
// Generated from M.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "MListener.h"


namespace antlrcpptest {

/**
 * This class provides an empty implementation of MListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  MBaseListener : public MListener {
public:

  virtual void enterProgram(MParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(MParser::ProgramContext * /*ctx*/) override { }

  virtual void enterProgramSection(MParser::ProgramSectionContext * /*ctx*/) override { }
  virtual void exitProgramSection(MParser::ProgramSectionContext * /*ctx*/) override { }

  virtual void enterStatement(MParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(MParser::StatementContext * /*ctx*/) override { }

  virtual void enterBlockStatement(MParser::BlockStatementContext * /*ctx*/) override { }
  virtual void exitBlockStatement(MParser::BlockStatementContext * /*ctx*/) override { }

  virtual void enterBlockItem(MParser::BlockItemContext * /*ctx*/) override { }
  virtual void exitBlockItem(MParser::BlockItemContext * /*ctx*/) override { }

  virtual void enterExpressionStatement(MParser::ExpressionStatementContext * /*ctx*/) override { }
  virtual void exitExpressionStatement(MParser::ExpressionStatementContext * /*ctx*/) override { }

  virtual void enterSelectionStatement(MParser::SelectionStatementContext * /*ctx*/) override { }
  virtual void exitSelectionStatement(MParser::SelectionStatementContext * /*ctx*/) override { }

  virtual void enterIterationStatement(MParser::IterationStatementContext * /*ctx*/) override { }
  virtual void exitIterationStatement(MParser::IterationStatementContext * /*ctx*/) override { }

  virtual void enterJumpStatement(MParser::JumpStatementContext * /*ctx*/) override { }
  virtual void exitJumpStatement(MParser::JumpStatementContext * /*ctx*/) override { }

  virtual void enterNonArrayTypeSpecifier(MParser::NonArrayTypeSpecifierContext * /*ctx*/) override { }
  virtual void exitNonArrayTypeSpecifier(MParser::NonArrayTypeSpecifierContext * /*ctx*/) override { }

  virtual void enterTypeSpecifier(MParser::TypeSpecifierContext * /*ctx*/) override { }
  virtual void exitTypeSpecifier(MParser::TypeSpecifierContext * /*ctx*/) override { }

  virtual void enterLbr(MParser::LbrContext * /*ctx*/) override { }
  virtual void exitLbr(MParser::LbrContext * /*ctx*/) override { }

  virtual void enterVariableDeclaration(MParser::VariableDeclarationContext * /*ctx*/) override { }
  virtual void exitVariableDeclaration(MParser::VariableDeclarationContext * /*ctx*/) override { }

  virtual void enterVariableInitDeclarator(MParser::VariableInitDeclaratorContext * /*ctx*/) override { }
  virtual void exitVariableInitDeclarator(MParser::VariableInitDeclaratorContext * /*ctx*/) override { }

  virtual void enterClassDeclaration(MParser::ClassDeclarationContext * /*ctx*/) override { }
  virtual void exitClassDeclaration(MParser::ClassDeclarationContext * /*ctx*/) override { }

  virtual void enterMemberDeclaration(MParser::MemberDeclarationContext * /*ctx*/) override { }
  virtual void exitMemberDeclaration(MParser::MemberDeclarationContext * /*ctx*/) override { }

  virtual void enterClassConstructor(MParser::ClassConstructorContext * /*ctx*/) override { }
  virtual void exitClassConstructor(MParser::ClassConstructorContext * /*ctx*/) override { }

  virtual void enterFunctionDeclaration(MParser::FunctionDeclarationContext * /*ctx*/) override { }
  virtual void exitFunctionDeclaration(MParser::FunctionDeclarationContext * /*ctx*/) override { }

  virtual void enterParameterDeclarationList(MParser::ParameterDeclarationListContext * /*ctx*/) override { }
  virtual void exitParameterDeclarationList(MParser::ParameterDeclarationListContext * /*ctx*/) override { }

  virtual void enterParameterDeclaration(MParser::ParameterDeclarationContext * /*ctx*/) override { }
  virtual void exitParameterDeclaration(MParser::ParameterDeclarationContext * /*ctx*/) override { }

  virtual void enterNew(MParser::NewContext * /*ctx*/) override { }
  virtual void exitNew(MParser::NewContext * /*ctx*/) override { }

  virtual void enterIdentifier(MParser::IdentifierContext * /*ctx*/) override { }
  virtual void exitIdentifier(MParser::IdentifierContext * /*ctx*/) override { }

  virtual void enterMemberAccess(MParser::MemberAccessContext * /*ctx*/) override { }
  virtual void exitMemberAccess(MParser::MemberAccessContext * /*ctx*/) override { }

  virtual void enterLiteral(MParser::LiteralContext * /*ctx*/) override { }
  virtual void exitLiteral(MParser::LiteralContext * /*ctx*/) override { }

  virtual void enterBinaryExpr(MParser::BinaryExprContext * /*ctx*/) override { }
  virtual void exitBinaryExpr(MParser::BinaryExprContext * /*ctx*/) override { }

  virtual void enterSubscript(MParser::SubscriptContext * /*ctx*/) override { }
  virtual void exitSubscript(MParser::SubscriptContext * /*ctx*/) override { }

  virtual void enterFunctionCall(MParser::FunctionCallContext * /*ctx*/) override { }
  virtual void exitFunctionCall(MParser::FunctionCallContext * /*ctx*/) override { }

  virtual void enterPostfixIncDec(MParser::PostfixIncDecContext * /*ctx*/) override { }
  virtual void exitPostfixIncDec(MParser::PostfixIncDecContext * /*ctx*/) override { }

  virtual void enterUnaryExpr(MParser::UnaryExprContext * /*ctx*/) override { }
  virtual void exitUnaryExpr(MParser::UnaryExprContext * /*ctx*/) override { }

  virtual void enterSubExpression(MParser::SubExpressionContext * /*ctx*/) override { }
  virtual void exitSubExpression(MParser::SubExpressionContext * /*ctx*/) override { }

  virtual void enterCreatorError(MParser::CreatorErrorContext * /*ctx*/) override { }
  virtual void exitCreatorError(MParser::CreatorErrorContext * /*ctx*/) override { }

  virtual void enterCreatorArray(MParser::CreatorArrayContext * /*ctx*/) override { }
  virtual void exitCreatorArray(MParser::CreatorArrayContext * /*ctx*/) override { }

  virtual void enterCreatorNonArray(MParser::CreatorNonArrayContext * /*ctx*/) override { }
  virtual void exitCreatorNonArray(MParser::CreatorNonArrayContext * /*ctx*/) override { }

  virtual void enterParameterList(MParser::ParameterListContext * /*ctx*/) override { }
  virtual void exitParameterList(MParser::ParameterListContext * /*ctx*/) override { }

  virtual void enterConstant(MParser::ConstantContext * /*ctx*/) override { }
  virtual void exitConstant(MParser::ConstantContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace antlrcpptest
