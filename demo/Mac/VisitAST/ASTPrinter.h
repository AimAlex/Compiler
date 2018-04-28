//
//  ASTPrinter.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/4/27.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef ASTPrinter_h
#define ASTPrinter_h
#include "ASTVisitor.h"
class ASTPrinter : public ASTVisitor{
public:
    std::string str;
    void indent() {
        str.append("    ");
    }
    
    void dedent() {
        for(int i = 0; i < 4; ++i) {
            str.pop_back();
        }
    }
    
    void visit(std::shared_ptr<IfState> node){
        if(node == NULL) return;
        std::cout<<str<<"if"<<std::endl;
        indent();
        (node -> cond) -> visited(std::shared_ptr<ASTVisitor> (this));
        (node -> then) -> visited(std::shared_ptr<ASTVisitor> (this));
        (node -> otherwise) -> visited(std::shared_ptr<ASTVisitor> (this));
        dedent();
    }
    void visit(std::shared_ptr<ReturnState> node){
        if(node == NULL) return;
        std::cout<<str<<"return"<<std::endl;
        indent();
        (node -> value) -> visited(std::shared_ptr<ASTVisitor>(this));
        dedent();
    }
    virtual void visit(std::shared_ptr<ForLoop> node){
        if(node == NULL) return;
        std::cout<<str<<"for"<<std::endl;
        indent();
        if (node -> initWithDecl != NULL){
            (node -> initWithDecl) -> visited(std::shared_ptr<ASTVisitor> (this));
        }
        else{
            (node -> init) -> visited(std::shared_ptr<ASTVisitor>(this));
        }
        (node -> cond) -> visited(std::shared_ptr<ASTVisitor>(this));
        (node -> step) -> visited(std::shared_ptr<ASTVisitor>(this));
        (node -> body) -> visited(std::shared_ptr<ASTVisitor>(this));
        dedent();
    }
    void visit(std::shared_ptr<VariableDecl> node){
        if(node == NULL) return;
        std::cout<<str<<"VariableDecl"<<": "<<node ->name<<std::endl;
        indent();
        (node -> type) -> visited(std::shared_ptr<ASTVisitor>(this));
        (node -> init) -> visited(std::shared_ptr<ASTVisitor>(this));
        dedent();
    }
    void visit(std::shared_ptr<ArrayTypeNode> node){
        if(node == NULL) return;
        std::cout<<str<<"ArrayTypeNode"<<std::endl;
        indent();
        (node -> type) -> visited(std::shared_ptr<ASTVisitor>(this));
        std::cout<<str<<"dememsion: "<<node->demension<<std::endl;
        dedent();
    }
    void visit(std::shared_ptr<PrimitiveTypeNode> node){
        if(node == NULL) return;
        std::cout<<str<<"PrimitiveTypeNode: "<<node->type<<std::endl;
    }
    void visit(std::shared_ptr<CompoundState> node){
        if(node == NULL) return;
        std::cout<<str<<"CompoundState"<<std::endl;
        indent();
        for(int i = 0; i < node -> stmts.size(); ++i) {
            (node -> stmts)[i] -> visited(std::shared_ptr<ASTVisitor>(this));
        }
        dedent();
    }
    void visit(std::shared_ptr<ClassDecl> node){
        if(node == NULL) return;
        std::cout<<str<<"ClassDecl: "<<node->name<<std::endl;
        indent();
        for(int i = 0; i < (node -> variableMembers).size(); ++i) {
            (node -> variableMembers)[i] -> visited(std::shared_ptr<ASTVisitor>(this));
        }
    }
    void visit(std::shared_ptr<ContinueState> node){
        if(node == NULL) return;
        std::cout<<str<<"ContinueState"<<std::endl;
    }
    virtual void visit(std::shared_ptr<WhileLoop> node);
    virtual void visit(std::shared_ptr<BreakState> node);
    virtual void visit(std::shared_ptr<FunctionDecl> node);
    virtual void visit(std::shared_ptr<ClassConstructor> node);
    virtual void visit(std::shared_ptr<ArrayAccess> node);
    virtual void visit(std::shared_ptr<BinaryExpr> node);
    virtual void visit(std::shared_ptr<BoolConst> node);
    virtual void visit(std::shared_ptr<EmptyExpr> node);
    virtual void visit(std::shared_ptr<FunctionCall> node);
    virtual void visit(std::shared_ptr<Identifier> node);
    virtual void visit(std::shared_ptr<IntConst> node);
    virtual void visit(std::shared_ptr<MemberAccess> node);
    virtual void visit(std::shared_ptr<NewExpr> node);
    virtual void visit(std::shared_ptr<NullLiteral> node);
    virtual void visit(std::shared_ptr<SelfDecrement> node);
    virtual void visit(std::shared_ptr<SelfIncrement> node);
    virtual void visit(std::shared_ptr<StringConst> node);
    virtual void visit(std::shared_ptr<UnaryExpr> node);
    virtual void visit(std::shared_ptr<Program> node);
    virtual void visit(std::shared_ptr<ClassTypeNode> node);
};

#endif /* ASTPrinter_h */
