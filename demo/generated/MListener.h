
// Generated from M.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "MParser.h"


namespace antlrcpptest {

/**
 * This interface defines an abstract listener for a parse tree produced by MParser.
 */
class  MListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(MParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(MParser::ProgramContext *ctx) = 0;

  virtual void enterProgramSection(MParser::ProgramSectionContext *ctx) = 0;
  virtual void exitProgramSection(MParser::ProgramSectionContext *ctx) = 0;

  virtual void enterStatement(MParser::StatementContext *ctx) = 0;
  virtual void exitStatement(MParser::StatementContext *ctx) = 0;

  virtual void enterBlockStatement(MParser::BlockStatementContext *ctx) = 0;
  virtual void exitBlockStatement(MParser::BlockStatementContext *ctx) = 0;

  virtual void enterBlockItem(MParser::BlockItemContext *ctx) = 0;
  virtual void exitBlockItem(MParser::BlockItemContext *ctx) = 0;

  virtual void enterExpressionStatement(MParser::ExpressionStatementContext *ctx) = 0;
  virtual void exitExpressionStatement(MParser::ExpressionStatementContext *ctx) = 0;

  virtual void enterSelectionStatement(MParser::SelectionStatementContext *ctx) = 0;
  virtual void exitSelectionStatement(MParser::SelectionStatementContext *ctx) = 0;

  virtual void enterIterationStatement(MParser::IterationStatementContext *ctx) = 0;
  virtual void exitIterationStatement(MParser::IterationStatementContext *ctx) = 0;

  virtual void enterJumpStatement(MParser::JumpStatementContext *ctx) = 0;
  virtual void exitJumpStatement(MParser::JumpStatementContext *ctx) = 0;

  virtual void enterNonArrayTypeSpecifier(MParser::NonArrayTypeSpecifierContext *ctx) = 0;
  virtual void exitNonArrayTypeSpecifier(MParser::NonArrayTypeSpecifierContext *ctx) = 0;

  virtual void enterTypeSpecifier(MParser::TypeSpecifierContext *ctx) = 0;
  virtual void exitTypeSpecifier(MParser::TypeSpecifierContext *ctx) = 0;

  virtual void enterLbr(MParser::LbrContext *ctx) = 0;
  virtual void exitLbr(MParser::LbrContext *ctx) = 0;

  virtual void enterVariableDeclaration(MParser::VariableDeclarationContext *ctx) = 0;
  virtual void exitVariableDeclaration(MParser::VariableDeclarationContext *ctx) = 0;

  virtual void enterVariableInitDeclarator(MParser::VariableInitDeclaratorContext *ctx) = 0;
  virtual void exitVariableInitDeclarator(MParser::VariableInitDeclaratorContext *ctx) = 0;

  virtual void enterClassDeclaration(MParser::ClassDeclarationContext *ctx) = 0;
  virtual void exitClassDeclaration(MParser::ClassDeclarationContext *ctx) = 0;

  virtual void enterMemberDeclaration(MParser::MemberDeclarationContext *ctx) = 0;
  virtual void exitMemberDeclaration(MParser::MemberDeclarationContext *ctx) = 0;

  virtual void enterClassConstructor(MParser::ClassConstructorContext *ctx) = 0;
  virtual void exitClassConstructor(MParser::ClassConstructorContext *ctx) = 0;

  virtual void enterFunctionDeclaration(MParser::FunctionDeclarationContext *ctx) = 0;
  virtual void exitFunctionDeclaration(MParser::FunctionDeclarationContext *ctx) = 0;

  virtual void enterParameterDeclarationList(MParser::ParameterDeclarationListContext *ctx) = 0;
  virtual void exitParameterDeclarationList(MParser::ParameterDeclarationListContext *ctx) = 0;

  virtual void enterParameterDeclaration(MParser::ParameterDeclarationContext *ctx) = 0;
  virtual void exitParameterDeclaration(MParser::ParameterDeclarationContext *ctx) = 0;

  virtual void enterNew(MParser::NewContext *ctx) = 0;
  virtual void exitNew(MParser::NewContext *ctx) = 0;

  virtual void enterIdentifier(MParser::IdentifierContext *ctx) = 0;
  virtual void exitIdentifier(MParser::IdentifierContext *ctx) = 0;

  virtual void enterMemberAccess(MParser::MemberAccessContext *ctx) = 0;
  virtual void exitMemberAccess(MParser::MemberAccessContext *ctx) = 0;

  virtual void enterLiteral(MParser::LiteralContext *ctx) = 0;
  virtual void exitLiteral(MParser::LiteralContext *ctx) = 0;

  virtual void enterBinaryExpr(MParser::BinaryExprContext *ctx) = 0;
  virtual void exitBinaryExpr(MParser::BinaryExprContext *ctx) = 0;

  virtual void enterSubscript(MParser::SubscriptContext *ctx) = 0;
  virtual void exitSubscript(MParser::SubscriptContext *ctx) = 0;

  virtual void enterFunctionCall(MParser::FunctionCallContext *ctx) = 0;
  virtual void exitFunctionCall(MParser::FunctionCallContext *ctx) = 0;

  virtual void enterPostfixIncDec(MParser::PostfixIncDecContext *ctx) = 0;
  virtual void exitPostfixIncDec(MParser::PostfixIncDecContext *ctx) = 0;

  virtual void enterUnaryExpr(MParser::UnaryExprContext *ctx) = 0;
  virtual void exitUnaryExpr(MParser::UnaryExprContext *ctx) = 0;

  virtual void enterSubExpression(MParser::SubExpressionContext *ctx) = 0;
  virtual void exitSubExpression(MParser::SubExpressionContext *ctx) = 0;

  virtual void enterCreatorError(MParser::CreatorErrorContext *ctx) = 0;
  virtual void exitCreatorError(MParser::CreatorErrorContext *ctx) = 0;

  virtual void enterCreatorArray(MParser::CreatorArrayContext *ctx) = 0;
  virtual void exitCreatorArray(MParser::CreatorArrayContext *ctx) = 0;

  virtual void enterCreatorNonArray(MParser::CreatorNonArrayContext *ctx) = 0;
  virtual void exitCreatorNonArray(MParser::CreatorNonArrayContext *ctx) = 0;

  virtual void enterParameterList(MParser::ParameterListContext *ctx) = 0;
  virtual void exitParameterList(MParser::ParameterListContext *ctx) = 0;

  virtual void enterConstant(MParser::ConstantContext *ctx) = 0;
  virtual void exitConstant(MParser::ConstantContext *ctx) = 0;


};

}  // namespace antlrcpptest
