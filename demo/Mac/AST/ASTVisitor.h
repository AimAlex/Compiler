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
    virtual void visit(IfState *node);
    virtual void visit(ReturnState *node);
    virtual void visit(ForLoop *node);
    virtual void visit(VariableDecl *node);
    virtual void visit(ArrayTypeNode *node);
    virtual void visit(PrimitiveTypeNode *node);
    virtual void visit(CompoundState *node);
    virtual void visit(ClassDecl *node);
    virtual void visit(ContinueState *node);
    virtual void visit(WhileLoop *node);
    virtual void visit(BreakState *node);
    virtual void visit(FunctionDecl *node);
    virtual void visit(ClassConstructor *node);
    virtual void visit(ArrayAccess *node);
    virtual void visit(BinaryExpr *node);
    virtual void visit(BoolConst *node);
    virtual void visit(EmptyExpr *node);
    virtual void visit(FunctionCall *node);
    virtual void visit(Identifier *node);
    virtual void visit(IntConst *node);
    virtual void visit(MemberAccess *node);
    virtual void visit(NewExpr *node);
    virtual void visit(NullLiteral *node);
    virtual void visit(SelfDecrement *node);
    virtual void visit(SelfIncrement *node);
    virtual void visit(StringConst *node);
    virtual void visit(UnaryExpr *node);
    virtual void visit(Program *node);
    virtual void visit(ClassTypeNode *node);
};

#endif /* ASTVisitor_h */
