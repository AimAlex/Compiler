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
class IRBuilder : public ASTVisitor{
public:
    std::shared_ptr<BasicBlock> curBlock;
    std::shared_ptr<BasicBlock> curLoopStepBlock;
    std::shared_ptr<BasicBlock> curLoopAfterBlock;
    std::shared_ptr<Function> curFunction;
    bool getAddress = false;
    bool isFunctionArgDecl = false;
    std::shared_ptr<IRRoot> irRoot;
    
    std::map<std::shared_ptr<IntValue>, std::shared_ptr<IntValue>> curFuncStaticMap;
    
    std::shared_ptr<IRRoot> getRoot() {
        return irRoot;
    }
    
    virtual void visit(std::shared_ptr<IfState> node)=0;
    virtual void visit(std::shared_ptr<ReturnState> node)=0;
    virtual void visit(std::shared_ptr<ForLoop> node)=0;
    virtual void visit(std::shared_ptr<VariableDecl> node)=0;
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
    virtual void visit(std::shared_ptr<Program> node)=0;
    virtual void visit(std::shared_ptr<ClassTypeNode> node)=0;
};

#endif /* IRBuilder_h */
