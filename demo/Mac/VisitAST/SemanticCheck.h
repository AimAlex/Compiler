//
//  SemanticCheck.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/4/30.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef SemanticCheck_h
#define SemanticCheck_h
#include "ASTVisitor.h"
#include "stack"
class SemanticCheck : public ASTVisitor, public std::enable_shared_from_this<SemanticCheck>{
public:
    std::vector<std::shared_ptr<SymbolTable>> tableList;
    std::shared_ptr<SymbolType> currentFunctionType;
    std::shared_ptr<ASTNode> currentFunction;
    std::stack<std::shared_ptr<ASTNode>> loopStack;
    void visit(std::shared_ptr<Program> node){
        if(node == NULL) return;
        std::shared_ptr<SymbolTable> ptr = node -> Table;
        tableList.push_back(ptr);
        for(int i = 0; i < (node -> decls).size(); ++i) {
            (node -> decls)[i] -> visited(shared_from_this());
        }
        tableList.pop_back();
    }
    void visit(std::shared_ptr<ClassDecl> node){
        if(node == NULL) return;
        std::shared_ptr<SymbolTable> ptr = node -> classTable;
        tableList.push_back(ptr);
        for(int i = 0; i < (node -> functionMembers).size(); ++i) {
            (node -> functionMembers)[i] -> visited(shared_from_this());
        }
        (node -> classconstructor) -> visited(shared_from_this());
        tableList.pop_back();
    }
    void visit(std::shared_ptr<FunctionDecl> node){
        if(node == NULL) return;
        std::shared_ptr<SymbolTable> ptr = node -> functionTable;
        currentFunctionType = node -> getType();
        currentFunction = node;
        tableList.push_back(ptr);
        (node -> body) -> visited(shared_from_this());
        tableList.pop_back();
        currentFunction = NULL;
        currentFunctionType = NULL;
    }
    void visit(std::shared_ptr<VariableDecl> node){
        if(node == NULL) return;
        std::shared_ptr<SymbolNode> ptr(new SymbolNode());
        std::shared_ptr<SymbolTable> currentNode = tableList[tableList.size() - 1];
        if(currentNode -> symbolTable.find(node -> name) != currentNode -> symbolTable.end()){
            std::cout<<"exist name： "<<node -> name<<std::endl;
            exit(1);
        }
        currentNode -> symbolTable[node -> name] = ptr;
        std::shared_ptr<SymbolType> varType = node -> getType();
        ptr -> type = varType;
        if(varType -> type == SymbolType::Null || varType -> type == SymbolType::VOID){
            std::cout<<"variable error: "<<node -> name<<std::endl;
            exit(1);
        }
        
        if(varType -> type == SymbolType::ClASS){
            if(tableList[0] -> symbolTable.find(varType -> getName()) == tableList[0] -> symbolTable.end()){
                std::cout<<"no such class: "<<varType -> getName()<<std::endl;
                exit(1);
            }
            if(tableList[0] -> symbolTable[varType -> getName()] -> type -> type != SymbolType::ClASS){
                std::cout<<"no such class: "<<varType -> getName()<<std::endl;
                exit(1);
            }
        }
        
        if(node -> init != NULL) {
            (node -> init) -> visited(shared_from_this());
        }//to do
        
    }
    void visit(std::shared_ptr<BreakState> node){
        if(node == NULL) return;
        if (loopStack.empty()) {
            std::cout<<"break error"<<std::endl;
            exit(1);
        }
    }
    void visit(std::shared_ptr<ContinueState> node){
        if(node == NULL) return;
        if(loopStack.empty()){
            std::cout<<"continue error" <<std::endl;
            exit(1);
        }
    }
    void visit(std::shared_ptr<ReturnState> node){
        if(node == NULL) return;
        if(currentFunctionType == NULL) {
            std::cout<<"return not in function"<<std::endl;
            exit(1);
        }
        std::shared_ptr<SymbolType> returnType;
        if(node -> value != NULL){
            //to do
        }
        else{
            
        }
        if(returnType -> type != currentFunctionType -> type){
            std::cout<<"return type error"<<std::endl;
            exit(1);
        }
        if(returnType -> type == SymbolType::ClASS && returnType -> getName() != currentFunctionType -> getName()){
            std::cout<<"return classtype error"<<std::endl;
            exit(1);
        }
    }
    void visit(std::shared_ptr<CompoundState> node){
        if(node == NULL) return;
        for(int i = 0; i < node -> stmts.size(); ++i) {
            (node -> stmts)[i] -> visited(shared_from_this());
        }
    }
    void visit(std::shared_ptr<IfState> node){
        if(node == NULL) return;
        std::shared_ptr<SymbolType> condType;
        (node -> cond) -> visited(shared_from_this());
        if(condType -> type != SymbolType::BOOL){
            std::cout<<"condition is not a bool"<<std::endl;
        }
        std::shared_ptr<SymbolTable> ptr(new SymbolTable());
        tableList.push_back(ptr);
        (node -> then) -> visited(shared_from_this());
        tableList.pop_back();
        if (node -> otherwise != NULL) {
            std::shared_ptr<SymbolTable> optr(new SymbolTable());
            tableList.push_back(optr);
            (node -> otherwise) -> visited(shared_from_this());
            tableList.pop_back();
        }
    }
    void visit(std::shared_ptr<ForLoop> node){
        if(node == NULL) return ;
        std::shared_ptr<SymbolTable> ptr(new SymbolTable());
        tableList.push_back(ptr);
        if(node -> init != NULL){
            (node -> init) -> visited(shared_from_this());
        }
        else if(node -> initWithDecl != NULL){
            (node -> init) -> visited(shared_from_this());
        }
        
        if(node -> cond != NULL){
            (node -> cond) -> visited(shared_from_this());
            //todo
        }
        
        if(node -> step != NULL){
            (node -> step) -> visited(shared_from_this());
        }
        
        loopStack.push(node);
        (node -> body) -> visited(shared_from_this());
        loopStack.pop();
        tableList.pop_back();
    }
    void visit(std::shared_ptr<WhileLoop> node){
        if(node == NULL) return ;
        std::shared_ptr<SymbolTable> ptr(new SymbolTable());
        tableList.push_back(ptr);
        if(node -> cond != NULL){
            (node -> cond) -> visited(shared_from_this());
            //todo
        }
        loopStack.push(node);
        (node -> body) -> visited(shared_from_this());
        loopStack.pop();
        
        tableList.pop_back();
    }
    void visit(std::shared_ptr<ClassConstructor> node){
        if(node == NULL) return;
        std::shared_ptr<SymbolTable> ptr = node -> constructorTable;
        tableList.push_back(ptr);
        (node -> body) -> visited(shared_from_this());
        tableList.pop_back();
    }
    
    void visit(std::shared_ptr<ArrayAccess> node){
        if(node == NULL) return;
        (node -> array) -> visited(shared_from_this());
        (node -> subscript) -> visited(shared_from_this());
        //todo
    }
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
    void visit(std::shared_ptr<ClassTypeNode>){}
    void visit(std::shared_ptr<ArrayTypeNode>){}
    void visit(std::shared_ptr<PrimitiveTypeNode>){}
};

#endif /* SemanticCheck_h */
