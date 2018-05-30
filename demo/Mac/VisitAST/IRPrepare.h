//
//  IRPrepare.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/30.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef IRPrepare_h
#define IRPrepare_h
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
#include "Return.h"
#include "BinaryOperation.h"
#include "Load.h"
#include "Branch.h"
#include "UnaryOperation.h"
#include "StaticString.h"
#include "HeapAllocate.h"
#include "IntComparison.h"
#include "Call.h"
#include "ClassRoot.h"
#define INTSIZE 8
class IRPrepare : public ASTVisitor, public std::enable_shared_from_this<IRPrepare>{
public:
    std::shared_ptr<IRRoot> irRoot;
    std::map<std::string, std::shared_ptr<Function>> ownfunctions;
    std::shared_ptr<ClassRoot> currentClass = NULL;
    std::shared_ptr<SymbolTable> GlobalSymbolTable;
    
    void visit(std::shared_ptr<Program> node){
        GlobalSymbolTable = node -> Table;
        irRoot = std::shared_ptr<IRRoot>(new IRRoot);
        node -> irRoot = irRoot;
        for(std::map<std::string, std::shared_ptr<SymbolNode>>::iterator iter= GlobalSymbolTable -> symbolTable.begin(); iter != GlobalSymbolTable -> symbolTable.end(); ++iter){
            if(iter -> second -> type -> type == SymbolType::FUNCTION) {
                //                std::cout<<iter -> first<<std::endl;
                ownfunctions[iter -> first] = std::shared_ptr<Function>(new Function(std::dynamic_pointer_cast<FunctionType>(iter -> second -> type)));
            }
            if(iter -> second -> type -> type == SymbolType::CLASSTYPE){
                irRoot -> classList[iter -> first] = std::shared_ptr<ClassRoot>(new ClassRoot(iter -> first));
            }
        }
        for(int i = 0; i < (node -> decls).size(); ++i) {
            (node -> decls)[i] -> visited(shared_from_this());
        }
    }
    
    void visit(std::shared_ptr<VariableDecl>){}
    
    void visit(std::shared_ptr<FunctionDecl> node){
        irRoot -> functions[node -> name] = ownfunctions[node -> name];
    }
    
    void visit(std::shared_ptr<BreakState>){}
    
    void visit(std::shared_ptr<ContinueState>){}
    
    void visit(std::shared_ptr<ReturnState>){}
    void visit(std::shared_ptr<CompoundState>){}
    void visit(std::shared_ptr<IfState>){}
    void visit(std::shared_ptr<ForLoop>){}
    
    void visit(std::shared_ptr<WhileLoop>){}
    void visit(std::shared_ptr<ArrayAccess>){}
    
    void visit(std::shared_ptr<UnaryExpr>){}
    
    void visit(std::shared_ptr<BinaryExpr>){}
    
    void visit(std::shared_ptr<BoolConst>){}
    
    void visit(std::shared_ptr<IntConst>){}
    
    void visit(std::shared_ptr<NullLiteral>){}
    
    void visit(std::shared_ptr<StringConst>){}
    
    void visit(std::shared_ptr<SelfDecrement>){}
    
    void visit(std::shared_ptr<SelfIncrement>){}
    
    void visit(std::shared_ptr<Identifier>){}
    void visit(std::shared_ptr<NewExpr>){}
    
    void visit(std::shared_ptr<FunctionCall>){}
    
    void visit(std::shared_ptr<ClassDecl> node){
        std::shared_ptr<SymbolNode> classTable = GlobalSymbolTable -> symbolTable[node -> name];
        std::shared_ptr<ClassRoot> curClass = irRoot -> classList[node -> name];
        currentClass = curClass;
        for(std::map<std::string, std::shared_ptr<SymbolNode>>::iterator iter = classTable -> table -> symbolTable.begin(); iter != classTable -> table -> symbolTable.end(); ++iter){
            if(iter -> first == "this") continue;
            if(iter -> second -> type -> type == SymbolType::FUNCTION) {
                curClass -> functions[iter -> first] = std::shared_ptr<Function>(new Function(std::dynamic_pointer_cast<FunctionType>(iter -> second -> type)));
            }
            if(iter -> second -> type -> type == SymbolType::CONSTRUCT) {
                curClass -> constructor = std::shared_ptr<Function>(new Function(std::dynamic_pointer_cast<FunctionType>(iter -> second -> type)));
            }
        }
    }
    
    void visit(std::shared_ptr<ClassConstructor>){}
    
    void visit(std::shared_ptr<MemberAccess>){}
    void visit(std::shared_ptr<ClassTypeNode>){};
    void visit(std::shared_ptr<EmptyExpr>){};
    void visit(std::shared_ptr<ArrayTypeNode>){};
    void visit(std::shared_ptr<PrimitiveTypeNode>){};
};

#endif /* IRPrepare_h */
