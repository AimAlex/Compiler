
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
#include "ClassDecl.h"
#include "ArrayTypeNode.h"
#include "SelfDecrement.h"
#include "SelfIncrement.h"
#include "FunctionCall.h"
#include "ArrayAccess.h"
#include "MemberAccess.h"
#include "UnaryExpr.h"
#include "BinaryExpr.h"
#include "Identifier.h"
#include "StringConst.h"
#include "IntConst.h"
#include "NullLiteral.h"
#include "BoolConst.h"
#include <cstdio>
#include "NewExpr.h"
#include "Program.h"

/**
 * This class provides an empty implementation of MListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  ASTListener : public antlrcpptest::MBaseListener {
public:
    std::map<antlr4::ParserRuleContext*, std::shared_ptr<ASTNode>> ASTTree;
    std::shared_ptr<ASTNode> program;
    std::shared_ptr<ASTNode> getProgram() {
        return program;
    }
    void enterProgram(antlrcpptest::MParser::ProgramContext * /*ctx*/) override {
        
    }
    void exitProgram(antlrcpptest::MParser::ProgramContext * ctx) override {
        std::shared_ptr<ASTNode> ptr(new Program());
        std::vector<std::shared_ptr<ASTNode>> vec;
        for(int i = 0; i < ctx->programSection().size(); ++i) {
            vec.push_back(ASTTree[ctx->programSection()[i]]);
        }
        ptr->accept(vec);
        ASTTree[ctx] = ptr;
        program = ptr;
    }
    
    void enterProgramSection(antlrcpptest::MParser::ProgramSectionContext * /*ctx*/) override { }
    void exitProgramSection(antlrcpptest::MParser::ProgramSectionContext * ctx) override {
        if(ctx->classDeclaration() != NULL) {
            ASTTree[ctx] = ASTTree[ctx->classDeclaration()];
        }
        else if(ctx->functionDeclaration() != NULL) {
            ASTTree[ctx] = ASTTree[ctx->functionDeclaration()];
        }
        else if(ctx->variableDeclaration() != NULL) {
            ASTTree[ctx] = ASTTree[ctx->variableDeclaration()];
        }
        else{
            throw(0);
        }
    }
    
    void enterStatement(antlrcpptest::MParser::StatementContext * /*ctx*/) override { }
    void exitStatement(antlrcpptest::MParser::StatementContext * ctx) override {
        if(ctx->blockStatement() != NULL) {
            ASTTree[ctx] = ASTTree[ctx->blockStatement()];
        }
        else if(ctx->expressionStatement() != NULL) {
            ASTTree[ctx] = ASTTree[ctx->expressionStatement()];
        }
        else if(ctx->iterationStatement() != NULL) {
            ASTTree[ctx] = ASTTree[ctx->iterationStatement()];
        }
        else if(ctx->jumpStatement() != NULL) {
            ASTTree[ctx] = ASTTree[ctx->jumpStatement()];
        }
        else if(ctx->selectionStatement() != NULL) {
            ASTTree[ctx] = ASTTree[ctx->selectionStatement()];
        }
        else{
            throw(0);
        }
    }
    
    void enterBlockStatement(antlrcpptest::MParser::BlockStatementContext * /*ctx*/) override { }
    void exitBlockStatement(antlrcpptest::MParser::BlockStatementContext * ctx) override {
        std::shared_ptr<ASTNode> ptr(new CompoundState());
        std::vector<std::shared_ptr<ASTNode>> vec;
        for(int i = 0; i < ctx->blockItem().size(); ++i) {
            vec.push_back(ASTTree[ctx->blockItem()[i]]);
        }
        ptr -> accept(vec);
        ASTTree[ctx] = ptr;
    }
    
    void enterBlockItem(antlrcpptest::MParser::BlockItemContext * /*ctx*/) override { }
    void exitBlockItem(antlrcpptest::MParser::BlockItemContext * ctx) override {
        if(ctx->statement() != NULL) {
            ASTTree[ctx] = ASTTree[ctx->statement()];
        }
        else if(ctx->variableDeclaration() != NULL) {
            ASTTree[ctx] = ASTTree[ctx->variableDeclaration()];
        }
        else{
            throw(0);
        }
    }
    
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
                vec.push_back(NULL);
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
                vec.push_back(ASTTree[ctx->declinit->variableInitDeclarator()]);
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
    void exitTypeSpecifier(antlrcpptest::MParser::TypeSpecifierContext * ctx) override {
        std::shared_ptr<ASTNode> ptr(new ArrayTypeNode());
        std::vector<std::shared_ptr<ASTNode>> vec;
        vec.push_back(ASTTree[ctx->nonArrayTypeSpecifier()]);
        ptr->accept(vec);
        ptr->acceptNum(ctx->lbr().size());
        ASTTree[ctx] = ptr;
    }
    
    void enterVariableDeclaration(antlrcpptest::MParser::VariableDeclarationContext * /*ctx*/) override { }
    void exitVariableDeclaration(antlrcpptest::MParser::VariableDeclarationContext * ctx) override {
//        std::cout<<ctx->typeSpecifier()->getText()<<std::endl;
        std::shared_ptr<ASTNode> iden = ASTTree[ctx->typeSpecifier()];
        std::shared_ptr<ASTNode> ptr(new VariableDecl());
        ptr->acceptStr(ctx->variableInitDeclarator()->Identifier()->getText());
//            std::cout<<ctx->variableInitDeclarator()[i]->Identifier()->getText()<<std::endl;
        std::vector<std::shared_ptr<ASTNode>> vec;
            
        vec.push_back(iden);
        if(ctx->variableInitDeclarator()->expression() == NULL){
                vec.push_back(NULL);
            }
        else{
            vec.push_back(ASTTree[ctx->variableInitDeclarator()->expression()]);
            }
        ptr -> accept(vec);
        ASTTree[ctx] = ptr;
    }
    
    void enterVariableInitDeclarator(antlrcpptest::MParser::VariableInitDeclaratorContext * /*ctx*/) override { }
    void exitVariableInitDeclarator(antlrcpptest::MParser::VariableInitDeclaratorContext * /*ctx*/) override {
    }
    
    void enterClassDeclaration(antlrcpptest::MParser::ClassDeclarationContext * /*ctx*/) override { }
    void exitClassDeclaration(antlrcpptest::MParser::ClassDeclarationContext * ctx) override {
//        std::cout<<ctx->Identifier()->getText()<<std::endl;
        std::shared_ptr<ClassDecl> ptr(new ClassDecl());
        ptr -> acceptStr(ctx->Identifier()->getText());
        std::vector<std::shared_ptr<ASTNode>> varList;
        std::vector<std::shared_ptr<ASTNode>> funcList;
        std::shared_ptr<ASTNode> constructor(NULL);
        for(int i = 0; i < ctx -> memberDeclaration().size(); ++i){
            if(ctx -> memberDeclaration()[i]->classConstructor() != NULL){
                constructor = ASTTree[ctx->memberDeclaration()[i]->classConstructor()];
            }
            else if(ctx -> memberDeclaration()[i]->functionDeclaration() != NULL){
                funcList.push_back(ASTTree[ctx->memberDeclaration()[i]->functionDeclaration()]);
            }
            else{
                varList.push_back(ASTTree[ctx->memberDeclaration()[i]->variableDeclaration()]);
            }
        }
        
        ptr -> accept(varList);
        ptr -> acceptFunction(funcList);
        ptr -> acceptConstructor(constructor);
        ASTTree[ctx] = ptr;
    }
    
    void enterMemberDeclaration(antlrcpptest::MParser::MemberDeclarationContext * /*ctx*/) override { }
    void exitMemberDeclaration(antlrcpptest::MParser::MemberDeclarationContext * /*ctx*/) override { }
    
    void enterClassConstructor(antlrcpptest::MParser::ClassConstructorContext * /*ctx*/) override { }
    void exitClassConstructor(antlrcpptest::MParser::ClassConstructorContext * ctx) override {
        std::shared_ptr<ASTNode> ptr(new ClassConstructor());
        ptr->acceptStr(ctx->Identifier()->getText());
        std::vector<std::shared_ptr<ASTNode>> vec;
        vec.push_back(ASTTree[ctx->blockStatement()]);
        ptr->accept(vec);
        ASTTree[ctx] = ptr;
    }
    
    void enterFunctionDeclaration(antlrcpptest::MParser::FunctionDeclarationContext * /*ctx*/) override {
    }
    void exitFunctionDeclaration(antlrcpptest::MParser::FunctionDeclarationContext * ctx) override {
        std::shared_ptr<ASTNode> ptr(new FunctionDecl());
        std::shared_ptr<ASTNode> iden = ASTTree[ctx->typeSpecifier()];
        ptr -> acceptStr(ctx->Identifier()->getText());
        std::vector<std::shared_ptr<ASTNode>> vec;
        vec.push_back(iden);
        vec.push_back(ASTTree[ctx->blockStatement()]);
        ptr -> accept(vec);
        std::vector<std::shared_ptr<ASTNode>> paraVec;
        if(ctx->parameterDeclarationList() != NULL) {
            for(int i = 0; i < ctx->parameterDeclarationList()->parameterDeclaration().size(); ++i){
                paraVec.push_back(ASTTree[ctx->parameterDeclarationList()->parameterDeclaration()[i]]);
            }
        }
        ptr -> acceptFunction(paraVec);
        ASTTree[ctx] = ptr;
    }
    
    void enterParameterDeclarationList(antlrcpptest::MParser::ParameterDeclarationListContext * /*ctx*/) override { }
    void exitParameterDeclarationList(antlrcpptest::MParser::ParameterDeclarationListContext * /*ctx*/) override {}
    
    void enterParameterDeclaration(antlrcpptest::MParser::ParameterDeclarationContext * /*ctx*/) override { }
    void exitParameterDeclaration(antlrcpptest::MParser::ParameterDeclarationContext * ctx) override {
        std::shared_ptr<ASTNode> iden = ASTTree[ctx->typeSpecifier()];
        std::shared_ptr<ASTNode> ptr(new VariableDecl());
        ptr->acceptStr(ctx->Identifier()->getText());
            //            std::cout<<ctx->variableInitDeclarator()[i]->Identifier()->getText()<<std::endl;
        std::vector<std::shared_ptr<ASTNode>> vec;
        vec.push_back(iden);
        vec.push_back(NULL);
        ptr -> accept(vec);
        ASTTree[ctx] = ptr;
    }
    
    void enterNew(antlrcpptest::MParser::NewContext * /*ctx*/) override { }
    void exitNew(antlrcpptest::MParser::NewContext * ctx) override {
//        std::cout<<ctx->creator()->getText()<<std::endl;
        ASTTree[ctx] = ASTTree[ctx->creator()];
    }
    
    void enterIdentifier(antlrcpptest::MParser::IdentifierContext * /*ctx*/) override { }
    void exitIdentifier(antlrcpptest::MParser::IdentifierContext * ctx) override {
        std::shared_ptr<ASTNode> ptr(new Identifier());
        ptr->acceptStr(ctx->Identifier()->getText());
        ASTTree[ctx] = ptr;
//        std::cout<<ctx->Identifier()->getText()<<std::endl;
    }
    
    void enterMemberAccess(antlrcpptest::MParser::MemberAccessContext * /*ctx*/) override { }
    void exitMemberAccess(antlrcpptest::MParser::MemberAccessContext * ctx) override {
        std::shared_ptr<ASTNode> ptr(new MemberAccess());
        std::vector<std::shared_ptr<ASTNode>> vec;
        vec.push_back(ASTTree[ctx -> expression()]);
        ptr->accept(vec);
        ptr->acceptStr(ctx->Identifier()->getText());
        ASTTree[ctx] = ptr;
//        std::cout<<ctx->Identifier()->getText()<<std::endl;
    }
    
    void enterLiteral(antlrcpptest::MParser::LiteralContext * /*ctx*/) override { }
    void exitLiteral(antlrcpptest::MParser::LiteralContext * ctx) override {
        ASTTree[ctx] = ASTTree[ctx->constant()];
    }
    
    void enterBinaryExpr(antlrcpptest::MParser::BinaryExprContext * /*ctx*/) override { }
    void exitBinaryExpr(antlrcpptest::MParser::BinaryExprContext * ctx) override {
        BinaryExpr::BinaryOp op;
        switch (ctx->op->getType()) {
            case antlrcpptest::MParser::Star:
                op = BinaryExpr::MUL;
                break;
            case antlrcpptest::MParser::Div:
                op = BinaryExpr::DIV;
                break;
            case antlrcpptest::MParser::Mod:
                op = BinaryExpr::MOD;
                break;
            case antlrcpptest::MParser::Plus:
                op = BinaryExpr::ADD;
                break;
            case antlrcpptest::MParser::Minus:
                op = BinaryExpr::SUB;
                break;
            case antlrcpptest::MParser::LeftShift:
                op = BinaryExpr::SHL;
                break;
            case antlrcpptest::MParser::RightShift:
                op = BinaryExpr::SHR;
                break;
            case antlrcpptest::MParser::Less:
                op = BinaryExpr::LT;
                break;
            case antlrcpptest::MParser::Greater:
                op = BinaryExpr::GT;
                break;
            case antlrcpptest::MParser::LessEqual:
                op = BinaryExpr::LE;
                break;
            case antlrcpptest::MParser::GreaterEqual:
                op = BinaryExpr::GE;
                break;
            case antlrcpptest::MParser::Equal:
                op = BinaryExpr::EQ;
                break;
            case antlrcpptest::MParser::NotEqual:
                op = BinaryExpr::NE;
                break;
            case antlrcpptest::MParser::And:
                op = BinaryExpr::BITWISE_AND;
                break;
            case antlrcpptest::MParser::Caret:
                op = BinaryExpr::XOR;
                break;
            case antlrcpptest::MParser::Or:
                op = BinaryExpr::BITWISE_OR;
                break;
            case antlrcpptest::MParser::AndAnd:
                op = BinaryExpr::LOGICAL_AND;
                break;
            case antlrcpptest::MParser::OrOr:
                op = BinaryExpr::LOGICAL_OR;
                break;
            case antlrcpptest::MParser::Assign:
                op = BinaryExpr::ASSIGN;
                break;
            default:
                throw(0);
                break;
        }
        std::shared_ptr<ASTNode> ptr(new BinaryExpr(op));
        std::vector<std::shared_ptr<ASTNode>> vec;
        vec.push_back(ASTTree[ctx->expression()[0]]);
        vec.push_back(ASTTree[ctx->expression()[1]]);
        ptr->accept(vec);
        ASTTree[ctx] = ptr;
//        std::cout<<ctx->expression()[0]->getText()<<std::endl;
//        std::cout<<ctx->expression()[1]->getText()<<std::endl;
    }
    
    void enterSubscript(antlrcpptest::MParser::SubscriptContext * /*ctx*/) override { }
    void exitSubscript(antlrcpptest::MParser::SubscriptContext * ctx) override {
        std::shared_ptr<ASTNode> ptr(new ArrayAccess());
        std::vector<std::shared_ptr<ASTNode>> vec;
        vec.push_back(ASTTree[ctx->expression()[0]]);
        vec.push_back(ASTTree[ctx->expression()[1]]);
        ptr->accept(vec);
        ASTTree[ctx] = ptr;
//        std::cout<<ctx->expression()[0]->getText()<<std::endl<<ctx->expression()[1]->getText()<<std::endl;
    }
    
    void enterFunctionCall(antlrcpptest::MParser::FunctionCallContext * /*ctx*/) override { }
    void exitFunctionCall(antlrcpptest::MParser::FunctionCallContext * ctx) override {
        std::shared_ptr<ASTNode> ptr(new FunctionCall());
        std::vector<std::shared_ptr<ASTNode>> vec;
        vec.push_back(ASTTree[ctx->expression()]);
        if(ctx->parameterList() != NULL) {
            for(int i = 0; i < ctx->parameterList()->expression().size(); ++i) {
                vec.push_back(ASTTree[ctx->parameterList()->expression()[i]]);
            }
        }
        ptr->accept(vec);
        ASTTree[ctx] = ptr;
//        std::cout<<ctx->expression()->getText()<<std::endl;
    }
    
    void enterPostfixIncDec(antlrcpptest::MParser::PostfixIncDecContext * /*ctx*/) override { }
    void exitPostfixIncDec(antlrcpptest::MParser::PostfixIncDecContext * ctx) override {
//        std::cout<<ctx->expression()->getText()<<std::endl;
        if (ctx->op->getType() == antlrcpptest::MParser::PlusPlus){
            std::shared_ptr<ASTNode> ptr(new SelfIncrement());
            std::vector<std::shared_ptr<ASTNode>> vec;
            vec.push_back(ASTTree[ctx->expression()]);
            ptr -> accept(vec);
            ASTTree[ctx] = ptr;
        }
        else {
            std::shared_ptr<ASTNode> ptr(new SelfDecrement());
            std::vector<std::shared_ptr<ASTNode>> vec;
            vec.push_back(ASTTree[ctx->expression()]);
            ptr -> accept(vec);
            ASTTree[ctx] = ptr;
        }
    }
    
    void enterUnaryExpr(antlrcpptest::MParser::UnaryExprContext * /*ctx*/) override { }
    void exitUnaryExpr(antlrcpptest::MParser::UnaryExprContext * ctx) override {
        UnaryExpr::UnaryOp op;
        switch (ctx->op->getType()) {
            case antlrcpptest::MParser::PlusPlus:
                op = UnaryExpr::INC;
                break;
            case antlrcpptest::MParser::MinusMinus:
                op = UnaryExpr::DEC;
                break;
            case antlrcpptest::MParser::Plus:
                op = UnaryExpr::POS;
                break;
            case antlrcpptest::MParser::Minus:
                op = UnaryExpr::NEG;
                break;
            case antlrcpptest::MParser::Not:
                op = UnaryExpr::LOGICAL_NOT;
                break;
            case antlrcpptest::MParser::Tilde:
                op = UnaryExpr::BITWISE_NOT;
                break;
            default:
                throw(0);
                break;
        }
        std::shared_ptr<ASTNode> ptr(new UnaryExpr(op));
        std::vector<std::shared_ptr<ASTNode>> vec;
        vec.push_back(ASTTree[ctx->expression()]);
        ptr->accept(vec);
        ASTTree[ctx] = ptr;
//        std::cout<<ctx->expression()->getText()<<std::endl;
//        std::cout<<ctx->op->getType()<<std::endl;
    }
    
    void enterSubExpression(antlrcpptest::MParser::SubExpressionContext * /*ctx*/) override { }
    void exitSubExpression(antlrcpptest::MParser::SubExpressionContext * ctx) override {
        ASTTree[ctx] = ASTTree[ctx->expression()];
    }
    
    void enterCreatorError(antlrcpptest::MParser::CreatorErrorContext * /*ctx*/) override { }
    void exitCreatorError(antlrcpptest::MParser::CreatorErrorContext * /*ctx*/) override {
        throw(0);
    }
    
    void enterCreatorArray(antlrcpptest::MParser::CreatorArrayContext * /*ctx*/) override { }
    void exitCreatorArray(antlrcpptest::MParser::CreatorArrayContext * ctx) override {
        std::shared_ptr<ASTNode> ptr(new NewExpr());
        std::vector<std::shared_ptr<ASTNode>> vec;
        vec.push_back(ASTTree[ctx->nonArrayTypeSpecifier()]);
//        std::cout<<ctx->lbr().size()<<std::endl;
        for(int i = 0; i < ctx->expression().size(); ++i) {
//            std::cout<<ctx->expression()[i]->getText()<<std::endl;
            vec.push_back(ASTTree[ctx->expression()[i]]);
        }
        for(int i = 0; i < ctx->lbr().size(); ++i){
            vec.push_back(NULL);
        }
        ptr->accept(vec);
        ASTTree[ctx] = ptr;
    }
    
    void enterCreatorNonArray(antlrcpptest::MParser::CreatorNonArrayContext * /*ctx*/) override { }
    void exitCreatorNonArray(antlrcpptest::MParser::CreatorNonArrayContext * ctx) override {
        std::shared_ptr<ASTNode> ptr(new NewExpr());
        std::vector<std::shared_ptr<ASTNode>> vec;
        vec.push_back(ASTTree[ctx->nonArrayTypeSpecifier()]);
        ptr->accept(vec);
        ASTTree[ctx] = ptr;
    }
    
    void enterParameterList(antlrcpptest::MParser::ParameterListContext * /*ctx*/) override { }
    void exitParameterList(antlrcpptest::MParser::ParameterListContext * /*ctx*/) override { }
    
    void enterConstant(antlrcpptest::MParser::ConstantContext * /*ctx*/) override { }
    void exitConstant(antlrcpptest::MParser::ConstantContext * ctx) override {
        std::string s = ctx -> type -> getText();
        size_t type = ctx -> type -> getType();
        if(type == antlrcpptest::MParser::IntegerConstant){
            std::shared_ptr<ASTNode> ptr(new IntConst(std::atoi(s.c_str())));
            ASTTree[ctx] = ptr;
        }
        else if(type == antlrcpptest::MParser::NullLiteral){
            std::shared_ptr<ASTNode> ptr(new NullLiteral());
            ASTTree[ctx] = ptr;
        }
        else if(type == antlrcpptest::MParser::BoolConstant){
            std::shared_ptr<ASTNode> ptr(new BoolConst(s == "true"));
            ASTTree[ctx] = ptr;
        }
        else if(type == antlrcpptest::MParser::StringLiteral){
            s = s.substr(1, s.size() - 2);
            std::shared_ptr<ASTNode> ptr(new StringConst());
            ptr->acceptStr(s);
//            std::cout<<s<<std::endl;
            ASTTree[ctx] = ptr;
        }
        else{
            throw(0);
        }
        
    }
    
    
    void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
    void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
    void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
    void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }
    
}; // namespace antlrcpptest
