//
//  IRBuilder.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/11.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef IRBuilder_h
#define IRBuilder_h
#include "ASTVisitor.h"
#include "BasicBlock.h"
#include "Function.h"
#include "IRRoot.h"
#include "Register.h"
#include "StaticSpace.h"
#include "VirtualRegister.h"
#include "Store.h"
#include "IntImmediate.h"
#include "IRInstruction.h"
#include "Move.h"
#include "Jump.h"
#include "Return.h"
#include "BinaryOperation.h"
#include "Load.h"
#include "Branch.h"
#include "UnaryOperation.h"
#include "StaticString.h"
#include "HeapAllocate.h"
#include "IntComparison.h"
#include "Call.h"
#include "ClassRoot.h"
#include "StackSlot.h"
#include "PhysicalRegister.h"
#define INTSIZE 8
class IRBuilder : public ASTVisitor, public std::enable_shared_from_this<IRBuilder>{
public:
    std::shared_ptr<BasicBlock> curBlock;
    std::shared_ptr<BasicBlock> curLoopStepBlock;
    std::shared_ptr<BasicBlock> curLoopAfterBlock;
    std::shared_ptr<Function> curFunction;
    bool getAddress = false;
    bool isFunctionArgDecl = false;
    std::shared_ptr<IRRoot> irRoot;
    std::shared_ptr<SymbolTable> GlobalSymbolTable;
    std::shared_ptr<ClassRoot> currentClass = NULL;

    std::map<std::shared_ptr<Register>, std::shared_ptr<Register>> curFuncStaticMap;

    std::shared_ptr<IRRoot> getRoot() {
        return irRoot;
    }
    void assign(bool isMemOp, int size, std::shared_ptr<Register> addr, int offset, std::shared_ptr<ASTNode> rhs) {
        if (rhs -> ifTrue != NULL) {
            std::shared_ptr<BasicBlock> merge = std::shared_ptr<BasicBlock>(new BasicBlock(curFunction, ""));
            if (isMemOp) {
                std::shared_ptr<IRInstruction>(new Store(curBlock, std::shared_ptr<Register>(new IntImmediate(1)), size, addr, offset)) -> append(rhs -> ifTrue);
                std::shared_ptr<IRInstruction>(new Store(curBlock, std::shared_ptr<Register>(new IntImmediate(0)), size, addr, offset)) -> append(rhs -> ifFalse);
            }
            else {
                std::shared_ptr<IRInstruction>(new Move(curBlock, addr, std::shared_ptr<Register>(new IntImmediate(1)))) -> append(rhs -> ifTrue);
                std::shared_ptr<IRInstruction>(new Move(curBlock, addr, std::shared_ptr<Register>(new IntImmediate(0)))) -> append(rhs -> ifFalse);
            }
            std::shared_ptr<IRInstruction>(new Jump(curBlock, merge)) -> end(rhs -> ifTrue);
            std::shared_ptr<IRInstruction>(new Jump(curBlock, merge)) -> append(rhs -> ifFalse);
            curBlock = merge;
        } else {
            if (isMemOp) {
                std::shared_ptr<IRInstruction>(new Store(curBlock, rhs -> intValue, size, addr, offset)) -> append(curBlock);
            }
            else {
                std::shared_ptr<IRInstruction>(new Move(curBlock, addr, rhs -> intValue)) -> append(curBlock);
            }
        }
    }
    
    void visit(std::shared_ptr<Program> node){
        GlobalSymbolTable = node -> Table;
        irRoot = node -> irRoot;
        for(int i = 0; i < (node -> decls).size(); ++i) {
            (node -> decls)[i] -> visited(shared_from_this());
        }
    }

    void visit(std::shared_ptr<VariableDecl> node){
//        std::cout<<node -> name<<std::endl;
        std::shared_ptr<SymbolNode> info = node -> scope -> table -> symbolTable[node -> name];
        if(node -> scope -> table == GlobalSymbolTable){
            std::shared_ptr<Register> data(new StaticSpace(node -> name, info -> type -> getsize()));
            info -> reg = data;
            irRoot -> dataList.push_back(data);
        }
        else{
            std::shared_ptr<Register> reg(new VirtualRegister(node -> name));
            if (isFunctionArgDecl) {
                curFunction -> argVarRegList.push_back(reg);
            }
            info -> reg = reg;
            if (node -> init != NULL) {
                if (node -> init -> isLogicalExpression()) {
                    node -> init -> ifTrue = std::shared_ptr<BasicBlock>(new BasicBlock(curFunction, ""));
                    node -> init -> ifFalse = std::shared_ptr<BasicBlock>(new BasicBlock(curFunction, ""));
                }
                node -> init -> visited(shared_from_this());
                assign(false, node -> init -> exprType -> getsize(), reg, 0, node -> init);
            }
            else if (!isFunctionArgDecl) {
                std::shared_ptr<IRInstruction>(new Move(curBlock, reg, std::shared_ptr<Register>(new IntImmediate(0)))) -> append(curBlock);
            }
        }
    }

