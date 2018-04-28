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
        std::cout<<str.size()<<std::endl;
    }
    
    void dedent() {
        for(int i = 0; i < 4; ++i) {
            std::cout<<str.size()<<std::endl;
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
    void visit(std::shared_ptr<ForLoop> node){
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
        (node -> classconstructor) -> visited(std::shared_ptr<ASTVisitor>(this));
        for(int i = 0; i < (node -> functionMembers).size(); ++i) {
            (node -> functionMembers)[i] -> visited(std::shared_ptr<ASTVisitor>(this));
        }
        dedent();
    }
    void visit(std::shared_ptr<ContinueState> node){
        if(node == NULL) return;
        std::cout<<str<<"ContinueState"<<std::endl;
    }
    void visit(std::shared_ptr<WhileLoop> node){
        if(node == NULL) return;
        std::cout<<str<<"WhileLoop"<<std::endl;
        indent();
        (node -> cond) -> visited(std::shared_ptr<ASTVisitor>(this));
        (node -> body) -> visited(std::shared_ptr<ASTVisitor>(this));
        dedent();
    }
    void visit(std::shared_ptr<BreakState> node){
        if(node == NULL) return;
        std::cout<<str<<"BreakState"<<std::endl;
    }
    void visit(std::shared_ptr<FunctionDecl> node){
        if(node == NULL)return;
        std::cout<<str<<"FunctionDecl: "<<node->name<<std::endl;
        indent();
        (node -> returnType) -> visited(std::shared_ptr<ASTVisitor>(this));
        std::cout<<node->parameterList.size()<<std::endl;
        for(int i = 0; i <  (node->parameterList).size(); ++i){
            (node -> parameterList)[i] -> visited(std::shared_ptr<ASTVisitor>(this));
        }
        (node -> body) -> visited(std::shared_ptr<ASTVisitor>(this));
        dedent();
    }
    void visit(std::shared_ptr<ClassConstructor> node){
        if(node == NULL) return;
        std::cout<<str<<"ClassConstructor: "<<node->name<<std::endl;
        indent();
        (node -> body) -> visited(std::shared_ptr<ASTVisitor> (this));
        dedent();
    }
    void visit(std::shared_ptr<ArrayAccess> node){
        if(node == NULL) return;
        std::cout<<str<<"ArrayAccess"<<std::endl;
        indent();
        (node -> array) -> visited(std::shared_ptr<ASTVisitor>(this));
        (node -> subscript) -> visited(std::shared_ptr<ASTVisitor>(this));
        dedent();
    }
    void visit(std::shared_ptr<BinaryExpr> node){
        if(node == NULL) return;
        std::cout<<str<<"BinaryExpr: "<<node->op<<std::endl;
        indent();
        (node -> lhs) -> visited(std::shared_ptr<ASTVisitor>(this));
        (node -> rhs) -> visited(std::shared_ptr<ASTVisitor>(this));
        dedent();
    }
    void visit(std::shared_ptr<BoolConst> node){
        if(node == NULL) return;
        std::cout<<str<<"BoolConst: "<<node->value<<std::endl;
    }
    void visit(std::shared_ptr<EmptyExpr> node){
        if(node == NULL) return;
        std::cout<<str<<"EmptyExpr"<<std::endl;
    }
    void visit(std::shared_ptr<FunctionCall> node){
        if(node == NULL) return;
        std::cout<<str<<"FunctionCall"<<std::endl;
        indent();
        (node -> name) -> visited(std::shared_ptr<ASTVisitor> (this));
        for(int i = 0; i <  (node->parameters).size(); ++i){
            (node -> parameters)[i] -> visited(std::shared_ptr<ASTVisitor>(this));
        }
    }
    void visit(std::shared_ptr<Identifier> node){
        if(node == NULL)return;
        std::cout<<str<<"Identifier: "<<node->name<<std::endl;
    }
    void visit(std::shared_ptr<IntConst> node){
        if(node == NULL) return;
        std::cout<<str<<"IntConst: "<<node->value<<std::endl;
    }
    void visit(std::shared_ptr<MemberAccess> node){
        if(node == NULL) return;
        std::cout<<str<<"MemberAccess: "<<node->member<<std::endl;
        indent();
        (node -> record) -> visited(std::shared_ptr<ASTVisitor>(this));
        dedent();
    }
    void visit(std::shared_ptr<NewExpr> node){
        if(node == NULL) return;
        std::cout<<str<<"NewExpr"<<std::endl;
        indent();
        (node -> type) -> visited(std::shared_ptr<ASTVisitor> (this));
        for(int i = 0; i < (node -> dim).size(); ++i) {
            std::cout<<str<<"[ ";
            (node -> dim)[i] -> visited(std::shared_ptr<ASTVisitor>(this));
            std::cout<<str<<" ]";
        }
        dedent();
    }
    void visit(std::shared_ptr<NullLiteral> node){
        if(node == NULL) return;
        std::cout<<str<<"NullLiteral"<<std::endl;
    }
    void visit(std::shared_ptr<SelfDecrement> node){
        if(node == NULL) return;
        std::cout<<str<<"SelfDecrement"<<std::endl;
        indent();
        (node -> oneself) -> visited(std::shared_ptr<ASTVisitor> (this));
        dedent();
    }
    void visit(std::shared_ptr<SelfIncrement> node){
        if(node == NULL) return;
        std::cout<<str<<"SelfIncrement"<<std::endl;
        indent();
        (node -> oneself) -> visited(std::shared_ptr<ASTVisitor> (this));
        dedent();
    }
    void visit(std::shared_ptr<StringConst> node){
        if(node == NULL) return;
        std::cout<<str<<"StringConst: "<<node -> value<<std::endl;
    }
    void visit(std::shared_ptr<UnaryExpr> node){
        if(node == NULL) return;
        std::cout<<str<<"UnaryExpr: "<<node->op<<std::endl;
        indent();
        (node -> body) -> visited(std::shared_ptr<ASTVisitor> (this));
        dedent();
    }
    void visit(std::shared_ptr<Program> node){
        if(node == NULL) return;
        std::cout<<str<<"Program"<<std::endl;
        indent();
        for(int i = 0; i < (node -> decls).size(); ++i) {
            (node -> decls)[i] -> visited(std::shared_ptr<ASTVisitor>(this));
        }
        dedent();
    }
    void visit(std::shared_ptr<ClassTypeNode> node){
        if(node == NULL) return;
        std::cout<<str<<"ClassTypeNode: "<<node -> name<<std::endl;
    }
};

#endif /* ASTPrinter_h */
