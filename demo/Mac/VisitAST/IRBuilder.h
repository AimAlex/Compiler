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
            
        }
        curFunction = NULL;
    }
    virtual void visit(std::shared_ptr<IfState> node)=0;
    virtual void visit(std::shared_ptr<ReturnState> node)=0;
    virtual void visit(std::shared_ptr<ForLoop> node)=0;
    virtual void visit(std::shared_ptr<ArrayTypeNode> node)=0;
    virtual void visit(std::shared_ptr<PrimitiveTypeNode> node)=0;
    virtual void visit(std::shared_ptr<CompoundState> node)=0;
    virtual void visit(std::shared_ptr<ClassDecl> node)=0;
    virtual void visit(std::shared_ptr<ContinueState> node)=0;
    virtual void visit(std::shared_ptr<WhileLoop> node)=0;
    virtual void visit(std::shared_ptr<BreakState> node)=0;
    virtual void visit(std::shared_ptr<ClassConstructor> node)=0;
    virtual void visit(std::shared_ptr<ArrayAccess> node)=0;
    virtual void visit(std::shared_ptr<BinaryExpr> node)=0;
    virtual void visit(std::shared_ptr<BoolConst> node)=0;
    virtual void visit(std::shared_ptr<EmptyExpr> node)=0;
    virtual void visit(std::shared_ptr<FunctionCall> node)=0;
    virtual void visit(std::shared_ptr<Identifier> node)=0;
    virtual void visit(std::shared_ptr<IntConst> node)=0;
    virtual void visit(std::shared_ptr<MemberAccess> node)=0;
    virtual void visit(std::shared_ptr<NewExpr> node)=0;
    virtual void visit(std::shared_ptr<NullLiteral> node)=0;
    virtual void visit(std::shared_ptr<SelfDecrement> node)=0;
    virtual void visit(std::shared_ptr<SelfIncrement> node)=0;
    virtual void visit(std::shared_ptr<StringConst> node)=0;
    virtual void visit(std::shared_ptr<UnaryExpr> node)=0;
    virtual void visit(std::shared_ptr<ClassTypeNode> node)=0;
};

#endif /* IRBuilder_h */