    void visit(std::shared_ptr<FunctionDecl> node){
        curFuncStaticMap.clear();
        if(currentClass != NULL){
            curFunction = currentClass -> functions[node -> name];
            std::shared_ptr<Register> reg(new VirtualRegister("this"));
            currentClass -> reg = reg;
            curFunction -> argVarRegList.push_back(reg);
        }
        else{
            curFunction = irRoot -> functions[node -> name];
        }
//        curFunction = std::shared_ptr<Function> (new Function(node -> functiontype));
        curFunction -> startBlock = std::shared_ptr<BasicBlock>(new BasicBlock(curFunction, node -> name + ".entry"));
//        irRoot -> functions[node -> name] = curFunction;
        curBlock = curFunction -> startBlock;
        isFunctionArgDecl = true;
        for(int i = 0; i < node -> parameterList.size(); ++i) {
            node -> parameterList[i] -> visited(shared_from_this());
        }
        isFunctionArgDecl = false;
        node -> body -> visited(shared_from_this());
        if(!curBlock -> ended){
            if(curFunction -> type -> returnType -> type == SymbolType::VOID){
                std::shared_ptr<Return> (new Return(curBlock, NULL)) -> end(curBlock);
            }
            else{
                std::shared_ptr<Return>(new Return(curBlock, std::shared_ptr<Register>(new IntImmediate(0)))) -> end(curBlock);
            }
        }
        if(curFunction -> retInstruction .size() > 1){
            std::shared_ptr<BasicBlock> exitBlock = std::shared_ptr<BasicBlock> (new BasicBlock(curFunction, curFunction -> name + "_exit"));
            std::shared_ptr<VirtualRegister> retReg;
            if(node -> functiontype -> returnType -> type == SymbolType::VOID){
                retReg = NULL;
            }
            else{
                retReg = std::shared_ptr<VirtualRegister>(new VirtualRegister("retValue"));
            }
            std::vector<std::shared_ptr<Return>> retInstructions(curFunction -> retInstruction);
//            std::cout<<retInstructions.size()<<std::endl;
            for(int i = 0; i < retInstructions.size(); ++i){
                std::shared_ptr<BasicBlock> Block = retInstructions[i] -> curBlock;
                if(retInstructions[i] -> ret != NULL){
                    retInstructions[i] -> prepend(std::shared_ptr<IRInstruction>(new Move(Block, retReg, retInstructions[i] -> ret)));
                }
                retInstructions[i] -> remove();
                std::shared_ptr<IRInstruction> (new Jump(Block, exitBlock)) -> end(Block);
            }
            if(curFunction -> retInstruction.size() != 0) std::cout<<"fuck"<<std::endl;
            std::shared_ptr<IRInstruction> (new Return(exitBlock, retReg)) -> end(exitBlock);
            curFunction -> exitBlock = exitBlock;
        }
        else{
            curFunction -> exitBlock = curFunction -> retInstruction[0] -> curBlock;
        }
        if(curFunction -> retInstruction.size() != 1) std::cout<<"fuck"<<std::endl;

        int resize = 0;
        std::vector<std::shared_ptr<BasicBlock>> vec(curFunction -> getReversePreOrder());
        for(int i = 0 ;i < curFunction -> exitBlock -> predecessor.size(); ++i) {
            std::vector<std::shared_ptr<BasicBlock>>::iterator iter = find(vec.begin(), vec.end(), curFunction -> exitBlock -> predecessor[i]);
            if(iter == vec.end()) continue;
            curFunction -> exitBlock -> predecessor[resize] = *iter;
            ++resize;
        }
        curFunction -> exitBlock -> predecessor.resize(resize + 1);
        curFunction = NULL;
    }

    void visit(std::shared_ptr<BreakState>){
        std::shared_ptr<IRInstruction>(new Jump(curBlock, curLoopAfterBlock)) -> end(curBlock);
    }

    void visit(std::shared_ptr<ContinueState>){
        std::shared_ptr<IRInstruction>(new Jump(curBlock, curLoopStepBlock)) -> end(curBlock);
    }

    void visit(std::shared_ptr<ReturnState> node){
        if(curFunction -> type -> returnType -> type == SymbolType::VOID){
            std::shared_ptr<IRInstruction>(new Return(curBlock, NULL)) -> end(curBlock);
        }
        else{
            if(node -> value -> isLogicalExpression()){
                node -> value -> ifTrue = std::shared_ptr<BasicBlock>(new BasicBlock(curFunction, NULL));
                node -> value -> ifFalse = std::shared_ptr<BasicBlock>(new BasicBlock(curFunction, NULL));
                node -> value -> visited(shared_from_this());

                std::shared_ptr<Register> reg (new VirtualRegister("retValue"));
                assign(false, INTSIZE, reg, 0, node -> value);

                std::shared_ptr<IRInstruction>(new Return(curBlock, reg)) -> end(curBlock);
            }
            else{
                node -> value -> visited(shared_from_this());
                std::shared_ptr<IRInstruction>(new Return(curBlock, node -> value -> intValue)) -> end(curBlock);
            }
        }
    }
    void visit(std::shared_ptr<CompoundState> node){
        for(int i = 0; i < node -> stmts.size(); ++i) {
            node -> stmts[i] -> visited(shared_from_this());
        }
    }
    void visit(std::shared_ptr<IfState> node){
        std::shared_ptr<BasicBlock> BlockTrue (new BasicBlock(curFunction, "if_true"));
        std::shared_ptr<BasicBlock> BlockFalse (new BasicBlock(curFunction, "if_false"));
        std::shared_ptr<BasicBlock> BlockMerge (new BasicBlock(curFunction, "if_merge"));
        node -> cond -> ifTrue = BlockTrue;
        if(node -> otherwise == NULL) {
            node -> cond -> ifFalse = BlockMerge;
            BlockFalse = NULL;
        }
        else{
            node -> cond -> ifFalse = BlockFalse;
        }
        node -> cond -> visited(shared_from_this());

        curBlock = BlockTrue;
        node -> then -> visited(shared_from_this());
        if(!curBlock -> ended){
            std::shared_ptr<IRInstruction> (new Jump(curBlock, BlockMerge)) -> end(curBlock);
        }

        if(node -> otherwise != NULL){
            curBlock = BlockFalse;
            node -> otherwise -> visited(shared_from_this());
            if(!curBlock -> ended){
                std::shared_ptr<IRInstruction> (new Jump(curBlock, BlockMerge)) -> end(curBlock);
            }
        }

        curBlock = BlockMerge;
    }
    void visit(std::shared_ptr<ForLoop> node){
        std::shared_ptr<BasicBlock> BlockCond (new BasicBlock(curFunction, "for_cond"));
        std::shared_ptr<BasicBlock> BlockLoop (new BasicBlock(curFunction, "for_loop"));
        std::shared_ptr<BasicBlock> BlockStep (new BasicBlock(curFunction, "for_step"));
        std::shared_ptr<BasicBlock> BlockAfter (new BasicBlock(curFunction, "for_after"));
        if(node -> cond == NULL){
            BlockCond = BlockLoop;
        }
        if(node -> step == NULL){
            BlockStep = BlockCond;
        }

        std::shared_ptr<BasicBlock> oldLoopCondBlock = curLoopStepBlock;
        std::shared_ptr<BasicBlock> oldLoopAfterBlock = curLoopAfterBlock;
        curLoopStepBlock = BlockStep;
        curLoopAfterBlock = BlockAfter;

        if(node -> init != NULL){
            node -> init -> visited(shared_from_this());
        }
        else if (node -> initWithDecl != NULL){
            node -> initWithDecl -> visited(shared_from_this());
        }

        std::shared_ptr<IRInstruction> (new Jump(curBlock, BlockCond)) -> end(curBlock);

        if(node -> cond != NULL){
            curBlock = BlockCond;
            node -> cond -> ifTrue = BlockLoop;
            node -> cond -> ifFalse = BlockAfter;
            node -> cond -> visited(shared_from_this());
        }

        curBlock = BlockLoop;
        node -> body -> visited(shared_from_this());
        std::shared_ptr<IRInstruction> (new Jump(curBlock, BlockStep)) -> end(curBlock);

        if(node -> step != NULL) {
            curBlock = BlockStep;
            node -> step -> visited(shared_from_this());
            std::shared_ptr<IRInstruction> (new Jump(curBlock, BlockCond)) -> end(curBlock);
        }

        curLoopStepBlock = oldLoopCondBlock;
        curLoopAfterBlock = oldLoopAfterBlock;
        curBlock = BlockAfter;
    }

