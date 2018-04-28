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
    virtual void visit(std::shared_ptr<IfState> node);
    virtual void visit(std::shared_ptr<ReturnState> node);
    virtual void visit(std::shared_ptr<ForLoop> node);
    virtual void visit(std::shared_ptr<VariableDecl> node);
    virtual void visit(std::shared_ptr<ArrayTypeNode> node);
    virtual void visit(std::shared_ptr<PrimitiveTypeNode> node);
    virtual void visit(std::shared_ptr<CompoundState> node);
    virtual void visit(std::shared_ptr<ClassDecl> node);
    virtual void visit(std::shared_ptr<ContinueState> node);
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

#endif /* ASTVisitor_h */
