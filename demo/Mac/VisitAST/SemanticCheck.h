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
        if(node -> classconstructor != NULL){
            (node -> classconstructor) -> visited(shared_from_this());
        }
        tableList.pop_back();
    }
    void visit(std::shared_ptr<FunctionDecl> node){
        if(node == NULL) return;
        std::shared_ptr<SymbolTable> ptr = node -> functionTable;
        currentFunctionType = node -> returnType -> getType();
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
            throw(0);
        }
        std::shared_ptr<SymbolType> varType = node -> getType();
        ptr -> type = varType;
        if(varType -> type == SymbolType::Null || varType -> type == SymbolType::VOID){
            std::cout<<"variable error: "<<node -> name<<std::endl;
            throw(0);
        }
//        std::cout<<"name"<<varType -> getName()<<std::endl;
        if(varType -> type == SymbolType::ClASS){
            if(tableList[0] -> symbolTable.find(varType -> getName()) == tableList[0] -> symbolTable.end()){
                std::cout<<"no such class: "<<varType -> getName()<<std::endl;
                throw(0);
            }
            if(tableList[0] -> symbolTable[varType -> getName()] -> type -> type != SymbolType::CLASSTYPE){
                std::cout<<"no such class: "<<varType -> getName()<<std::endl;
                throw(0);
            }
        }
        
        if(node -> init != NULL) {
            (node -> init) -> visited(shared_from_this());
            if (!varType -> sameType(node -> init -> exprType)) {
                std::cout<<"not same type: "<<node -> name<<std::endl;
                throw(0);
            }
        }
        currentNode -> symbolTable[node -> name] = ptr;
    }
    void visit(std::shared_ptr<BreakState> node){
        if(node == NULL) return;
        if (loopStack.empty()) {
            std::cout<<"break error"<<std::endl;
            throw(0);
        }
    }
    void visit(std::shared_ptr<ContinueState> node){
        if(node == NULL) return;
        if(loopStack.empty()){
            std::cout<<"continue error" <<std::endl;
            throw(0);
        }
    }
    void visit(std::shared_ptr<ReturnState> node){
        if(node == NULL) return;
        if(currentFunctionType == NULL) {
            std::cout<<"return not in function"<<std::endl;
            throw(0);
        }
        std::shared_ptr<SymbolType> returnType;
        if(node -> value != NULL){
            (node -> value) -> visited(shared_from_this());
            returnType = node -> value -> exprType;
        }
        else{
            returnType = std::shared_ptr<SymbolType>(new VariableType("void", 0));
            returnType -> type = SymbolType::VOID;
        }
        if(!currentFunctionType -> sameType(returnType)){
            std::cout<<"return type error "<<returnType -> getName()<<std::endl;
            throw(0);
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
        (node -> cond) -> visited(shared_from_this());
        std::shared_ptr<SymbolType> condType = node -> cond -> exprType;
        if(condType -> type != SymbolType::BOOL){
            std::cout<<"condition is not a bool"<<std::endl;
            throw(0);
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
            if(node -> cond -> exprType -> type != SymbolType::BOOL){
                std::cout<<"condition is not a bool"<<std::endl;
                throw(0);
            }
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
            if(node -> cond -> exprType -> type != SymbolType::BOOL){
                std::cout<<"condition is not a bool"<<std::endl;
                throw(0);
            }
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
        if (node -> array -> exprType -> getDemension() == 0) {
            std::cout<<"Array access occurs at non-array expression"<<std::endl;
            throw(0);
        }
        if (node -> subscript -> exprType -> type != SymbolType::INT) {
            std::cout<<"Array subscript is not int"<<std::endl;
            throw(0);
        }
//        node -> exprType = ((ArrayType)node.array.exprType).bodyType;
//        todo
        std::shared_ptr<SymbolType> ptr (new VariableType(node -> array -> exprType -> getName(), node -> array -> exprType -> getDemension() - 1));
        ptr -> type = node -> array -> exprType -> type;
        node -> exprType  = ptr;
        node -> isLvalue = true;
    }
    void visit(std::shared_ptr<FunctionCall> node){
        if(node == NULL) return;
        (node -> name) -> visited(shared_from_this());
        std::shared_ptr<SymbolType> ptr= node -> name -> exprType;
        if(ptr -> type == SymbolType::CLASSTYPE){
            if(node -> parameters.size() != 0){
                std::cout<<"constructor no parametres"<<std::endl;
                throw(0);
            }
            node -> isLvalue = false;
            node -> exprType = std::shared_ptr<SymbolType>(new VariableType(ptr -> getName(), 0));
            node -> exprType -> type = SymbolType::ClASS;
        }
        else if(ptr -> type == SymbolType::FUNCTION){
            std::vector<std::shared_ptr<SymbolType>> vec(ptr -> getFunction());
            if(node -> parameters.size() != vec.size() - 1){
                std::cout<<"parameters number dismatch"<<std::endl;
                throw(0);
            }
            for(int i = 0; i < node -> parameters.size(); ++i){
                (node -> parameters)[i] -> visited(shared_from_this());
                if(!(node -> parameters)[i] -> exprType -> sameType(vec[i + 1])){
                    std::cout<<"parameters types error "<<vec[i + 1] -> getName()<<std::endl;
                    throw(0);
                }
            }
            node -> isLvalue = false;
            node -> exprType = std::shared_ptr<SymbolType>(new VariableType(vec[0] -> getName(), vec[0] -> getDemension()));
            node -> exprType -> type = vec[0] -> type;
        }
        else{
            std::cout<<"functioncall not function"<<ptr -> getName()<<std::endl;
            throw(0);
        }
    }
    void visit(std::shared_ptr<MemberAccess> node){
        if(node == NULL) return;
        (node -> record) -> visited(shared_from_this());
        std::shared_ptr<SymbolType> recordType = node -> record -> exprType;
        if(recordType -> type == SymbolType::ClASS){
            std::string name = recordType -> getName();
            if(tableList[0] -> symbolTable.find(name) == tableList[0] -> symbolTable.end()){
                std::cout<<"no such class: "<<name<<std::endl;
                throw(0);
            }
            std::shared_ptr<SymbolTable> ptr = tableList[0] -> symbolTable[name] -> table;
            if(ptr -> symbolTable.find(node -> member) == ptr -> symbolTable.end()){
                std::cout<<"no such member: "<<node -> member<<std::endl;
                throw(0);
            }
            std::shared_ptr<SymbolType> type = ptr -> symbolTable[node -> member] -> type;
            node -> isLvalue = true;
            node -> exprType = type;
        }
        else if(recordType -> type == SymbolType::STRING){
            if(node -> member == "length"){
                std::vector<std::shared_ptr<SymbolType>> vec;
                std::shared_ptr<SymbolType> newNode(new VariableType("int", 0));
                newNode -> type = SymbolType::INT;
                vec.push_back(newNode);
                std::shared_ptr<SymbolType> ptr (new FunctionType(vec));
                ptr -> type = SymbolType::FUNCTION;
                node -> isLvalue = false;
                node -> exprType = ptr;
            }
            else if(node -> member == "substring"){
                std::vector<std::shared_ptr<SymbolType>> vec;
                std::shared_ptr<SymbolType> newNode(new VariableType("string", 0));
                newNode -> type = SymbolType::STRING;
                std::shared_ptr<SymbolType> paraNode1(new VariableType("int", 0));
                paraNode1 -> type = SymbolType::INT;
                std::shared_ptr<SymbolType> paraNode2(new VariableType("int", 0));
                paraNode2 -> type = SymbolType::INT;
                vec.push_back(newNode);
                vec.push_back(paraNode1);
                vec.push_back(paraNode2);
                std::shared_ptr<SymbolType> ptr (new FunctionType(vec));
                ptr -> type = SymbolType::FUNCTION;
                node -> isLvalue = false;
                node -> exprType = ptr;
            }
            else if(node -> member == "parseInt"){
                std::vector<std::shared_ptr<SymbolType>> vec;
                std::shared_ptr<SymbolType> newNode(new VariableType("int", 0));
                newNode -> type = SymbolType::INT;
                vec.push_back(newNode);
                std::shared_ptr<SymbolType> ptr (new FunctionType(vec));
                ptr -> type = SymbolType::FUNCTION;
                node -> isLvalue = false;
                node -> exprType = ptr;
            }
            else if(node -> member == "ord"){
                std::vector<std::shared_ptr<SymbolType>> vec;
                std::shared_ptr<SymbolType> newNode(new VariableType("int", 0));
                newNode -> type = SymbolType::INT;
                std::shared_ptr<SymbolType> paraNode(new VariableType("int", 0));
                paraNode -> type = SymbolType::INT;
                vec.push_back(newNode);
                vec.push_back(paraNode);
                std::shared_ptr<SymbolType> ptr (new FunctionType(vec));
                ptr -> type = SymbolType::FUNCTION;
                node -> isLvalue = false;
                node -> exprType = ptr;
            }
            else{
                std::cout<<"no such member: "<<node -> member<<std::endl;
                throw(0);
            }
        }
        else if(recordType -> getDemension() != 0){
            if(node -> member != "size"){
                std::cout<<"no such member: "<<node-> member<<std::endl;
            }
            std::vector<std::shared_ptr<SymbolType>> vec;
            std::shared_ptr<SymbolType> newNode(new VariableType("int", 0));
            newNode -> type = SymbolType::INT;
            vec.push_back(newNode);
            std::shared_ptr<SymbolType> ptr (new FunctionType(vec));
            ptr -> type = SymbolType::FUNCTION;
            node -> isLvalue = false;
            node -> exprType = ptr;
        }
        else{
            std::cout<<"member access error"<<std::endl;
            throw(0);
        }
    }
    void visit(std::shared_ptr<Identifier> node){
        std::shared_ptr<SymbolNode> ptr(NULL);
        for(int i = tableList.size() - 1; i >= 0; --i){
            if((tableList[i] -> symbolTable).find(node -> name) == (tableList[i] -> symbolTable).end()){
                continue;
            }
            ptr = (tableList[i] -> symbolTable)[node -> name];
        }
        if (ptr == NULL) {
            std::cout<<"no such symbol"<<std::endl;
            throw(0);
        }
        std::shared_ptr<SymbolType> t = ptr -> type;
        node -> exprType = t;
        node -> isLvalue = (t -> type != SymbolType::FUNCTION);
    }
    void visit(std::shared_ptr<NewExpr> node){
        if(node == NULL) return;
        std::shared_ptr<SymbolType> nodeType = node -> type -> getType();
//        std::cout<<nodeType -> getName()<<std::endl;
        for (int i = 0; i < node -> dim.size(); ++i) {
            std::shared_ptr<ASTNode> x = node -> dim[i];
            if (x == NULL) break;
            x -> visited(shared_from_this());
            if (x -> exprType -> type != SymbolType::INT) {
                std::cout<<"Dimension expression not int"<<std::endl;
                throw(0);
            }
        }
        std::shared_ptr<SymbolType> type (new VariableType(nodeType -> getName(), node -> dim.size()));
        type -> type = nodeType -> type;
        node -> exprType = type;
        node -> isLvalue = false;
    }
    
    void visit(std::shared_ptr<UnaryExpr> node){
        if(node == NULL) return;
        (node -> body) -> visited(shared_from_this());
        switch(node -> op){
            case UnaryExpr::INC:
            case UnaryExpr::DEC:
                if (!node -> body -> isLvalue) {
                    std::cout<<"++ -- not lvalues."<<std::endl;
                    throw(0);
                }
                if (node -> body -> exprType -> type != SymbolType::INT) {
                    std::cout<<"++ -- not int`."<<std::endl;
                    throw(0);
                }
                node -> exprType = std::shared_ptr<SymbolType> (new VariableType("int", 0));
                node -> exprType -> type = SymbolType::INT;
                node -> isLvalue = true;
                break;
            case UnaryExpr::POS:
            case UnaryExpr::NEG:
            case UnaryExpr::BITWISE_NOT:
//                if (!node -> body -> isLvalue) {
//                    std::cout<<"+ - ~ not lvalues."<<std::endl;
//                    throw(0);
//                }
                if (node -> body -> exprType -> type != SymbolType::INT) {
                    std::cout<<"+ - ~ not int."<<std::endl;
                    throw(0);
                }
                node -> exprType = std::shared_ptr<SymbolType> (new VariableType("int", 0));
                node -> exprType -> type = SymbolType::INT;
                node -> isLvalue = false;
                break;
            case UnaryExpr::LOGICAL_NOT:
//                if (!node -> body -> isLvalue) {
//                    std::cout<<"!not lvalues."<<std::endl;
//                    throw(0);
//                }
                if (node -> body -> exprType -> type != SymbolType::BOOL) {
                    std::cout<<"! not bool."<<std::endl;
                    throw(0);
                }
                node -> exprType = std::shared_ptr<SymbolType> (new VariableType("bool", 0));
                node -> exprType -> type = SymbolType::BOOL;
                node -> isLvalue = false;
                break;
        }
    }
    void visit(std::shared_ptr<BinaryExpr> node){
        if(node == NULL) return;
        node -> lhs -> visited(shared_from_this());
        node -> rhs -> visited(shared_from_this());
        if (!node -> lhs -> exprType -> sameType(node -> rhs -> exprType)) {
            std::cout<<"The left and right not the same value"<<node -> rhs -> exprType -> getName()<<std::endl;
            throw(0);
        }
        SymbolType::Types operandType = node -> lhs -> exprType -> type;
        switch (node -> op) {
            case BinaryExpr::ASSIGN:
                if (!node -> lhs -> isLvalue) {
                    std::cout<<"assignment expression not lvalue"<<std::endl;
                    throw(0);
                }
                node -> exprType = node -> rhs -> exprType;//samearea
                node -> isLvalue = true;
                break;
            case BinaryExpr::LOGICAL_OR:
            case BinaryExpr::LOGICAL_AND:
                if (operandType != SymbolType::BOOL) {
                    std::cout<<"or/and not`bool`"<<std::endl;
                    throw(0);
                }
                node -> exprType = std::shared_ptr<SymbolType> (new VariableType("bool", 0));
                node -> exprType -> type = SymbolType::BOOL;
                node -> isLvalue = false;
                break;
            case BinaryExpr::EQ:
            case BinaryExpr::NE:
                node -> exprType = std::shared_ptr<SymbolType> (new VariableType("bool", 0));
                node -> exprType -> type = SymbolType::BOOL;
                node -> isLvalue = false;
                break;
            case BinaryExpr::LT:
            case BinaryExpr::GT:
            case BinaryExpr::LE:
            case BinaryExpr::GE:
                if (operandType != SymbolType::INT && operandType != SymbolType::STRING) {
                    std::cout<<"relational operation not `int` or a `string`"<<std::endl;
                    throw(0);
                }
                node -> exprType = std::shared_ptr<SymbolType> (new VariableType("bool", 0));
                node -> exprType -> type = SymbolType::BOOL;
                node -> isLvalue = false;
                break;
            case BinaryExpr::BITWISE_OR:
            case BinaryExpr::BITWISE_AND:
            case BinaryExpr::XOR:
            case BinaryExpr::SHL:
            case BinaryExpr::SHR:
            case BinaryExpr::SUB:
            case BinaryExpr::MUL:
            case BinaryExpr::DIV:
            case BinaryExpr::MOD:
                if (operandType != SymbolType::INT) {
                    std::cout<<"binary arithmetic operation not`int`"<<std::endl;
                    throw(0);
                }
                node -> exprType = std::shared_ptr<SymbolType> (new VariableType("int", 0));
                node -> exprType -> type = SymbolType::INT;
                node -> isLvalue = false;
                break;
            case BinaryExpr::ADD:
                if(operandType == SymbolType::STRING){
                    node -> exprType = std::shared_ptr<SymbolType> (new VariableType("string", 0));
                    node -> exprType -> type = SymbolType::STRING;
                    node -> isLvalue = false;
                }
                else if(operandType == SymbolType::INT){
                    node -> exprType = std::shared_ptr<SymbolType> (new VariableType("int", 0));
                    node -> exprType -> type = SymbolType::INT;
                    node -> isLvalue = false;
                }
                else{
                    std::cout<<"binary arithmetic operation not`int` or `string`"<<std::endl;
                    throw(0);
                }
                break;
        }
    }
    void visit(std::shared_ptr<EmptyExpr> node){
        if(node == NULL) return;
        node -> exprType = std::shared_ptr<SymbolType> (new VariableType("void", 0));
        node -> exprType -> type = SymbolType::VOID;
        node -> isLvalue = false;
    }
    void visit(std::shared_ptr<BoolConst> node){
        if(node == NULL) return;
        node -> exprType = std::shared_ptr<SymbolType> (new VariableType("bool", 0));
        node -> exprType -> type = SymbolType::BOOL;
        node -> isLvalue = false;
    }
    void visit(std::shared_ptr<IntConst> node){
        if(node == NULL) return;
        node -> exprType = std::shared_ptr<SymbolType> (new VariableType("int", 0));
        node -> exprType -> type = SymbolType::INT;
        node -> isLvalue = false;
    }
    void visit(std::shared_ptr<StringConst> node){
        if(node == NULL) return;
        node -> exprType = std::shared_ptr<SymbolType> (new VariableType("string", 0));
        node -> exprType -> type = SymbolType::STRING;
        node -> isLvalue = false;
    }
    void visit(std::shared_ptr<NullLiteral> node){
        if(node == NULL) return;
        node -> exprType = std::shared_ptr<SymbolType> (new VariableType("null", 0));
        node -> exprType -> type = SymbolType::Null;
        node -> isLvalue = false;
    }

    void visit(std::shared_ptr<SelfDecrement> node){
        if(node == NULL) return;
        node -> oneself -> visited(shared_from_this());
        if (!node -> oneself -> isLvalue) {
            std::cout<<"Self decrement not lvalue."<<std::endl;
            throw (0);
        }
        if (node -> oneself -> exprType -> type != SymbolType::INT) {
            std::cout<<"Self decrement not int "<<std::endl;
            throw(0);
        }
        node -> exprType = std::shared_ptr<SymbolType> (new VariableType("int", 0));
        node -> exprType -> type = SymbolType::INT;
        node -> isLvalue = false;
    }
    void visit(std::shared_ptr<SelfIncrement> node){
        if(node == NULL) return;
        node -> oneself -> visited(shared_from_this());
        if (!node -> oneself -> isLvalue) {
            std::cout<<"Self increment not lvalue."<<std::endl;
            throw (0);
        }
        if (node -> oneself -> exprType -> type != SymbolType::INT) {
            std::cout<<"Self increment not int "<<std::endl;
            throw (0);
        }
        node -> exprType = std::shared_ptr<SymbolType> (new VariableType("int", 0));
        node -> exprType -> type = SymbolType::INT;
        node -> isLvalue = false;
    }
    void visit(std::shared_ptr<ClassTypeNode>){}
    void visit(std::shared_ptr<ArrayTypeNode>){}
    void visit(std::shared_ptr<PrimitiveTypeNode>){}
};

#endif /* SemanticCheck_h */