    void visit(std::shared_ptr<WhileLoop> node){
        std::shared_ptr<BasicBlock> BlockCond (new BasicBlock(curFunction, "for_cond"));
        std::shared_ptr<BasicBlock> BlockLoop (new BasicBlock(curFunction, "for_loop"));
        std::shared_ptr<BasicBlock> BlockAfter (new BasicBlock(curFunction, "for_after"));

        std::shared_ptr<BasicBlock> oldLoopCondBlock = curLoopStepBlock;
        std::shared_ptr<BasicBlock> oldLoopAfterBlock = curLoopAfterBlock;
        curLoopStepBlock = BlockCond;
        curLoopAfterBlock = BlockAfter;

        std::shared_ptr<IRInstruction> (new Jump(curBlock, BlockCond)) -> end(curBlock);

        curBlock = BlockCond;
        node -> cond -> ifTrue = BlockLoop;
        node -> cond -> ifFalse = BlockAfter;
        node -> cond -> visited(shared_from_this());

        curBlock = BlockLoop;
        node -> body -> visited(shared_from_this());
        std::shared_ptr<IRInstruction> (new Jump(curBlock, BlockCond)) -> end(curBlock);

        curLoopStepBlock = oldLoopCondBlock;
        curLoopAfterBlock = oldLoopAfterBlock;
        curBlock = BlockAfter;
    }
    void visit(std::shared_ptr<ArrayAccess> node){
        bool getAddr = getAddress;
        getAddress = false;
        node -> array -> visited(shared_from_this());
        node -> subscript -> visited(shared_from_this());
        getAddress = getAddr;

        std::shared_ptr<Register> tmp(new IntImmediate(node -> array -> exprType -> getsize()));
        std::shared_ptr<Register> reg(new VirtualRegister(""));
        std::shared_ptr<IRInstruction>(new BinaryOperation(curBlock, reg, BinaryOperation::MUL, node -> subscript -> intValue, tmp)) -> append(curBlock);
        std::shared_ptr<IRInstruction>(new BinaryOperation(curBlock, reg, BinaryOperation::ADD, node -> array -> intValue, reg)) -> append(curBlock);
        if(getAddress) {
            node -> addressValue = reg;
            node -> addressOffset = INTSIZE;
        }
        else{
            std::shared_ptr<IRInstruction> (new Load(curBlock, reg, node -> exprType -> getsize(), reg, INTSIZE)) -> append(curBlock);
            node -> intValue = reg;
            if(node -> ifTrue != NULL){
                std::shared_ptr<IRInstruction>(new Branch(curBlock, node -> intValue, node -> ifTrue, node -> ifFalse)) -> end(curBlock);
            }
        }
    }

    void visit(std::shared_ptr<UnaryExpr> node){
        if(node -> op == UnaryExpr::LOGICAL_NOT){
            node -> body -> ifTrue = node -> ifFalse;
            node -> body -> ifFalse = node -> ifTrue;
            node -> body -> visited(shared_from_this());
            return;
        }

        node -> body -> visited(shared_from_this());
        std::shared_ptr<Register> reg(new VirtualRegister(""));
        switch (node -> op) {
            case UnaryExpr::INC:
                selfIncDec(node -> body, node, true, false);
                break;
            case UnaryExpr::DEC:
                selfIncDec(node -> body, node, false, false);
                break;
            case UnaryExpr::POS:
                node -> intValue = node -> body -> intValue;
                break;
            case UnaryExpr::NEG:
                node -> intValue = reg;
                std::shared_ptr<IRInstruction>(new UnaryOperation(curBlock, reg, UnaryOperation::NEG, node -> body -> intValue)) -> append(curBlock);
                break;
            case UnaryExpr::BITWISE_NOT:
                node -> intValue = reg;
                std::shared_ptr<IRInstruction>(new UnaryOperation(curBlock, reg, UnaryOperation::NOT, node -> body -> intValue)) -> append(curBlock);
            default:
                break;
        }
    }

