//
//  ASTVisitor.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/4/27.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef ASTVisitor_h
#define ASTVisitor_h
//#include "IfState.h"
//#include "ReturnState.h"
//#include "ForLoop.h"
//#include "VariableDecl.h"
//#include "ArrayTypeNode.h"
//#include "PrimitiveTypeNode.h"
//#include "CompoundState.h"
//#include "ClassDecl.h"
//#include "ContinueState.h"
//#include "WhileLoop.h"
//#include "BreakState.h"
//#include "FunctionDecl.h"
//#include "ClassConstructor.h"
//#include "ArrayAccess.h"
//#include "BinaryExpr.h"
//#include "BoolConst.h"
//#include "EmptyExpr.h"
//#include "FunctionCall.h"
//#include "Identifier.h"
//#include "IntConst.h"
//#include "MemberAccess.h"
//#include "NewExpr.h"
//#include "NullLiteral.h"
//#include "SelfDecrement.h"
//#include "SelfIncrement.h"
//#include "StringConst.h"
//#include "UnaryExpr.h"
//#include "Program.h"
//#include "ClassTypeNode.h"
class IfState;
class ReturnState;
class ForLoop;
class VariableDecl;
class ArrayTypeNode;
class PrimitiveTypeNode;
class CompoundState;
class ClassDecl;
class ContinueState;
class WhileLoop;
class BreakState;
class FunctionDecl;
class ClassConstructor;
class ArrayAccess;
class BinaryExpr;
class BoolConst;
class EmptyExpr;
class FunctionCall;
class Identifier;
class IntConst;
class MemberAccess;
class NewExpr;
class NullLiteral;
class SelfDecrement;
class SelfIncrement;
class StringConst;
class UnaryExpr;
class Program;
class ClassTypeNode;
class ASTVisitor{
public:
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

#endif /* ASTVisitor_h */
