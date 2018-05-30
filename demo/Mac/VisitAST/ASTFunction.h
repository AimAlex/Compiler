//
//  ASTFunction.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/4/30.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef ASTFunction_h
#define ASTFunction_h
#include "ASTVisitor.h"
#include "SymbolTable.h"
#include <vector>
#include "ClassType.h"
#include "FunctionType.h"
class ASTFunction : public ASTVisitor, public std::enable_shared_from_this<ASTFunction>{
public:
    std::vector<std::shared_ptr<SymbolTable>> currentTable;
    void visit(std::shared_ptr<IfState>){}
    void visit(std::shared_ptr<ReturnState>){}
    void visit(std::shared_ptr<ForLoop>){}
    void visit(std::shared_ptr<VariableDecl> node){
        if(currentTable.size() == 1) return;
        std::shared_ptr<SymbolNode> ptr(new SymbolNode());
        std::shared_ptr<SymbolTable> currentNode = currentTable[currentTable.size() - 1];
        if(currentNode -> symbolTable.find(node -> name) != currentNode -> symbolTable.end()){
            std::cout<<"exist name： "<<node -> name<<std::endl;
            throw(0);
        }
        if(node -> name[0] == '_'){
            std::cout<<"variable not _"<<std::endl;
            throw(0);
        }
        currentNode -> symbolTable[node -> name] = ptr;
        std::shared_ptr<SymbolType> varType = node -> getType();
        ptr -> type = varType;
        ptr -> table = currentNode;
        node -> scope = ptr;
//        std::cout<<ptr -> table -> name<<std::endl;
        if(varType -> type == SymbolType::ClASS){
            if(currentTable[0] -> symbolTable.find(varType -> getName()) == currentTable[0] -> symbolTable.end()){
                std::cout<<"no such class: "<<varType -> getName()<<std::endl;
                throw(0);
            }
            if(currentTable[0] -> symbolTable[varType -> getName()] -> type -> type != SymbolType::CLASSTYPE){
                std::cout<<"no such class: "<<varType -> getName()<<std::endl;
                throw(0);
            }
        }
        
    }
    void visit(std::shared_ptr<ArrayTypeNode>){}
    void visit(std::shared_ptr<PrimitiveTypeNode>){}
    void visit(std::shared_ptr<CompoundState>){}
    void visit(std::shared_ptr<ClassDecl> node){
        if(node == NULL) return;
        std::shared_ptr<SymbolNode> ptr = currentTable[0] -> symbolTable[node -> name];
        currentTable.push_back(ptr -> table);
        for(int i = 0; i < (node -> functionMembers).size(); ++i) {
            (node -> functionMembers)[i] -> visited(shared_from_this());
        }
        for(int i = 0; i < (node -> variableMembers).size(); ++i) {
            (node -> variableMembers)[i] -> visited(shared_from_this());
        }
        currentTable.pop_back();
    }
    void visit(std::shared_ptr<ContinueState>){}
    void visit(std::shared_ptr<WhileLoop>){}
    void visit(std::shared_ptr<BreakState>){}
    void visit(std::shared_ptr<FunctionDecl> node){
        if(node == NULL) return;
        std::shared_ptr<SymbolNode> ptr(new SymbolNode());
        std::shared_ptr<SymbolTable> currentNode = currentTable[currentTable.size() - 1];
        if(currentNode -> symbolTable.find(node -> name) != currentNode -> symbolTable.end()){
            std::cout<<"exist name: "<<node -> name<<std::endl;
            throw(0);
        }
        if(node -> name[0] == '_'){
            std::cout<<"function not _"<<std::endl;
            throw(0);
        }
        currentNode -> symbolTable[node -> name] = ptr;
        ptr -> table = std::shared_ptr<SymbolTable>(new SymbolTable());
        ptr -> table -> name = node -> name;
        node -> functionTable = ptr -> table;
        currentTable.push_back(ptr -> table);
        
        std::vector<std::shared_ptr<SymbolType>> vec;
        std::shared_ptr<SymbolType> returnType = node -> returnType -> getType();
        if(returnType -> type == SymbolType::ClASS){
            if(currentTable[0] -> symbolTable.find(returnType -> getName()) == currentTable[0] -> symbolTable.end()){
                std::cout<<"no such class: "<<returnType -> getName()<<std::endl;
                throw(0);
            }
            if(currentTable[0] -> symbolTable[returnType -> getName()] -> type -> type != SymbolType::CLASSTYPE){
                std::cout<<"no such class: "<<returnType -> getName()<<std::endl;
                throw(0);
            }
        }
        vec.push_back(returnType);
        for(int i = 0; i <  (node->parameterList).size(); ++i){
            std::shared_ptr<SymbolType> paraType = (node -> parameterList)[i] -> getType();
            if(paraType -> type == SymbolType::ClASS){
                if(currentTable[0] -> symbolTable.find(paraType -> getName()) == currentTable[0] -> symbolTable.end()){
                    std::cout<<"no such class: "<<paraType -> getName()<<std::endl;
                    throw(0);
                }
                if(currentTable[0] -> symbolTable[paraType -> getName()] -> type -> type != SymbolType::CLASSTYPE){
                    std::cout<<"no such class: "<<paraType -> getName()<<std::endl;
                    throw(0);
                }
            }
            (node -> parameterList)[i] -> visited(shared_from_this());
            vec.push_back(paraType);
        }
//        std::cout<<node ->name <<" "<<node -> parameterList.size()<<std::endl;
        node -> functiontype = std::shared_ptr<FunctionType> (new FunctionType(vec, node -> name));
        ptr -> type = node -> functiontype;
        ptr -> type -> type = SymbolType::FUNCTION;
        currentTable.pop_back();
    }
    void visit(std::shared_ptr<ClassConstructor>){}
    void visit(std::shared_ptr<ArrayAccess>){}
    void visit(std::shared_ptr<BinaryExpr>){}
    void visit(std::shared_ptr<BoolConst>){}
    void visit(std::shared_ptr<EmptyExpr>){}
    void visit(std::shared_ptr<FunctionCall>){}
    void visit(std::shared_ptr<Identifier>){}
    void visit(std::shared_ptr<IntConst>){}
    void visit(std::shared_ptr<MemberAccess>){}
    void visit(std::shared_ptr<NewExpr>){}
    void visit(std::shared_ptr<NullLiteral>){}
    void visit(std::shared_ptr<SelfDecrement>){}
    void visit(std::shared_ptr<SelfIncrement>){}
    void visit(std::shared_ptr<StringConst>){}
    void visit(std::shared_ptr<UnaryExpr>){}
    void visit(std::shared_ptr<Program> node){
        if(node == NULL) return;
        std::shared_ptr<SymbolTable> ptr = node -> Table;
        currentTable.push_back(ptr);
        for(int i = 0; i < (node -> decls).size(); ++i) {
            (node -> decls)[i] -> visited(shared_from_this());
        }
        if(currentTable[0] -> symbolTable.find("main") == currentTable[0] -> symbolTable.end()){
            std::cout<<"no main"<<std::endl;
            throw(0);
        }
        std::shared_ptr<SymbolNode> m = currentTable[0]-> symbolTable["main"];
        if(m -> type -> type != SymbolType::FUNCTION){
            std::cout<<"main is not function"<<std::endl;
            throw(0);
        }
        std::vector<std::shared_ptr<SymbolType>> vec(m -> type -> getFunction());
        if(vec.size() != 1){
            std::cout<<"main has parameter"<<std::endl;
            throw(0);
        }
        if(vec[0] -> type != SymbolType::INT){
            std::cout<<"main returntype error"<<std::endl;
            throw(0);
        }
        currentTable.pop_back();
        //        auto iter = node -> Table -> symbolTable.begin();
        //        while(iter != node -> Table -> symbolTable.end()) {
        //            std::cout << iter->first<< std::endl;
        //            iter++;
        //        }
    }
    void visit(std::shared_ptr<ClassTypeNode>){}
};

#endif /* ASTFunction_h */
