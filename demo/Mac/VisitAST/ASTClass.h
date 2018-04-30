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
#include "ConstructorType.h"
class ASTClass : public ASTVisitor, public std::enable_shared_from_this<ASTClass>{
public:
    std::shared_ptr<SymbolTable> currentTable;
    void visit(std::shared_ptr<IfState>){}
    void visit(std::shared_ptr<ReturnState>){}
    void visit(std::shared_ptr<ForLoop>){}
    void visit(std::shared_ptr<VariableDecl>){}
    void visit(std::shared_ptr<ArrayTypeNode>){}
    void visit(std::shared_ptr<PrimitiveTypeNode>){}
    void visit(std::shared_ptr<CompoundState>){}
    void visit(std::shared_ptr<ClassDecl> node){
        if(node == NULL) return;
        std::shared_ptr<SymbolNode> ptr(new SymbolNode());
        if(currentTable -> symbolTable.find(node -> name) != currentTable -> symbolTable.end()){
            std::cout<<"exist class"<<std::endl;
            exit(1);
        }
        currentTable -> symbolTable[node -> name] = ptr;
        ptr -> table = std::shared_ptr<SymbolTable>(new SymbolTable());
        ptr -> table -> name = node -> name;
        node -> classTable = ptr -> table;
        ptr -> type = std::shared_ptr<SymbolType> (new ClassType(""));
        ptr -> type -> type = SymbolType::ClASS;
        if(node -> classconstructor != NULL){
            currentTable = ptr -> table;
            (node -> classconstructor) -> visited(shared_from_this());
        }
    }
    void visit(std::shared_ptr<ContinueState>){}
    void visit(std::shared_ptr<WhileLoop>){}
    void visit(std::shared_ptr<BreakState>){}
    void visit(std::shared_ptr<FunctionDecl>){}
    void visit(std::shared_ptr<ClassConstructor> node){
        if(node == NULL)return;
        if(node -> name != currentTable -> name) {
            std::cout<<"constructor not match"<<std::endl;
        }
        std::shared_ptr<SymbolNode> ptr (new SymbolNode());
        currentTable -> symbolTable[node -> name] = ptr;
        ptr -> table = std::shared_ptr<SymbolTable>  (new SymbolTable());
        ptr -> table -> name = node -> name;
        node -> constructorTable = ptr -> table;
        ptr -> type = std::shared_ptr<SymbolType> (new ConstructorType());
        ptr -> type -> type = SymbolType::CONSTRUCT;
    }
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
        std::shared_ptr<SymbolTable> ptr(new SymbolTable());
        ptr -> name = "Global";
        node -> Table = ptr;
        for(int i = 0; i < (node -> decls).size(); ++i) {
            currentTable = ptr;
            (node -> decls)[i] -> visited(shared_from_this());
        }
//        auto iter = node -> Table -> symbolTable.begin();
//        while(iter != node -> Table -> symbolTable.end()) {
//            std::cout << iter->first<< std::endl;
//            iter++;
//        }
    }
    void visit(std::shared_ptr<ClassTypeNode>){}
};

#endif /* ASTSymbol_h */