    void visit(std::shared_ptr<BinaryExpr> node){
        switch (node -> op) {
            case BinaryExpr::ASSIGN:
                binaryAssign(node);
                break;
            case BinaryExpr::LOGICAL_OR:
            case BinaryExpr::LOGICAL_AND:
                logicalBinaryExpr(node);
                break;
            case BinaryExpr::EQ:
            case BinaryExpr::NE:
            case BinaryExpr::LT:
            case BinaryExpr::GT:
            case BinaryExpr::LE:
            case BinaryExpr::GE:
                if(node -> lhs -> exprType -> type == SymbolType::STRING){
                    stringBinaryExpr(node);
                }
                else{
                    intRelationExpr(node);
                }
                break;
            case BinaryExpr::SHL:
            case BinaryExpr::SHR:
            case BinaryExpr::ADD:
            case BinaryExpr::SUB:
            case BinaryExpr::MUL:
            case BinaryExpr::DIV:
            case BinaryExpr::MOD:
            case BinaryExpr::XOR:
            case BinaryExpr::BITWISE_OR:
            case BinaryExpr::BITWISE_AND:
                if (node -> lhs -> exprType -> type == SymbolType::STRING){
                    stringBinaryExpr(node);
                }
                else {
                    intArithmeticExpr(node);
                }
                break;
            default:
                break;
        }
    }

    void stringBinaryExpr(std::shared_ptr<BinaryExpr> node){
        node -> lhs -> visited(shared_from_this());
        node -> rhs -> visited(shared_from_this());
        std::shared_ptr<Register> reg(new VirtualRegister(""));
        node -> intValue = reg;
        std::shared_ptr<Call> call;
        std::shared_ptr<ASTNode> tmp;
        switch (node -> op) {
            case BinaryExpr::ADD:
                call = std::shared_ptr<Call>(new Call(curBlock, reg, irRoot -> builtinStringConcat));
                break;
            case BinaryExpr::EQ:
                call = std::shared_ptr<Call>(new Call(curBlock, reg, irRoot -> builtinStringEqual));
                break;
            case BinaryExpr::LT:
                call = std::shared_ptr<Call>(new Call(curBlock, reg, irRoot -> builtinStringLess));
                break;
            case BinaryExpr::GT:
                tmp = node -> lhs;
                node -> lhs = node -> rhs;
                node -> rhs = tmp;
                call = std::shared_ptr<Call>(new Call(curBlock, reg, irRoot -> builtinStringLess));
                break;
            default:
                break;
        }
        call -> args.push_back(node -> lhs -> intValue);
        call -> args.push_back(node -> rhs -> intValue);
        call -> append(curBlock);
        
        if(node -> ifTrue != NULL){
            std::shared_ptr<IRInstruction> (new Branch(curBlock, reg, node -> ifTrue, node -> ifFalse)) -> end(curBlock);
        }
        else{
            node -> intValue = reg;
        }
    }
    
    void visit(std::shared_ptr<BoolConst> node){
        node -> intValue = std::shared_ptr<Register>(new IntImmediate((int)node -> value));
    }

    void visit(std::shared_ptr<IntConst> node){
        node -> intValue = std::shared_ptr<Register>(new IntImmediate(node -> value));
    }

    void visit(std::shared_ptr<NullLiteral> node){
        node -> intValue = std::shared_ptr<Register>(new IntImmediate(0));
    }

    void visit(std::shared_ptr<StringConst> node){
        std::map<std::string, std::shared_ptr<Register>>::iterator iter = irRoot -> strings.find(node -> value);
        if(iter == irRoot -> strings.end()){
            std::shared_ptr<Register> ss(new StaticString(node -> value));
            irRoot -> strings[node -> value] = ss;
            node -> intValue = ss;
        }
        else{
            node -> intValue = iter -> second;
        }
    }

    void selfIncDec(std::shared_ptr<ASTNode> body, std::shared_ptr<ASTNode> node, bool isInc, bool isPostfix){
        bool isMemOp = body -> needMemoryAccess();
        bool getaddr = getAddress;
        getAddress = isMemOp;
        body -> visited(shared_from_this());
        std::shared_ptr<Register> addr = body -> addressValue;
        int offset = body -> addressOffset;

        getAddress = false;
        body -> visited(shared_from_this());
        getAddress = getaddr;

        BinaryOperation::BinaryOp op;
        if(isInc){
            op = BinaryOperation::ADD;
        }
        else{
            op = BinaryOperation::SUB;
        }

        std::shared_ptr<Register> one(new IntImmediate(1));
        std::shared_ptr<Register> reg(new VirtualRegister(""));

        if(isPostfix){
            std::shared_ptr<IRInstruction> (new Move(curBlock, reg, body -> intValue)) -> append(curBlock);
            node -> intValue = reg;
        }
        else{
            node -> intValue = body -> intValue;
        }

        if(isMemOp){
            std::shared_ptr<IRInstruction>(new BinaryOperation(curBlock, reg, op, body -> intValue, one)) -> append(curBlock);
            std::shared_ptr<IRInstruction>(new Store(curBlock, reg, body -> exprType -> getsize(), addr, offset)) -> append(curBlock);
            if(!isPostfix){
                node -> intValue = reg;
            }
        }
        else{
            std::shared_ptr<IRInstruction> (new BinaryOperation(curBlock, body -> intValue, op, body -> intValue, one)) -> append(curBlock);
        }
    }

    void visit(std::shared_ptr<SelfDecrement> node){
        selfIncDec(node -> oneself, node, false, true);
    }

    void visit(std::shared_ptr<SelfIncrement> node){
        selfIncDec(node -> oneself, node, true, true);
    }

    void binaryAssign(std::shared_ptr<BinaryExpr> node) {
        if(node -> rhs -> isLogicalExpression()){
            node -> rhs -> ifTrue = std::shared_ptr<BasicBlock>(new BasicBlock(curFunction, ""));
            node -> rhs -> ifFalse = std::shared_ptr<BasicBlock>(new BasicBlock(curFunction, ""));
        }
        node -> rhs -> visited(shared_from_this());

        bool isMemOp = node -> lhs -> needMemoryAccess();
        getAddress = isMemOp;
        node -> lhs -> visited(shared_from_this());
        getAddress = false;

        std::shared_ptr<Register> addr;
        int offset;
        if(isMemOp){
            addr = node -> lhs -> addressValue;
            offset = node -> lhs -> addressOffset;
//            std::cout<<node -> lhs -> addressOffset<<std::endl;
        }
        else{
            addr = node -> lhs -> intValue;
            offset = 0;
        }
        assign(isMemOp, node -> rhs -> exprType -> getsize(), addr, offset, node -> rhs);
        node -> intValue = node -> rhs -> intValue;
    }

