
#include "antlr4-runtime.h"
#include "MBaseListener.h"


/**
 * This class provides an empty implementation of MListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  ASTListener : public antlrcpptest::MBaseListener {
public:
    
    void enterProgram(antlrcpptest::MParser::ProgramContext * /*ctx*/) override {
        
    }
    void exitProgram(antlrcpptest::MParser::ProgramContext * /*ctx*/) override {
        
    }
    
    void enterProgramSection(antlrcpptest::MParser::ProgramSectionContext * ctx) override {
        
    }
    void exitProgramSection(antlrcpptest::MParser::ProgramSectionContext * ctx) override { }
    
    void enterStatement(antlrcpptest::MParser::StatementContext * ctx) override {
        std::cout<<ctx->getText()<<std::endl;
        std::cout<<ctx->getStart()->getLine();
    }
    void exitStatement(antlrcpptest::MParser::StatementContext * ctx) override { }
    
    void enterBlockStatement(antlrcpptest::MParser::BlockStatementContext * /*ctx*/) override { }
    void exitBlockStatement(antlrcpptest::MParser::BlockStatementContext * /*ctx*/) override { }
    
    void enterBlockItem(antlrcpptest::MParser::BlockItemContext * /*ctx*/) override { }
    void exitBlockItem(antlrcpptest::MParser::BlockItemContext * /*ctx*/) override { }
    
    void enterExpressionStatement(antlrcpptest::MParser::ExpressionStatementContext * /*ctx*/) override { }
    void exitExpressionStatement(antlrcpptest::MParser::ExpressionStatementContext * /*ctx*/) override { }
    
    void enterSelectionStatement(antlrcpptest::MParser::SelectionStatementContext * /*ctx*/) override { }
    void exitSelectionStatement(antlrcpptest::MParser::SelectionStatementContext * /*ctx*/) override { }
    
    void enterIterationStatement(antlrcpptest::MParser::IterationStatementContext * /*ctx*/) override { }
    void exitIterationStatement(antlrcpptest::MParser::IterationStatementContext * /*ctx*/) override { }
    
    void enterJumpStatement(antlrcpptest::MParser::JumpStatementContext * /*ctx*/) override { }
    void exitJumpStatement(antlrcpptest::MParser::JumpStatementContext * /*ctx*/) override { }
    
    void enterNonArrayTypeSpecifier(antlrcpptest::MParser::NonArrayTypeSpecifierContext * /*ctx*/) override { }
    void exitNonArrayTypeSpecifier(antlrcpptest::MParser::NonArrayTypeSpecifierContext * /*ctx*/) override { }
    
    void enterTypeSpecifier(antlrcpptest::MParser::TypeSpecifierContext * ctx) override {
        std::cout<<ctx->getText()<<std::endl;
        std::cout<<ctx->getStart()->getLine()<<std::endl;
    }
    void exitTypeSpecifier(antlrcpptest::MParser::TypeSpecifierContext * /*ctx*/) override { }
    
    void enterVariableDeclaration(antlrcpptest::MParser::VariableDeclarationContext * /*ctx*/) override { }
    void exitVariableDeclaration(antlrcpptest::MParser::VariableDeclarationContext * /*ctx*/) override { }
    
    void enterVariableInitDeclarator(antlrcpptest::MParser::VariableInitDeclaratorContext * /*ctx*/) override { }
    void exitVariableInitDeclarator(antlrcpptest::MParser::VariableInitDeclaratorContext * /*ctx*/) override { }
    
    void enterClassDeclaration(antlrcpptest::MParser::ClassDeclarationContext * /*ctx*/) override { }
    void exitClassDeclaration(antlrcpptest::MParser::ClassDeclarationContext * /*ctx*/) override { }
    
    void enterMemberDeclaration(antlrcpptest::MParser::MemberDeclarationContext * /*ctx*/) override { }
    void exitMemberDeclaration(antlrcpptest::MParser::MemberDeclarationContext * /*ctx*/) override { }
    
    void enterClassFunctionDeclaration(antlrcpptest::MParser::ClassFunctionDeclarationContext * /*ctx*/) override { }
    void exitClassFunctionDeclaration(antlrcpptest::MParser::ClassFunctionDeclarationContext * /*ctx*/) override { }
    
    void enterFunctionDeclaration(antlrcpptest::MParser::FunctionDeclarationContext * ctx) override {
    }
    void exitFunctionDeclaration(antlrcpptest::MParser::FunctionDeclarationContext * /*ctx*/) override { }
    
    void enterParameterDeclarationList(antlrcpptest::MParser::ParameterDeclarationListContext * /*ctx*/) override { }
    void exitParameterDeclarationList(antlrcpptest::MParser::ParameterDeclarationListContext * /*ctx*/) override { }
    
    void enterParameterDeclaration(antlrcpptest::MParser::ParameterDeclarationContext * /*ctx*/) override { }
    void exitParameterDeclaration(antlrcpptest::MParser::ParameterDeclarationContext * /*ctx*/) override { }
    
    void enterNew(antlrcpptest::MParser::NewContext * /*ctx*/) override { }
    void exitNew(antlrcpptest::MParser::NewContext * /*ctx*/) override { }
    
    void enterIdentifier(antlrcpptest::MParser::IdentifierContext * /*ctx*/) override { }
    void exitIdentifier(antlrcpptest::MParser::IdentifierContext * /*ctx*/) override { }
    
    void enterMemberAccess(antlrcpptest::MParser::MemberAccessContext * /*ctx*/) override { }
    void exitMemberAccess(antlrcpptest::MParser::MemberAccessContext * /*ctx*/) override { }
    
    void enterLiteral(antlrcpptest::MParser::LiteralContext * /*ctx*/) override { }
    void exitLiteral(antlrcpptest::MParser::LiteralContext * /*ctx*/) override { }
    
    void enterBinaryExpr(antlrcpptest::MParser::BinaryExprContext * /*ctx*/) override { }
    void exitBinaryExpr(antlrcpptest::MParser::BinaryExprContext * /*ctx*/) override { }
    
    void enterSubscript(antlrcpptest::MParser::SubscriptContext * /*ctx*/) override { }
    void exitSubscript(antlrcpptest::MParser::SubscriptContext * /*ctx*/) override { }
    
    void enterFunctionCall(antlrcpptest::MParser::FunctionCallContext * /*ctx*/) override { }
    void exitFunctionCall(antlrcpptest::MParser::FunctionCallContext * /*ctx*/) override { }
    
    void enterPostfixIncDec(antlrcpptest::MParser::PostfixIncDecContext * /*ctx*/) override { }
    void exitPostfixIncDec(antlrcpptest::MParser::PostfixIncDecContext * /*ctx*/) override { }
    
    void enterUnaryExpr(antlrcpptest::MParser::UnaryExprContext * /*ctx*/) override { }
    void exitUnaryExpr(antlrcpptest::MParser::UnaryExprContext * /*ctx*/) override { }
    
    void enterSubExpression(antlrcpptest::MParser::SubExpressionContext * /*ctx*/) override { }
    void exitSubExpression(antlrcpptest::MParser::SubExpressionContext * /*ctx*/) override { }
    
    void enterCreatorError(antlrcpptest::MParser::CreatorErrorContext * /*ctx*/) override { }
    void exitCreatorError(antlrcpptest::MParser::CreatorErrorContext * /*ctx*/) override { }
    
    void enterCreatorArray(antlrcpptest::MParser::CreatorArrayContext * /*ctx*/) override { }
    void exitCreatorArray(antlrcpptest::MParser::CreatorArrayContext * /*ctx*/) override { }
    
    void enterCreatorNonArray(antlrcpptest::MParser::CreatorNonArrayContext * /*ctx*/) override { }
    void exitCreatorNonArray(antlrcpptest::MParser::CreatorNonArrayContext * /*ctx*/) override { }
    
    void enterParameterList(antlrcpptest::MParser::ParameterListContext * /*ctx*/) override { }
    void exitParameterList(antlrcpptest::MParser::ParameterListContext * /*ctx*/) override { }
    
    void enterConstant(antlrcpptest::MParser::ConstantContext * /*ctx*/) override { }
    void exitConstant(antlrcpptest::MParser::ConstantContext * /*ctx*/) override { }
    
    
    void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
    void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
    void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
    void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }
    
}; // namespace antlrcpptest
