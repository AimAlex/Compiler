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
                rhs -> ifTrue -> append(std::shared_ptr<IRInstruction>(new Store(curBlock, std::shared_ptr<Register>(new IntImmediate(1)), size, addr, offset)));
                rhs -> ifFalse -> append(std::shared_ptr<IRInstruction>(new Store(curBlock, std::shared_ptr<Register>(new IntImmediate(0)), size, addr, offset)));
            }
            else {
                rhs -> ifTrue -> append(std::shared_ptr<IRInstruction>(new Move(curBlock, addr, std::shared_ptr<Register>(new IntImmediate(1)))));
                rhs -> ifFalse -> append(std::shared_ptr<IRInstruction>(new Move(curBlock, addr, std::shared_ptr<Register>(new IntImmediate(0)))));
            }
            rhs -> ifTrue -> end(std::shared_ptr<IRInstruction>(new Jump(curBlock, merge)));
            rhs -> ifFalse -> end(std::shared_ptr<IRInstruction>(new Jump(curBlock, merge)));
            curBlock = merge;
        } else {
            if (isMemOp) {
                curBlock -> append(std::shared_ptr<IRInstruction>(new Store(curBlock, rhs -> intValue, size, addr, offset)));
            } else {
                curBlock -> append(std::shared_ptr<IRInstruction>(new Move(curBlock, addr, rhs -> intValue)));
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
            } else if (!isFunctionArgDecl) {
                curBlock -> append(std::shared_ptr<IRInstruction>(new Move(curBlock, reg, std::shared_ptr<Register>(new IntImmediate(0)))));
            }
        }
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
    virtual void visit(std::shared_ptr<FunctionDecl> node)=0;
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