    void logicalBinaryExpr(std::shared_ptr<BinaryExpr> node){
        if(node -> op == BinaryExpr::LOGICAL_AND) {
            node -> lhs -> ifTrue = std::shared_ptr<BasicBlock> (new BasicBlock(curFunction, "lhs_true"));
            node -> lhs -> ifFalse = node -> ifFalse;
            node -> lhs -> visited(shared_from_this());
            curBlock = node -> lhs -> ifTrue;
        }
        else{
            node -> lhs -> ifTrue = node -> ifTrue;
            node -> lhs -> ifFalse = std::shared_ptr<BasicBlock> (new BasicBlock(curFunction, "lhs_false"));
            node -> lhs -> visited(shared_from_this());
            curBlock = node -> lhs -> ifFalse;
        }

        node -> rhs -> ifTrue = node -> ifTrue;
        node -> rhs -> ifFalse = node -> ifFalse;
        node -> rhs -> visited(shared_from_this());
    }

    void intRelationExpr(std::shared_ptr<BinaryExpr> node){
        node -> lhs -> visited(shared_from_this());
        node -> rhs -> visited(shared_from_this());

        IntComparison::Comparison Op;
        switch (node -> op) {
            case BinaryExpr::EQ:
                Op = IntComparison::EQ;
                break;
            case BinaryExpr::NE:
                Op = IntComparison::NE;
                break;
            case BinaryExpr::LT:
                Op = IntComparison::LT;
                break;
            case BinaryExpr::GT:
                Op = IntComparison::GT;
                break;
            case BinaryExpr::LE:
                Op = IntComparison::LE;
                break;
            case BinaryExpr::GE:
                Op = IntComparison::GE;
                break;
        }

        std::shared_ptr<Register> reg(new VirtualRegister(""));
        std::shared_ptr<IRInstruction>(new IntComparison(curBlock, reg, Op, node -> lhs -> intValue, node -> rhs -> intValue)) -> append(curBlock);
        if(node -> ifTrue != NULL) {
            std::shared_ptr<IRInstruction>(new Branch(curBlock, reg, node -> ifTrue, node -> ifFalse)) -> end(curBlock);
        }
        else{
            node -> intValue = reg;
        }
    }

    void intArithmeticExpr(std::shared_ptr<BinaryExpr> node){
        node -> lhs -> visited(shared_from_this());
        node -> rhs -> visited(shared_from_this());

        BinaryOperation::BinaryOp Op;
        switch (node -> op) {
            case BinaryExpr::SHL:
                Op = BinaryOperation::SHL;
                break;
            case BinaryExpr::SHR:
                Op = BinaryOperation::SHR;
                break;
            case BinaryExpr::ADD:
                Op = BinaryOperation::ADD;
                break;
            case BinaryExpr::SUB:
                Op = BinaryOperation::SUB;
                break;
            case BinaryExpr::MUL:
                Op = BinaryOperation::MUL;
                break;
            case BinaryExpr::DIV:
                Op = BinaryOperation::DIV;
                break;
            case BinaryExpr::MOD:
                Op = BinaryOperation::MOD;
                break;
            case BinaryExpr::XOR:
                Op = BinaryOperation::XOR;
                break;
            case BinaryExpr::BITWISE_AND:
                Op = BinaryOperation::AND;
                break;
            case BinaryExpr::BITWISE_OR:
                Op = BinaryOperation::OR;
                break;
        }

        std::shared_ptr<Register>reg (new VirtualRegister (""));
        node -> intValue = reg;
        std::shared_ptr<IRInstruction>(new BinaryOperation(curBlock, reg, Op, node -> lhs -> intValue, node -> rhs -> intValue)) -> append(curBlock);
    }

    void visit(std::shared_ptr<Identifier> node){
        std::shared_ptr<SymbolNode> info = node -> info;
        if(node -> info -> table -> memorysize > 0){
            if(getAddress){
                node -> addressValue = currentClass -> reg;
                node -> addressOffset = info -> offset;
//                std::cout<<node -> name<<" "<<info -> table -> symbolTable["b"] -> offset<<std::endl;
            }
            else{
                std::shared_ptr<Register> reg(new VirtualRegister(""));
                node -> intValue = reg;
                std::shared_ptr<IRInstruction>(new Load(curBlock, reg, info -> type -> getsize(), currentClass -> reg, info -> offset)) -> append(curBlock);
            }
        }
        else{
            node -> intValue = info -> reg;
        }
        if(node -> ifTrue != NULL){
            std::shared_ptr<IRInstruction> (new Branch(curBlock, node -> intValue, node -> ifTrue, node -> ifFalse)) -> end(curBlock);
        }
    }
    
    void visit(std::shared_ptr<FunctionCall> node){
        std::shared_ptr<SymbolType> type = node -> name -> exprType;
        std::shared_ptr<Function> func;
        if(buildinFunctionCall(node, type)) {
            if(node -> ifTrue != NULL){
                std::shared_ptr<IRInstruction>(new Branch(curBlock, node -> intValue, node -> ifTrue, node -> ifFalse)) -> end(curBlock);
            }
            return;
        }
        if(node -> name -> gettype() == "MemberAccess"){
            node -> name -> visited(shared_from_this());
            std::shared_ptr<MemberAccess> memberAccess = std::dynamic_pointer_cast<MemberAccess>(node -> name);
            std::shared_ptr<SymbolType> recordType = memberAccess -> record -> exprType;
            func = irRoot -> classList[recordType -> getName()] -> functions[memberAccess -> member];
        }
        else if(currentClass != NULL && currentClass -> functions.find(type -> getName()) != currentClass -> functions.end()){
            func = currentClass -> functions[type -> getName()];
        }
        else{
            func = irRoot -> functions[type -> getName()];
        }
        for(int i = 0; i < node -> parameters.size(); ++i) {
            node -> parameters[i] -> visited(shared_from_this());
        }
        std::shared_ptr<Register> reg(new VirtualRegister(""));
        std::shared_ptr<Call> call(new Call(curBlock, reg, func));

        if(node -> name -> gettype() == "MemberAccess"){
            call -> args.push_back(node -> name -> intValue);
        }
        else if(currentClass != NULL && currentClass -> functions.find(type -> getName()) != currentClass -> functions.end()){
            call -> args.push_back(currentClass -> reg);
        }
        for(int i = 0; i < node -> parameters.size(); ++i) {
            call -> args.push_back(node -> parameters[i] -> intValue);
        }
        call -> append(curBlock);
        node -> intValue = reg;
        
        if(node -> ifTrue != NULL){
            std::shared_ptr<IRInstruction>(new Branch(curBlock, node -> intValue, node -> ifTrue, node -> ifFalse)) -> end(curBlock);
        }
    }
    
