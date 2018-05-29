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
            throw(0);
        }
        if(node -> name[0] == '_'){
            std::cout<<"class name not _"<<std::endl;
            throw(0);
        }
        currentTable -> symbolTable[node -> name] = ptr;
        ptr -> table = std::shared_ptr<SymbolTable>(new SymbolTable());
        ptr -> table -> name = node -> name;
        node -> classTable = ptr -> table;
        ptr -> type = std::shared_ptr<SymbolType> (new ClassType(""));
        ptr -> type -> type = SymbolType::CLASSTYPE;
        
        std::shared_ptr<SymbolType> thisType(new ClassType(node -> name));
        thisType -> type = SymbolType::ClASS;
        std::shared_ptr<SymbolNode> thisNode(new SymbolNode());
        thisNode -> type = thisType;
        ptr -> table -> symbolTable["this"] = thisNode;
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
            throw(0);
        }
        std::shared_ptr<SymbolNode> ptr (new SymbolNode());
        currentTable -> symbolTable[node -> name] = ptr;
        ptr -> table = std::shared_ptr<SymbolTable>  (new SymbolTable());
        ptr -> table -> name = node -> name;
        node -> constructorTable = ptr -> table;
        ptr -> type = std::shared_ptr<SymbolType> (new FunctionType(node -> name));
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
        
        std::shared_ptr<SymbolNode> Print(new SymbolNode());
        std::vector<std::shared_ptr<SymbolType>> Printvec;
        std::shared_ptr<SymbolType> PrintReturn (new VariableType("void", 0));
        PrintReturn -> type = SymbolType::VOID;
        Printvec.push_back(PrintReturn);
        std::shared_ptr<SymbolType> PrintPar (new VariableType("string", 0));
        PrintPar -> type = SymbolType::STRING;
        Printvec.push_back(PrintPar);
        Print -> type = std::shared_ptr<SymbolType>(new FunctionType(Printvec, "print"));
        Print -> type -> type = SymbolType::FUNCTION;
        ptr -> symbolTable["print"] = Print;
        
        std::shared_ptr<SymbolNode> Println(new SymbolNode());
        std::vector<std::shared_ptr<SymbolType>> Printlnvec;
        std::shared_ptr<SymbolType> PrintlnReturn (new VariableType("void", 0));
        PrintlnReturn -> type = SymbolType::VOID;
        Printlnvec.push_back(PrintlnReturn);
        std::shared_ptr<SymbolType> PrintlnPar (new VariableType("string", 0));
        PrintlnPar -> type = SymbolType::STRING;
        Printlnvec.push_back(PrintlnPar);
        Println -> type = std::shared_ptr<SymbolType>(new FunctionType(Printlnvec, "println"));
        Println -> type -> type = SymbolType::FUNCTION;
        ptr -> symbolTable["println"] = Println;
        
        std::shared_ptr<SymbolNode> GetString(new SymbolNode());
        std::vector<std::shared_ptr<SymbolType>> GetStringvec;
        std::shared_ptr<SymbolType> GetStringReturn (new VariableType("string", 0));
        GetStringReturn -> type = SymbolType::STRING;
        GetStringvec.push_back(GetStringReturn);
        GetString -> type = std::shared_ptr<SymbolType>(new FunctionType(GetStringvec, "getString"));
        GetString -> type -> type = SymbolType::FUNCTION;
        ptr -> symbolTable["getString"] = GetString;
        
        std::shared_ptr<SymbolNode> GetInt(new SymbolNode());
        std::vector<std::shared_ptr<SymbolType>> GetIntvec;
        std::shared_ptr<SymbolType> GetIntReturn (new VariableType("int", 0));
        GetIntReturn -> type = SymbolType::INT;
        GetIntvec.push_back(GetIntReturn);
        GetInt -> type = std::shared_ptr<SymbolType>(new FunctionType(GetIntvec, "getInt"));
        GetInt -> type -> type = SymbolType::FUNCTION;
        ptr -> symbolTable["getInt"] = GetInt;
        
        std::shared_ptr<SymbolNode> ToString(new SymbolNode());
        std::vector<std::shared_ptr<SymbolType>> ToStringvec;
        std::shared_ptr<SymbolType> ToStringReturn (new VariableType("string", 0));
        ToStringReturn -> type = SymbolType::STRING;
        ToStringvec.push_back(ToStringReturn);
        std::shared_ptr<SymbolType> ToStringPar (new VariableType("int", 0));
        ToStringPar -> type = SymbolType::INT;
        ToStringvec.push_back(ToStringPar);
        ToString -> type = std::shared_ptr<SymbolType>(new FunctionType(ToStringvec, "toString"));
        ToString -> type -> type = SymbolType::FUNCTION;
        ptr -> symbolTable["toString"] = ToString;
        
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
