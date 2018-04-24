
// Generated from M.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "MParser.h"


namespace antlrcpptest {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by MParser.
 */
class  MVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by MParser.
   */
    virtual antlrcpp::Any visitProgram(MParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitProgramSection(MParser::ProgramSectionContext *context) = 0;

    virtual antlrcpp::Any visitStatement(MParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitBlockStatement(MParser::BlockStatementContext *context) = 0;

    virtual antlrcpp::Any visitBlockItem(MParser::BlockItemContext *context) = 0;

    virtual antlrcpp::Any visitExpressionStatement(MParser::ExpressionStatementContext *context) = 0;

    virtual antlrcpp::Any visitSelectionStatement(MParser::SelectionStatementContext *context) = 0;

    virtual antlrcpp::Any visitIterationStatement(MParser::IterationStatementContext *context) = 0;

    virtual antlrcpp::Any visitJumpStatement(MParser::JumpStatementContext *context) = 0;

    virtual antlrcpp::Any visitNonArrayTypeSpecifier(MParser::NonArrayTypeSpecifierContext *context) = 0;

    virtual antlrcpp::Any visitTypeSpecifier(MParser::TypeSpecifierContext *context) = 0;

    virtual antlrcpp::Any visitLbr(MParser::LbrContext *context) = 0;

    virtual antlrcpp::Any visitVariableDeclaration(MParser::VariableDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitVariableInitDeclarator(MParser::VariableInitDeclaratorContext *context) = 0;

    virtual antlrcpp::Any visitClassDeclaration(MParser::ClassDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitMemberDeclaration(MParser::MemberDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitClassConstructor(MParser::ClassConstructorContext *context) = 0;

    virtual antlrcpp::Any visitFunctionDeclaration(MParser::FunctionDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitParameterDeclarationList(MParser::ParameterDeclarationListContext *context) = 0;

    virtual antlrcpp::Any visitParameterDeclaration(MParser::ParameterDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitNew(MParser::NewContext *context) = 0;

    virtual antlrcpp::Any visitIdentifier(MParser::IdentifierContext *context) = 0;

    virtual antlrcpp::Any visitMemberAccess(MParser::MemberAccessContext *context) = 0;

    virtual antlrcpp::Any visitLiteral(MParser::LiteralContext *context) = 0;

    virtual antlrcpp::Any visitBinaryExpr(MParser::BinaryExprContext *context) = 0;

    virtual antlrcpp::Any visitSubscript(MParser::SubscriptContext *context) = 0;

    virtual antlrcpp::Any visitFunctionCall(MParser::FunctionCallContext *context) = 0;

    virtual antlrcpp::Any visitPostfixIncDec(MParser::PostfixIncDecContext *context) = 0;

    virtual antlrcpp::Any visitUnaryExpr(MParser::UnaryExprContext *context) = 0;

    virtual antlrcpp::Any visitSubExpression(MParser::SubExpressionContext *context) = 0;

    virtual antlrcpp::Any visitCreatorError(MParser::CreatorErrorContext *context) = 0;

    virtual antlrcpp::Any visitCreatorArray(MParser::CreatorArrayContext *context) = 0;

    virtual antlrcpp::Any visitCreatorNonArray(MParser::CreatorNonArrayContext *context) = 0;

    virtual antlrcpp::Any visitParameterList(MParser::ParameterListContext *context) = 0;

    virtual antlrcpp::Any visitConstant(MParser::ConstantContext *context) = 0;


};

}  // namespace antlrcpptest