    bool buildinFunctionCall(std::shared_ptr<FunctionCall> node, std::shared_ptr<SymbolType> type){
        bool bakGetAddress = getAddress;
        getAddress = false;
        if(node -> name -> gettype() == "MemberAccess"){
            node -> name -> visited(shared_from_this());
            std::shared_ptr<MemberAccess> memberAccess = std::dynamic_pointer_cast<MemberAccess>(node -> name);
            if(memberAccess -> record -> exprType -> type == SymbolType::STRING){
                if(memberAccess -> member == "length"){
                    std::cout<<"length"<<std::endl;
//                    new Call(curBlock, reg, func)
                }
                else if(memberAccess -> member == "substring"){
//                    std::cout<<"substring"<<std::endl;
                    node -> parameters[0] -> visited(shared_from_this());
                    node -> parameters[1] -> visited(shared_from_this());
                    std::shared_ptr<Register> reg(new VirtualRegister("substr"));
                    std::shared_ptr<Call> call(new Call(curBlock, reg, irRoot -> builtinStringSubString));
                    call -> args.push_back(memberAccess -> intValue);
                    call -> args.push_back(node -> parameters[0] -> intValue);
                    call -> args.push_back(node -> parameters[1] -> intValue);
                    call -> append(curBlock);
                    node -> intValue = reg;
                }
                else if(memberAccess -> member == "parseInt"){
//                    std::cout<<"parseInt"<<std::endl;
                    std::shared_ptr<Register> reg(new VirtualRegister("parsedInt"));
                    std::shared_ptr<Call> call(new Call(curBlock, reg, irRoot -> builtinStringParseInt));
                    call -> args.push_back(memberAccess -> intValue);
                    call -> append(curBlock);
                    node -> intValue = reg;
                }
                else if(memberAccess -> member == "ord"){
//                    std::cout<<"ord"<<std::endl;
                    node -> parameters[0] -> visited(shared_from_this());
                    std::shared_ptr<Register> reg(new VirtualRegister("ord"));
                    std::shared_ptr<IRInstruction> (new BinaryOperation(curBlock, reg, BinaryOperation::ADD, memberAccess -> intValue, node -> parameters[0] -> intValue)) -> append(curBlock);
                    std::shared_ptr<IRInstruction>(new Load(curBlock, reg, 1, reg, 4)) -> append(curBlock);
                    node -> intValue = reg;
                }
                else{
                    getAddress = bakGetAddress;
                    return false;
                }
            }
            else if(memberAccess -> record -> exprType -> getDemension() != 0){
                if(memberAccess -> member == "size"){
                    std::shared_ptr<Register> reg(new VirtualRegister("size"));
                    std::shared_ptr<IRInstruction>(new Load(curBlock, reg, INTSIZE, memberAccess -> intValue, 0)) -> append(curBlock);
                    node -> intValue = reg;
                }
                else{
                    getAddress = bakGetAddress;
                    return false;
                }
            }
            else{
                getAddress = bakGetAddress;
                return false;
            }
        }
        else{
            if(type -> getName() == "print"){
                processPrint(node -> parameters[0], 0);
            }
            else if(type -> getName() == "println"){
                processPrint(node -> parameters[0], 1);
            }
            else if(type -> getName() == "getString"){
                std::shared_ptr<Register> reg(new VirtualRegister("gottemString"));
                std::shared_ptr<Call> call(new Call(curBlock, reg, irRoot -> builtinGetString));
                call -> append(curBlock);
                node -> intValue = reg;
            }
            else if(type -> getName() == "getInt"){
                std::shared_ptr<Register> reg(new VirtualRegister("gottemInt"));
                std::shared_ptr<Call> call(new Call(curBlock, reg, irRoot -> builtinGetInt));
                call -> append(curBlock);
                node -> intValue = reg;
            }
            else if(type -> getName() == "toString"){
                node -> parameters[0] -> visited(shared_from_this());
                std::shared_ptr<Register> reg(new VirtualRegister("tostring"));
                std::shared_ptr<Call> call(new Call(curBlock, reg, irRoot -> builtinToString));
                call -> args.push_back(node -> parameters[0] -> intValue);
                call -> append(curBlock);
                node -> intValue = reg;
            }
            else{
                return false;
            }
        }
        getAddress = bakGetAddress;
        return true;
    }
    
