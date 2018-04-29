//
//  ASTSymbol.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/4/27.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef ASTClass_h
#define ASTClass_h
#include "ASTVisitor.h"
#include "SymbolTable.h"
#include <vector>
#include "ClassType.h"
#include "FunctionType.h"
class ASTClass : public ASTVisitor, public std::enable_shared_from_this<ASTClass>{
public:
    std::shared_ptr<SymbolTable> ClassList;
    virtual void visit(std::shared_ptr<IfState> node)=0;
    virtual void visit(std::shared_ptr<ReturnState> node)=0;
    virtual void visit(std::shared_ptr<ForLoop> node)=0;
    virtual void visit(std::shared_ptr<VariableDecl> node)=0;
    virtual void visit(std::shared_ptr<ArrayTypeNode> node)=0;
    virtual void visit(std::shared_ptr<PrimitiveTypeNode> node)=0;
    virtual void visit(std::shared_ptr<CompoundState> node)=0;
    void visit(std::shared_ptr<ClassDecl> node){
        if(node == NULL) return;
        std::shared_ptr<SymbolNode> classNode(new ClassType(node -> name));
        tableList[tableList.size() - 1] -> add(node -> name, classNode);
        std::shared_ptr<SymbolTable> ptr(new SymbolTable());
    }
    virtual void visit(std::shared_ptr<ContinueState> node)=0;
    virtual void visit(std::shared_ptr<WhileLoop> node)=0;
    virtual void visit(std::shared_ptr<BreakState> node)=0;
    void visit(std::shared_ptr<FunctionDecl> node){
        if(node == NULL) return;
        std::shared_ptr<SymbolNode> functionNode(new FunctionType());
        (node -> returnType) -> visited(shared_from_this());
        //        std::cout<<node->parameterList.size()<<std::endl;
        for(int i = 0; i <  (node->parameterList).size(); ++i){
            (node -> parameterList)[i] -> visited(shared_from_this());
        }
    }
    void visit(std::shared_ptr<ClassConstructor> node){
        if(node == NULL) return;
        if(node -> name == )
    }
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
    void visit(std::shared_ptr<SelfDecrement> node){};
    void visit(std::shared_ptr<SelfIncrement> node){};
    virtual void visit(std::shared_ptr<StringConst> node)=0;
    virtual void visit(std::shared_ptr<UnaryExpr> node)=0;
    void visit(std::shared_ptr<Program> node){
        if(node == NULL) return;
        std::shared_ptr<SymbolTable> ptr(new SymbolTable());
        ClassList = ptr;
        node -> classTable = ptr;
        for(int i = 0; i < (node -> decls).size(); ++i) {
            if((node ->decls)[i] -> getType() == "class"){
                (node -> decls)[i] -> visited(shared_from_this());
            }
        }
    }
    virtual void visit(std::shared_ptr<ClassTypeNode> node)=0;
};

#endif /* ASTSymbol_h */
