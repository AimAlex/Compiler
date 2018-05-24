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
        irRoot = std::shared_ptr<IRRoot>(new IRRoot);
        for(int i = 0; i < (node -> decls).size(); ++i) {
            (node -> decls)[i] -> visited(shared_from_this());
        }
    }
    
    void visit(std::shared_ptr<VariableDecl> node){
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
        curFunction = std::shared_ptr<Function> (new Function(node -> functiontype));
        curFunction -> startBlock = std::shared_ptr<BasicBlock>(new BasicBlock(curFunction, node -> name + "_entry"));
        irRoot -> functions[node -> name] = curFunction;
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
        std::shared_ptr<Register> reg(new VirtualRegister(NULL));
        std::shared_ptr<IRInstruction>(new BinaryOperation(curBlock, reg, BinaryOperation::MUL, node -> subscript -> intValue, tmp)) -> append(curBlock);
        std::shared_ptr<IRInstruction>(new BinaryOperation(curBlock, reg, BinaryOperation::ADD, node -> array -> intValue, reg));
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
        std::shared_ptr<Register> reg(new VirtualRegister(NULL));
        switch (node -> op) {
            case UnaryExpr::INC:
//
                break;
            case UnaryExpr::DEC:
//
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
//
                break;
            case BinaryExpr::LOGICAL_OR:
            case BinaryExpr::LOGICAL_AND:
//
                break;
            case BinaryExpr::EQ:
            case BinaryExpr::NE:
            case BinaryExpr::LT:
            case BinaryExpr::GT:
            case BinaryExpr::LE:
            case BinaryExpr::GE:
                
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
//
                break;
            default:
                break;
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
    
    void visit(std::shared_ptr<NewExpr> node){
        std::shared_ptr<Register> reg(new VirtualRegister(NULL));
        if(node -> exprType -> type == SymbolType::ClASS){
            
        }
        else{
            bool getaddress = getAddress;
            getAddress = false;
            
        }
    }
    virtual void visit(std::shared_ptr<ArrayTypeNode> node)=0;
    virtual void visit(std::shared_ptr<PrimitiveTypeNode> node)=0;
    virtual void visit(std::shared_ptr<ClassDecl> node)=0;
    virtual void visit(std::shared_ptr<ClassConstructor> node)=0;
    virtual void visit(std::shared_ptr<EmptyExpr> node)=0;
    virtual void visit(std::shared_ptr<FunctionCall> node)=0;
    virtual void visit(std::shared_ptr<Identifier> node)=0;
    virtual void visit(std::shared_ptr<MemberAccess> node)=0;
    virtual void visit(std::shared_ptr<SelfDecrement> node)=0;
    virtual void visit(std::shared_ptr<SelfIncrement> node)=0;
    virtual void visit(std::shared_ptr<ClassTypeNode> node)=0;
};

#endif /* IRBuilder_h */