    void processPrint(std::shared_ptr<ASTNode> node, bool ln){
        if(node -> gettype() == "BinaryExpr"){
            std::shared_ptr<BinaryExpr> expr = std::dynamic_pointer_cast<BinaryExpr>(node);
            processPrint(expr -> lhs, false);
            processPrint(expr -> rhs, ln);
        }
        else if(node -> gettype() == "FunctionCall" && std::dynamic_pointer_cast<FunctionCall>(node) -> name -> exprType -> getName() == "toString"){
            std::shared_ptr<ASTNode> expr = std::dynamic_pointer_cast<FunctionCall>(node) -> parameters[0];
            expr -> visited(shared_from_this());
            std::shared_ptr<Call> call;
            if(ln){
                call = std::shared_ptr<Call>(new Call(curBlock, NULL, irRoot -> builtinPrintlnInt));
            }
            else{
                call = std::shared_ptr<Call>(new Call(curBlock, NULL, irRoot -> builtinPrintInt));
            }
            call -> args.push_back(expr -> intValue);
            call -> append(curBlock);
        }
        else{
            node -> visited(shared_from_this());
            std::shared_ptr<Call> call (new Call(curBlock, NULL, irRoot -> builtinPrintlnInt));
            call -> args.push_back(node -> intValue);
            call -> append(curBlock);
        }
            
            //        else if(node -> gettype() == "FunctionCall" && std::dynamic_pointer_cast<FunctionCall>(node) -> name -> exprType -> type == SymbolType::FUNCTION && std::dynamic_pointer_cast<FunctionCall>(node) -> name -> gettype() == "MemberAccess" && std::dynamic_pointer_cast<MemberAccess>(std::dynamic_pointer_cast<FunctionCall>(node) -> name) -> exprType -> type == SymbolType::STRING)
    }
    
    void visit(std::shared_ptr<ClassDecl> node){
        std::shared_ptr<SymbolNode> classTable = GlobalSymbolTable -> symbolTable[node -> name];
        std::shared_ptr<ClassRoot> curClass = irRoot -> classList[node -> name];
        currentClass = curClass;
        curClass -> size = classTable -> table -> memorysize;
        if(node -> classconstructor != NULL){
            node -> classconstructor -> visited(shared_from_this());
        }
        for(int i = 0; i < node -> functionMembers.size(); ++i) {
            node -> functionMembers[i] -> visited(shared_from_this());
        }
        currentClass = NULL;
    }
    
    void visit(std::shared_ptr<ClassConstructor> node){
        curFuncStaticMap.clear();
        curFunction = currentClass -> constructor;
        //        curFunction = std::shared_ptr<Function> (new Function(node -> functiontype));
        curFunction -> startBlock = std::shared_ptr<BasicBlock>(new BasicBlock(curFunction, node -> name + ".entry"));
        //        irRoot -> functions[node -> name] = curFunction;
        curBlock = curFunction -> startBlock;
        isFunctionArgDecl = true;
        std::shared_ptr<Register> reg(new VirtualRegister("this"));
        currentClass -> reg = reg;
        curFunction -> argVarRegList.push_back(reg);
        isFunctionArgDecl = false;
        node -> body -> visited(shared_from_this());
        if(!curBlock -> ended){
            std::shared_ptr<Return> (new Return(curBlock, NULL)) -> end(curBlock);
        }
        
        curFunction -> exitBlock = curFunction -> retInstruction[0] -> curBlock;
//        if(curFunction -> retInstruction.size() != 1) std::cout<<"fuck"<<std::endl;
        
        int resize = 0;
        std::vector<std::shared_ptr<BasicBlock>> vec(curFunction -> getReversePreOrder());
        for(int i = 0 ;i < curFunction -> exitBlock -> predecessor.size(); ++i) {
            std::vector<std::shared_ptr<BasicBlock>>::iterator iter = find(vec.begin(), vec.end(), curFunction -> exitBlock -> predecessor[i]);
            if(iter == vec.end()) continue;
            curFunction -> exitBlock -> predecessor[resize] = *iter;
            ++resize;
        }
        curFunction -> exitBlock -> predecessor.resize(resize + 1);
        curFunction = NULL;
    }
    
    void visit(std::shared_ptr<MemberAccess> node){
        bool getaddr = getAddress;
        getAddress = false;
        node -> record -> visited(shared_from_this());
        getAddress = getaddr;
        
        if(node -> record -> exprType -> type == SymbolType::STRING){
            node -> intValue = node -> record -> intValue;
            if(node -> ifTrue != NULL){
                std::shared_ptr<IRInstruction>(new Branch(curBlock, node -> intValue, node -> ifTrue, node -> ifFalse)) -> end(curBlock);
            }
            return ;
        }
        else if(node -> record -> exprType -> getDemension() != 0){
            node -> intValue = node -> record -> intValue;
            if(node -> ifTrue != NULL){
                std::shared_ptr<IRInstruction>(new Branch(curBlock, node -> intValue, node -> ifTrue, node -> ifFalse)) -> end(curBlock);
            }
            return ;
        }
        std::shared_ptr<Register> addr = node -> record -> intValue;
        std::shared_ptr<ClassType> t = std::dynamic_pointer_cast<ClassType>(node -> record -> exprType);
        std::shared_ptr<SymbolNode> info = GlobalSymbolTable -> symbolTable[node -> record -> exprType -> getName()] -> table -> symbolTable[node -> member];
//        std::cout<<node -> member<<std::endl;
//        std::cout<<info -> type -> getName()<<std::endl;
        if(info -> type -> type == SymbolType::FUNCTION){
            node -> intValue = node -> record -> intValue;
            if(node -> ifTrue != NULL){
                std::shared_ptr<IRInstruction>(new Branch(curBlock, node -> intValue, node -> ifTrue, node -> ifFalse)) -> end(curBlock);
            }
        }
        else if(getAddress){
            node -> addressValue = addr;
            node -> addressOffset = info -> offset;
//            std::cout<<info -> offset<<std::endl;;
        }
        else{
            std::shared_ptr<VirtualRegister> reg (new VirtualRegister(""));
            node -> intValue = reg;
            std::shared_ptr<IRInstruction> (new Load(curBlock, reg, info -> type -> getsize(), addr, info -> offset)) -> append(curBlock);
            if(node -> ifTrue != NULL){
                std::shared_ptr<IRInstruction>(new Branch(curBlock, node -> intValue, node -> ifTrue, node -> ifFalse)) -> end(curBlock);
            }
        }
    }
    
