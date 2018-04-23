
#include "antlr4-runtime.h"
#include "MBaseListener.h"
#include "IfState.h"
#include <map>
#include "FunctionDecl.h"
#include "EmptyExpr.h"
#include "CompoundState.h"
#include "WhileLoop.h"
#include "ForLoop.h"
#include "BreakState.h"
#include "ReturnState.h"
#include "ContinueState.h"
#include "PrimitiveTypeNode.h"
#include "ClassTypeNode.h"
#include "StringConst.h"
#include "VariableDecl.h"
/**
 * This class provides an empty implementation of MListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  ASTListener : public antlrcpptest::MBaseListener {
public:
    std::map<antlr4::ParserRuleContext*, std::shared_ptr<ASTNode>> ASTTree;
    void enterProgram(antlrcpptest::MParser::ProgramContext * /*ctx*/) override {
        
    }
    void exitProgram(antlrcpptest::MParser::ProgramContext * ctx) override {
        
    }
    
    void enterProgramSection(antlrcpptest::MParser::ProgramSectionContext * /*ctx*/) override {
        
    }
    void exitProgramSection(antlrcpptest::MParser::ProgramSectionContext * /*ctx*/) override { }
    
    void enterStatement(antlrcpptest::MParser::StatementContext * /*ctx*/) override {
//        std::cout<<ctx->getText()<<std::endl;
//        std::cout<<ctx->getStart()->getLine();
    }
    void exitStatement(antlrcpptest::MParser::StatementContext * /*ctx*/) override {
//        std::cout<<ctx<<std::endl;
    }
    
    void enterBlockStatement(antlrcpptest::MParser::BlockStatementContext * /*ctx*/) override { }
    void exitBlockStatement(antlrcpptest::MParser::BlockStatementContext * ctx) override {
        std::shared_ptr<ASTNode> ptr(new CompoundState());
        std::vector<std::shared_ptr<ASTNode>> vec;
        for(int i = 0; i < ctx->blockItem().size(); ++i) {
            vec.push_back(ASTTree[ctx->blockItem()[i]]);
        }
        ptr -> accept(vec);
    }
    
    void enterBlockItem(antlrcpptest::MParser::BlockItemContext * /*ctx*/) override { }
    void exitBlockItem(antlrcpptest::MParser::BlockItemContext * /*ctx*/) override { }
    
    void enterExpressionStatement(antlrcpptest::MParser::ExpressionStatementContext * /*ctx*/) override { }
    void exitExpressionStatement(antlrcpptest::MParser::ExpressionStatementContext * ctx) override {
        if(ctx->expression() == NULL) {
//            std::cout<<"NULL"<<std::endl;
            ASTTree[ctx] = NULL;
        }
        else{
            ASTTree[ctx] = ASTTree[ctx->expression()];
//            std::cout<<ctx->toString()<<std::endl;
//            std::cout<<ctx<<std::endl;
        }
    }
    
    void enterSelectionStatement(antlrcpptest::MParser::SelectionStatementContext * /*ctx*/) override {
    }
    void exitSelectionStatement(antlrcpptest::MParser::SelectionStatementContext * ctx) override {
        std::shared_ptr<ASTNode> ptr(new IfState());
        std::vector<std::shared_ptr<ASTNode>> vec;
        vec.push_back(ASTTree[ctx -> expression()]);
        vec.push_back(ASTTree[ctx -> statement()[0]]);
        if(ctx -> statement()[1] ==  NULL) {
            vec.push_back(NULL);
        }
        else {
            vec.push_back(ASTTree[ctx -> statement()[1]]);
        }
        ptr -> accept(vec);
        ASTTree[ctx] = ptr;
    }
    
    void enterIterationStatement(antlrcpptest::MParser::IterationStatementContext * /*ctx*/) override { }
    void exitIterationStatement(antlrcpptest::MParser::IterationStatementContext * ctx) override {
        if(ctx->getStart()->getText() == "while"){
            std::shared_ptr<ASTNode> ptr(new WhileLoop());
            std::vector<std::shared_ptr<ASTNode>> vec;
            vec.push_back(ASTTree[ctx->expression()[0]]);
            vec.push_back(ASTTree[ctx->statement()]);
            ptr -> accept(vec);
            ASTTree[ctx] = ptr;
        }
        else {
            std::shared_ptr<ASTNode> ptr(new ForLoop());
            std::vector<std::shared_ptr<ASTNode>> vec;
            if (ctx -> variableDeclaration() == NULL){
                if(ctx->init == NULL) {
                    vec.push_back(NULL);
                }
                else{
                    vec.push_back(ASTTree[ctx->init]);
                }
                if(ctx->cond == NULL) {
                    vec.push_back(NULL);
                }
                else{
                    vec.push_back(ASTTree[ctx->cond]);
                }
                if(ctx->step == NULL) {
                    vec.push_back(NULL);
                }
                else{
                    vec.push_back(ASTTree[ctx->step]);
                }
                if(ctx->statement() == NULL) {
                    vec.push_back(NULL);
                }
                else{
                    vec.push_back(ASTTree[ctx->statement()]);
                }
            }
            else{
                vec.push_back(NULL);
                if(ctx->cond == NULL) {
                    vec.push_back(NULL);
                }
                else{
                    vec.push_back(ASTTree[ctx->cond]);
                }
                if(ctx->step == NULL) {
                    vec.push_back(NULL);
                }
                else{
                    vec.push_back(ASTTree[ctx->step]);
                }
                if(ctx->statement() == NULL) {
                    vec.push_back(NULL);
                }
                else{
                    vec.push_back(ASTTree[ctx->statement()]);
                }
                for(int i = 0; i < ctx->declinit->variableInitDeclarator().size(); ++i) {
                    vec.push_back(ASTTree[ctx->declinit->variableInitDeclarator()[i]]);
                }
            }
            ptr -> accept(vec);
            ASTTree[ctx] = ptr;
        }
    }
    
    void enterJumpStatement(antlrcpptest::MParser::JumpStatementContext * /*ctx*/) override { }
    void exitJumpStatement(antlrcpptest::MParser::JumpStatementContext * ctx) override {
//        std::cout<<ctx->getStart()->getText()<<std::endl;
        if(ctx->getStart()->getText() == "continue") {
            std::shared_ptr<ASTNode> ptr(new CoutinueState());
            ASTTree[ctx] = ptr;
        }
        else if(ctx->getStart()->getText() == "break") {
            std::shared_ptr<ASTNode> ptr(new BreakState());
            ASTTree[ctx] = ptr;
        }
        else {
            std::shared_ptr<ASTNode> ptr(new ReturnState());
            std::vector<std::shared_ptr<ASTNode>> vec;
            if(ctx->expression() == NULL) {
                vec.push_back(NULL);
            }
            else{
                vec.push_back(ASTTree[ctx->expression()]);
            }
            ptr -> accept(vec);
            ASTTree[ctx] = ptr;
        }
        
    }
    
    void enterNonArrayTypeSpecifier(antlrcpptest::MParser::NonArrayTypeSpecifierContext * /*ctx*/) override { }
    void exitNonArrayTypeSpecifier(antlrcpptest::MParser::NonArrayTypeSpecifierContext * ctx) override {
        if(ctx->type->getText() == "int") {
//            std::cout<<"int"<<std::endl;
            std::shared_ptr<ASTNode> ptr(new PrimitiveTypeNode(PrimitiveTypeNode::Types::INT));
            ASTTree[ctx] = ptr;
        }
        else if(ctx->type->getText() == "bool") {
            std::shared_ptr<ASTNode> ptr(new PrimitiveTypeNode(PrimitiveTypeNode::Types::BOOL));
            ASTTree[ctx] = ptr;
        }
        else if(ctx->type->getText() == "string") {
            std::shared_ptr<ASTNode> ptr(new PrimitiveTypeNode(PrimitiveTypeNode::Types::STRING));
            ASTTree[ctx] = ptr;
        }
        else if(ctx->type->getText() == "void") {
            std::shared_ptr<ASTNode> ptr(new PrimitiveTypeNode(PrimitiveTypeNode::Types::VOID));
            ASTTree[ctx] = ptr;
        }
        else{
//            std::cout<<ctx->Identifier()->getText()<<std::endl;;
            std::shared_ptr<ASTNode> ptr(new ClassTypeNode(ctx->Identifier()->getText()));
            ASTTree[ctx] = ptr;
        }
    }
    
    void enterTypeSpecifier(antlrcpptest::MParser::TypeSpecifierContext * /*ctx*/) override {
    }
    void exitTypeSpecifier(antlrcpptest::MParser::TypeSpecifierContext * /*ctx*/) override { }
    
    void enterVariableDeclaration(antlrcpptest::MParser::VariableDeclarationContext * /*ctx*/) override { }
    void exitVariableDeclaration(antlrcpptest::MParser::VariableDeclarationContext * ctx) override {
        std::cout<<ctx->typeSpecifier()->getText()<<std::endl;
        std::shared_ptr<ASTNode> iden = ASTTree[ctx->typeSpecifier()];
        for(int i = 0; i < ctx->variableInitDeclarator().size(); ++i) {
            std::shared_ptr<ASTNode> ptr(new VariableDecl());
            std::cout<<ctx->variableInitDeclarator()[i]->Identifier()->getText()<<std::endl;
            std::vector<std::shared_ptr<ASTNode>> vec;
            vec.push_back(iden);
            vec.push_back(ASTTree[ctx->variableInitDeclarator()[i]]);
            ptr -> accept(vec);
        }
        std::cout<<ctx->variableInitDeclarator()[0]->Identifier()->getText()<<std::endl;
    }
    
    void enterVariableInitDeclarator(antlrcpptest::MParser::VariableInitDeclaratorContext * /*ctx*/) override { }
    void exitVariableInitDeclarator(antlrcpptest::MParser::VariableInitDeclaratorContext * /*ctx*/) override {
    }
    
    void enterClassDeclaration(antlrcpptest::MParser::ClassDeclarationContext * /*ctx*/) override { }
    void exitClassDeclaration(antlrcpptest::MParser::ClassDeclarationContext * /*ctx*/) override { }
    
    void enterMemberDeclaration(antlrcpptest::MParser::MemberDeclarationContext * /*ctx*/) override { }
    void exitMemberDeclaration(antlrcpptest::MParser::MemberDeclarationContext * /*ctx*/) override { }
    
    void enterClassFunctionDeclaration(antlrcpptest::MParser::ClassFunctionDeclarationContext * /*ctx*/) override { }
    void exitClassFunctionDeclaration(antlrcpptest::MParser::ClassFunctionDeclarationContext * /*ctx*/) override { }
    
    void enterFunctionDeclaration(antlrcpptest::MParser::FunctionDeclarationContext * /*ctx*/) override {
    }
    void exitFunctionDeclaration(antlrcpptest::MParser::FunctionDeclarationContext * ctx) override {
        
        std::shared_ptr <ASTNode> ptr;
        ASTTree[ctx] = ptr;
    }
    
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