    void visit(std::shared_ptr<NewExpr> node){
        std::shared_ptr<Register> reg(new VirtualRegister(""));
        if(node -> exprType -> type == SymbolType::ClASS && node -> exprType -> getDemension() == 0){
            std::shared_ptr<IRInstruction> (new HeapAllocate(curBlock, reg, std::shared_ptr<Register> (new IntImmediate(GlobalSymbolTable -> symbolTable[node -> exprType -> getName()] -> table -> memorysize)))) -> append(curBlock);
            std::shared_ptr<ClassRoot> newClass = irRoot->classList[node -> exprType -> getName()];
            if(newClass -> constructor != NULL){
                std::shared_ptr<Call> call(new Call(curBlock, std::shared_ptr<Register>( new VirtualRegister("")), newClass -> constructor));
                call -> args.push_back(reg);
                call -> append(curBlock);
            }
            node -> intValue = reg;
        }
        else{
            newArray(0, reg, node);
            node -> intValue = reg;
        }
    }
    
    void newArray(int order, std::shared_ptr<Register> reg, std::shared_ptr<NewExpr> node){
        if(order == node -> exprType -> getDemension()) return;
        if(node -> dim[order] == NULL) return;
        node -> dim[order] -> visited(shared_from_this());
        
        
        std::shared_ptr<Register> dim = node -> dim[order] -> intValue;
        if(order == 0){
            std::shared_ptr<BinaryOperation> (new BinaryOperation(curBlock, reg, BinaryOperation::MUL, dim, std::shared_ptr<Register> (new IntImmediate(INTSIZE)))) -> append(curBlock);
            std::shared_ptr<BinaryOperation>(new BinaryOperation(curBlock, reg, BinaryOperation::ADD, reg, std::shared_ptr<Register> (new IntImmediate(INTSIZE)))) -> append(curBlock);
            std::shared_ptr<IRInstruction>(new HeapAllocate(curBlock, reg, reg)) -> append(curBlock);
            std::shared_ptr<IRInstruction>(new Store(curBlock, dim, INTSIZE, reg, 0)) -> append(curBlock);
            newArray(order + 1, reg, node);
        }
        else{
            std::shared_ptr<Register> prevDim = node -> dim[order - 1] -> intValue;
            std::shared_ptr<BasicBlock> BlockCond (new BasicBlock(curFunction, "for_cond"));
            std::shared_ptr<BasicBlock> BlockLoop (new BasicBlock(curFunction, "for_loop"));
            std::shared_ptr<BasicBlock> BlockStep (new BasicBlock(curFunction, "for_step"));
            std::shared_ptr<BasicBlock> BlockAfter (new BasicBlock(curFunction, "for_after"));
            
            std::shared_ptr<BasicBlock> oldLoopCondBlock = curLoopStepBlock;
            std::shared_ptr<BasicBlock> oldLoopAfterBlock = curLoopAfterBlock;
            curLoopStepBlock = BlockStep;
            curLoopAfterBlock = BlockAfter;
            
            std::shared_ptr<VirtualRegister> init_reg(new VirtualRegister("init_i"));
            std::shared_ptr<IRInstruction> (new Move(curBlock, init_reg, std::shared_ptr<Register>(new IntImmediate(0)))) -> append(curBlock);
            std::shared_ptr<IRInstruction>(new Jump(curBlock, BlockCond)) -> end(curBlock);
            
            curBlock = BlockCond;
            std::shared_ptr<Register> cmp(new VirtualRegister(""));
            std::shared_ptr<IRInstruction>(new IntComparison(curBlock, cmp, IntComparison::LT, init_reg, prevDim)) -> append(curBlock);
            std::shared_ptr<IRInstruction>(new Branch(curBlock, cmp, BlockLoop, BlockAfter)) -> end(curBlock);
            
            curBlock = BlockLoop;
            std::shared_ptr<Register> parReg(new VirtualRegister(""));
            std::shared_ptr<Register> addrReg(new VirtualRegister(""));
            std::shared_ptr<IRInstruction> (new BinaryOperation(curBlock, parReg, BinaryOperation::MUL, init_reg, std::shared_ptr<Register>(new IntImmediate(INTSIZE)))) -> append(curBlock);
            std::shared_ptr<IRInstruction> (new BinaryOperation(curBlock, parReg, BinaryOperation::ADD, reg, parReg)) -> append(curBlock);
            std::shared_ptr<IRInstruction> (new BinaryOperation(curBlock, addrReg, BinaryOperation::MUL, dim, std::shared_ptr<Register>(new IntImmediate(INTSIZE)))) -> append(curBlock);
            std::shared_ptr<IRInstruction> (new BinaryOperation(curBlock, addrReg, BinaryOperation::ADD, addrReg, std::shared_ptr<Register>(new IntImmediate(INTSIZE)))) -> append(curBlock);
            std::shared_ptr<IRInstruction> (new HeapAllocate(curBlock, addrReg, addrReg)) -> append(curBlock);
            std::shared_ptr<IRInstruction>(new Store(curBlock, dim, INTSIZE, addrReg, 0)) -> append(curBlock);
            std::shared_ptr<IRInstruction>(new Store(curBlock, addrReg, INTSIZE, parReg, INTSIZE)) -> append(curBlock);
            newArray(order + 1, addrReg, node);
            std::shared_ptr<IRInstruction> (new Jump(curBlock, BlockStep)) -> end(curBlock);
            
            curBlock = BlockStep;
            std::shared_ptr<IRInstruction> (new BinaryOperation(curBlock, init_reg, BinaryOperation::ADD, init_reg, std::shared_ptr<Register>(new IntImmediate(1)))) -> append(curBlock);
            std::shared_ptr<IRInstruction> (new Jump(curBlock, BlockCond)) -> end(curBlock);
            
            curLoopStepBlock = oldLoopCondBlock;
            curLoopAfterBlock = oldLoopAfterBlock;
            curBlock = BlockAfter;
        }
    }
    
    void visit(std::shared_ptr<ClassTypeNode>){};
    void visit(std::shared_ptr<EmptyExpr>){};
    void visit(std::shared_ptr<ArrayTypeNode>){};
    void visit(std::shared_ptr<PrimitiveTypeNode>){};
};

#endif /* IRBuilder_h */
