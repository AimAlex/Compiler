
// Generated from M.g4 by ANTLR 4.7.1


#include "MListener.h"
#include "MVisitor.h"

#include "MParser.h"


using namespace antlrcpp;
using namespace antlrcpptest;
using namespace antlr4;

MParser::MParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

MParser::~MParser() {
  delete _interpreter;
}

std::string MParser::getGrammarFileName() const {
  return "M.g4";
}

const std::vector<std::string>& MParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& MParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

MParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MParser::ProgramContext::EOF() {
  return getToken(MParser::EOF, 0);
}

std::vector<MParser::ProgramSectionContext *> MParser::ProgramContext::programSection() {
  return getRuleContexts<MParser::ProgramSectionContext>();
}

MParser::ProgramSectionContext* MParser::ProgramContext::programSection(size_t i) {
  return getRuleContext<MParser::ProgramSectionContext>(i);
}


size_t MParser::ProgramContext::getRuleIndex() const {
  return MParser::RuleProgram;
}

void MParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void MParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


antlrcpp::Any MParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

MParser::ProgramContext* MParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, MParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(49);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MParser::Bool)
      | (1ULL << MParser::Int)
      | (1ULL << MParser::Void)
      | (1ULL << MParser::String)
      | (1ULL << MParser::Class)
      | (1ULL << MParser::Identifier))) != 0)) {
      setState(46);
      programSection();
      setState(51);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(52);
    match(MParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramSectionContext ------------------------------------------------------------------

MParser::ProgramSectionContext::ProgramSectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MParser::ClassDeclarationContext* MParser::ProgramSectionContext::classDeclaration() {
  return getRuleContext<MParser::ClassDeclarationContext>(0);
}

MParser::FunctionDeclarationContext* MParser::ProgramSectionContext::functionDeclaration() {
  return getRuleContext<MParser::FunctionDeclarationContext>(0);
}

MParser::VariableDeclarationContext* MParser::ProgramSectionContext::variableDeclaration() {
  return getRuleContext<MParser::VariableDeclarationContext>(0);
}


size_t MParser::ProgramSectionContext::getRuleIndex() const {
  return MParser::RuleProgramSection;
}

void MParser::ProgramSectionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgramSection(this);
}

void MParser::ProgramSectionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgramSection(this);
}


antlrcpp::Any MParser::ProgramSectionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MVisitor*>(visitor))
    return parserVisitor->visitProgramSection(this);
  else
    return visitor->visitChildren(this);
}

MParser::ProgramSectionContext* MParser::programSection() {
  ProgramSectionContext *_localctx = _tracker.createInstance<ProgramSectionContext>(_ctx, getState());
  enterRule(_localctx, 2, MParser::RuleProgramSection);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(57);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(54);
      classDeclaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(55);
      functionDeclaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(56);
      variableDeclaration();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

MParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MParser::BlockStatementContext* MParser::StatementContext::blockStatement() {
  return getRuleContext<MParser::BlockStatementContext>(0);
}

MParser::ExpressionStatementContext* MParser::StatementContext::expressionStatement() {
  return getRuleContext<MParser::ExpressionStatementContext>(0);
}

MParser::SelectionStatementContext* MParser::StatementContext::selectionStatement() {
  return getRuleContext<MParser::SelectionStatementContext>(0);
}

MParser::IterationStatementContext* MParser::StatementContext::iterationStatement() {
  return getRuleContext<MParser::IterationStatementContext>(0);
}

MParser::JumpStatementContext* MParser::StatementContext::jumpStatement() {
  return getRuleContext<MParser::JumpStatementContext>(0);
}


size_t MParser::StatementContext::getRuleIndex() const {
  return MParser::RuleStatement;
}

void MParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void MParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


antlrcpp::Any MParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

MParser::StatementContext* MParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 4, MParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(64);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MParser::LBrace: {
        enterOuterAlt(_localctx, 1);
        setState(59);
        blockStatement();
        break;
      }

      case MParser::New:
      case MParser::Plus:
      case MParser::Minus:
      case MParser::Not:
      case MParser::Tilde:
      case MParser::PlusPlus:
      case MParser::MinusMinus:
      case MParser::LParen:
      case MParser::Semi:
      case MParser::NullLiteral:
      case MParser::BoolConstant:
      case MParser::IntegerConstant:
      case MParser::CharacterConstant:
      case MParser::StringLiteral:
      case MParser::Identifier: {
        enterOuterAlt(_localctx, 2);
        setState(60);
        expressionStatement();
        break;
      }

      case MParser::If: {
        enterOuterAlt(_localctx, 3);
        setState(61);
        selectionStatement();
        break;
      }

      case MParser::For:
      case MParser::While: {
        enterOuterAlt(_localctx, 4);
        setState(62);
        iterationStatement();
        break;
      }

      case MParser::Break:
      case MParser::Continue:
      case MParser::Return: {
        enterOuterAlt(_localctx, 5);
        setState(63);
        jumpStatement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockStatementContext ------------------------------------------------------------------

MParser::BlockStatementContext::BlockStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MParser::BlockItemContext *> MParser::BlockStatementContext::blockItem() {
  return getRuleContexts<MParser::BlockItemContext>();
}

MParser::BlockItemContext* MParser::BlockStatementContext::blockItem(size_t i) {
  return getRuleContext<MParser::BlockItemContext>(i);
}


size_t MParser::BlockStatementContext::getRuleIndex() const {
  return MParser::RuleBlockStatement;
}

void MParser::BlockStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockStatement(this);
}

void MParser::BlockStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockStatement(this);
}


antlrcpp::Any MParser::BlockStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MVisitor*>(visitor))
    return parserVisitor->visitBlockStatement(this);
  else
    return visitor->visitChildren(this);
}

MParser::BlockStatementContext* MParser::blockStatement() {
  BlockStatementContext *_localctx = _tracker.createInstance<BlockStatementContext>(_ctx, getState());
  enterRule(_localctx, 6, MParser::RuleBlockStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(66);
    match(MParser::LBrace);
    setState(70);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MParser::Bool)
      | (1ULL << MParser::Int)
      | (1ULL << MParser::Void)
      | (1ULL << MParser::String)
      | (1ULL << MParser::If)
      | (1ULL << MParser::For)
      | (1ULL << MParser::While)
      | (1ULL << MParser::Break)
      | (1ULL << MParser::Continue)
      | (1ULL << MParser::Return)
      | (1ULL << MParser::New)
      | (1ULL << MParser::Plus)
      | (1ULL << MParser::Minus)
      | (1ULL << MParser::Not)
      | (1ULL << MParser::Tilde)
      | (1ULL << MParser::PlusPlus)
      | (1ULL << MParser::MinusMinus)
      | (1ULL << MParser::LParen)
      | (1ULL << MParser::LBrace)
      | (1ULL << MParser::Semi)
      | (1ULL << MParser::NullLiteral)
      | (1ULL << MParser::BoolConstant)
      | (1ULL << MParser::IntegerConstant)
      | (1ULL << MParser::CharacterConstant)
      | (1ULL << MParser::StringLiteral)
      | (1ULL << MParser::Identifier))) != 0)) {
      setState(67);
      blockItem();
      setState(72);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(73);
    match(MParser::RBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockItemContext ------------------------------------------------------------------

MParser::BlockItemContext::BlockItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MParser::VariableDeclarationContext* MParser::BlockItemContext::variableDeclaration() {
  return getRuleContext<MParser::VariableDeclarationContext>(0);
}

MParser::StatementContext* MParser::BlockItemContext::statement() {
  return getRuleContext<MParser::StatementContext>(0);
}


size_t MParser::BlockItemContext::getRuleIndex() const {
  return MParser::RuleBlockItem;
}

void MParser::BlockItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockItem(this);
}

void MParser::BlockItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockItem(this);
}


antlrcpp::Any MParser::BlockItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MVisitor*>(visitor))
    return parserVisitor->visitBlockItem(this);
  else
    return visitor->visitChildren(this);
}

MParser::BlockItemContext* MParser::blockItem() {
  BlockItemContext *_localctx = _tracker.createInstance<BlockItemContext>(_ctx, getState());
  enterRule(_localctx, 8, MParser::RuleBlockItem);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(77);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(75);
      variableDeclaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(76);
      statement();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionStatementContext ------------------------------------------------------------------

MParser::ExpressionStatementContext::ExpressionStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MParser::ExpressionContext* MParser::ExpressionStatementContext::expression() {
  return getRuleContext<MParser::ExpressionContext>(0);
}


size_t MParser::ExpressionStatementContext::getRuleIndex() const {
  return MParser::RuleExpressionStatement;
}

void MParser::ExpressionStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionStatement(this);
}

void MParser::ExpressionStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionStatement(this);
}


antlrcpp::Any MParser::ExpressionStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MVisitor*>(visitor))
    return parserVisitor->visitExpressionStatement(this);
  else
    return visitor->visitChildren(this);
}

MParser::ExpressionStatementContext* MParser::expressionStatement() {
  ExpressionStatementContext *_localctx = _tracker.createInstance<ExpressionStatementContext>(_ctx, getState());
  enterRule(_localctx, 10, MParser::RuleExpressionStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(80);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MParser::New)
      | (1ULL << MParser::Plus)
      | (1ULL << MParser::Minus)
      | (1ULL << MParser::Not)
      | (1ULL << MParser::Tilde)
      | (1ULL << MParser::PlusPlus)
      | (1ULL << MParser::MinusMinus)
      | (1ULL << MParser::LParen)
      | (1ULL << MParser::NullLiteral)
      | (1ULL << MParser::BoolConstant)
      | (1ULL << MParser::IntegerConstant)
      | (1ULL << MParser::CharacterConstant)
      | (1ULL << MParser::StringLiteral)
      | (1ULL << MParser::Identifier))) != 0)) {
      setState(79);
      expression(0);
    }
    setState(82);
    match(MParser::Semi);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SelectionStatementContext ------------------------------------------------------------------

MParser::SelectionStatementContext::SelectionStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MParser::ExpressionContext* MParser::SelectionStatementContext::expression() {
  return getRuleContext<MParser::ExpressionContext>(0);
}

std::vector<MParser::StatementContext *> MParser::SelectionStatementContext::statement() {
  return getRuleContexts<MParser::StatementContext>();
}

MParser::StatementContext* MParser::SelectionStatementContext::statement(size_t i) {
  return getRuleContext<MParser::StatementContext>(i);
}


size_t MParser::SelectionStatementContext::getRuleIndex() const {
  return MParser::RuleSelectionStatement;
}

void MParser::SelectionStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelectionStatement(this);
}

void MParser::SelectionStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelectionStatement(this);
}


antlrcpp::Any MParser::SelectionStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MVisitor*>(visitor))
    return parserVisitor->visitSelectionStatement(this);
  else
    return visitor->visitChildren(this);
}

MParser::SelectionStatementContext* MParser::selectionStatement() {
  SelectionStatementContext *_localctx = _tracker.createInstance<SelectionStatementContext>(_ctx, getState());
  enterRule(_localctx, 12, MParser::RuleSelectionStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(84);
    match(MParser::If);
    setState(85);
    match(MParser::LParen);
    setState(86);
    expression(0);
    setState(87);
    match(MParser::RParen);
    setState(88);
    statement();
    setState(91);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      setState(89);
      match(MParser::T__0);
      setState(90);
      statement();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IterationStatementContext ------------------------------------------------------------------

MParser::IterationStatementContext::IterationStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MParser::ExpressionContext *> MParser::IterationStatementContext::expression() {
  return getRuleContexts<MParser::ExpressionContext>();
}

MParser::ExpressionContext* MParser::IterationStatementContext::expression(size_t i) {
  return getRuleContext<MParser::ExpressionContext>(i);
}

MParser::StatementContext* MParser::IterationStatementContext::statement() {
  return getRuleContext<MParser::StatementContext>(0);
}

MParser::VariableDeclarationContext* MParser::IterationStatementContext::variableDeclaration() {
  return getRuleContext<MParser::VariableDeclarationContext>(0);
}


size_t MParser::IterationStatementContext::getRuleIndex() const {
  return MParser::RuleIterationStatement;
}

void MParser::IterationStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIterationStatement(this);
}

void MParser::IterationStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIterationStatement(this);
}


antlrcpp::Any MParser::IterationStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MVisitor*>(visitor))
    return parserVisitor->visitIterationStatement(this);
  else
    return visitor->visitChildren(this);
}

MParser::IterationStatementContext* MParser::iterationStatement() {
  IterationStatementContext *_localctx = _tracker.createInstance<IterationStatementContext>(_ctx, getState());
  enterRule(_localctx, 14, MParser::RuleIterationStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(127);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(93);
      match(MParser::While);
      setState(94);
      match(MParser::LParen);
      setState(95);
      expression(0);
      setState(96);
      match(MParser::RParen);
      setState(97);
      statement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(99);
      match(MParser::For);
      setState(100);
      match(MParser::LParen);
      setState(101);
      dynamic_cast<IterationStatementContext *>(_localctx)->declinit = variableDeclaration();
      setState(103);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MParser::New)
        | (1ULL << MParser::Plus)
        | (1ULL << MParser::Minus)
        | (1ULL << MParser::Not)
        | (1ULL << MParser::Tilde)
        | (1ULL << MParser::PlusPlus)
        | (1ULL << MParser::MinusMinus)
        | (1ULL << MParser::LParen)
        | (1ULL << MParser::NullLiteral)
        | (1ULL << MParser::BoolConstant)
        | (1ULL << MParser::IntegerConstant)
        | (1ULL << MParser::CharacterConstant)
        | (1ULL << MParser::StringLiteral)
        | (1ULL << MParser::Identifier))) != 0)) {
        setState(102);
        dynamic_cast<IterationStatementContext *>(_localctx)->cond = expression(0);
      }
      setState(105);
      match(MParser::Semi);
      setState(107);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MParser::New)
        | (1ULL << MParser::Plus)
        | (1ULL << MParser::Minus)
        | (1ULL << MParser::Not)
        | (1ULL << MParser::Tilde)
        | (1ULL << MParser::PlusPlus)
        | (1ULL << MParser::MinusMinus)
        | (1ULL << MParser::LParen)
        | (1ULL << MParser::NullLiteral)
        | (1ULL << MParser::BoolConstant)
        | (1ULL << MParser::IntegerConstant)
        | (1ULL << MParser::CharacterConstant)
        | (1ULL << MParser::StringLiteral)
        | (1ULL << MParser::Identifier))) != 0)) {
        setState(106);
        dynamic_cast<IterationStatementContext *>(_localctx)->step = expression(0);
      }
      setState(109);
      match(MParser::RParen);
      setState(110);
      statement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(112);
      match(MParser::For);
      setState(113);
      match(MParser::LParen);
      setState(115);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MParser::New)
        | (1ULL << MParser::Plus)
        | (1ULL << MParser::Minus)
        | (1ULL << MParser::Not)
        | (1ULL << MParser::Tilde)
        | (1ULL << MParser::PlusPlus)
        | (1ULL << MParser::MinusMinus)
        | (1ULL << MParser::LParen)
        | (1ULL << MParser::NullLiteral)
        | (1ULL << MParser::BoolConstant)
        | (1ULL << MParser::IntegerConstant)
        | (1ULL << MParser::CharacterConstant)
        | (1ULL << MParser::StringLiteral)
        | (1ULL << MParser::Identifier))) != 0)) {
        setState(114);
        dynamic_cast<IterationStatementContext *>(_localctx)->init = expression(0);
      }
      setState(117);
      match(MParser::Semi);
      setState(119);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MParser::New)
        | (1ULL << MParser::Plus)
        | (1ULL << MParser::Minus)
        | (1ULL << MParser::Not)
        | (1ULL << MParser::Tilde)
        | (1ULL << MParser::PlusPlus)
        | (1ULL << MParser::MinusMinus)
        | (1ULL << MParser::LParen)
        | (1ULL << MParser::NullLiteral)
        | (1ULL << MParser::BoolConstant)
        | (1ULL << MParser::IntegerConstant)
        | (1ULL << MParser::CharacterConstant)
        | (1ULL << MParser::StringLiteral)
        | (1ULL << MParser::Identifier))) != 0)) {
        setState(118);
        dynamic_cast<IterationStatementContext *>(_localctx)->cond = expression(0);
      }
      setState(121);
      match(MParser::Semi);
      setState(123);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MParser::New)
        | (1ULL << MParser::Plus)
        | (1ULL << MParser::Minus)
        | (1ULL << MParser::Not)
        | (1ULL << MParser::Tilde)
        | (1ULL << MParser::PlusPlus)
        | (1ULL << MParser::MinusMinus)
        | (1ULL << MParser::LParen)
        | (1ULL << MParser::NullLiteral)
        | (1ULL << MParser::BoolConstant)
        | (1ULL << MParser::IntegerConstant)
        | (1ULL << MParser::CharacterConstant)
        | (1ULL << MParser::StringLiteral)
        | (1ULL << MParser::Identifier))) != 0)) {
        setState(122);
        dynamic_cast<IterationStatementContext *>(_localctx)->step = expression(0);
      }
      setState(125);
      match(MParser::RParen);
      setState(126);
      statement();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- JumpStatementContext ------------------------------------------------------------------

MParser::JumpStatementContext::JumpStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MParser::ExpressionContext* MParser::JumpStatementContext::expression() {
  return getRuleContext<MParser::ExpressionContext>(0);
}


size_t MParser::JumpStatementContext::getRuleIndex() const {
  return MParser::RuleJumpStatement;
}

void MParser::JumpStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterJumpStatement(this);
}

void MParser::JumpStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitJumpStatement(this);
}


antlrcpp::Any MParser::JumpStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MVisitor*>(visitor))
    return parserVisitor->visitJumpStatement(this);
  else
    return visitor->visitChildren(this);
}

MParser::JumpStatementContext* MParser::jumpStatement() {
  JumpStatementContext *_localctx = _tracker.createInstance<JumpStatementContext>(_ctx, getState());
  enterRule(_localctx, 16, MParser::RuleJumpStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(138);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MParser::Continue: {
        enterOuterAlt(_localctx, 1);
        setState(129);
        match(MParser::Continue);
        setState(130);
        match(MParser::Semi);
        break;
      }

      case MParser::Break: {
        enterOuterAlt(_localctx, 2);
        setState(131);
        match(MParser::Break);
        setState(132);
        match(MParser::Semi);
        break;
      }

      case MParser::Return: {
        enterOuterAlt(_localctx, 3);
        setState(133);
        match(MParser::Return);
        setState(135);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << MParser::New)
          | (1ULL << MParser::Plus)
          | (1ULL << MParser::Minus)
          | (1ULL << MParser::Not)
          | (1ULL << MParser::Tilde)
          | (1ULL << MParser::PlusPlus)
          | (1ULL << MParser::MinusMinus)
          | (1ULL << MParser::LParen)
          | (1ULL << MParser::NullLiteral)
          | (1ULL << MParser::BoolConstant)
          | (1ULL << MParser::IntegerConstant)
          | (1ULL << MParser::CharacterConstant)
          | (1ULL << MParser::StringLiteral)
          | (1ULL << MParser::Identifier))) != 0)) {
          setState(134);
          expression(0);
        }
        setState(137);
        match(MParser::Semi);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NonArrayTypeSpecifierContext ------------------------------------------------------------------

MParser::NonArrayTypeSpecifierContext::NonArrayTypeSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MParser::NonArrayTypeSpecifierContext::Identifier() {
  return getToken(MParser::Identifier, 0);
}


size_t MParser::NonArrayTypeSpecifierContext::getRuleIndex() const {
  return MParser::RuleNonArrayTypeSpecifier;
}

void MParser::NonArrayTypeSpecifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNonArrayTypeSpecifier(this);
}

void MParser::NonArrayTypeSpecifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNonArrayTypeSpecifier(this);
}


antlrcpp::Any MParser::NonArrayTypeSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MVisitor*>(visitor))
    return parserVisitor->visitNonArrayTypeSpecifier(this);
  else
    return visitor->visitChildren(this);
}

MParser::NonArrayTypeSpecifierContext* MParser::nonArrayTypeSpecifier() {
  NonArrayTypeSpecifierContext *_localctx = _tracker.createInstance<NonArrayTypeSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 18, MParser::RuleNonArrayTypeSpecifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(145);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MParser::Int: {
        enterOuterAlt(_localctx, 1);
        setState(140);
        dynamic_cast<NonArrayTypeSpecifierContext *>(_localctx)->type = match(MParser::Int);
        break;
      }

      case MParser::Bool: {
        enterOuterAlt(_localctx, 2);
        setState(141);
        dynamic_cast<NonArrayTypeSpecifierContext *>(_localctx)->type = match(MParser::Bool);
        break;
      }

      case MParser::String: {
        enterOuterAlt(_localctx, 3);
        setState(142);
        dynamic_cast<NonArrayTypeSpecifierContext *>(_localctx)->type = match(MParser::String);
        break;
      }

      case MParser::Void: {
        enterOuterAlt(_localctx, 4);
        setState(143);
        dynamic_cast<NonArrayTypeSpecifierContext *>(_localctx)->type = match(MParser::Void);
        break;
      }

      case MParser::Identifier: {
        enterOuterAlt(_localctx, 5);
        setState(144);
        dynamic_cast<NonArrayTypeSpecifierContext *>(_localctx)->type = match(MParser::Identifier);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeSpecifierContext ------------------------------------------------------------------

MParser::TypeSpecifierContext::TypeSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MParser::NonArrayTypeSpecifierContext* MParser::TypeSpecifierContext::nonArrayTypeSpecifier() {
  return getRuleContext<MParser::NonArrayTypeSpecifierContext>(0);
}

MParser::TypeSpecifierContext* MParser::TypeSpecifierContext::typeSpecifier() {
  return getRuleContext<MParser::TypeSpecifierContext>(0);
}


size_t MParser::TypeSpecifierContext::getRuleIndex() const {
  return MParser::RuleTypeSpecifier;
}

void MParser::TypeSpecifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeSpecifier(this);
}

void MParser::TypeSpecifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeSpecifier(this);
}


antlrcpp::Any MParser::TypeSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MVisitor*>(visitor))
    return parserVisitor->visitTypeSpecifier(this);
  else
    return visitor->visitChildren(this);
}


MParser::TypeSpecifierContext* MParser::typeSpecifier() {
   return typeSpecifier(0);
}

MParser::TypeSpecifierContext* MParser::typeSpecifier(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MParser::TypeSpecifierContext *_localctx = _tracker.createInstance<TypeSpecifierContext>(_ctx, parentState);
  MParser::TypeSpecifierContext *previousContext = _localctx;
  size_t startState = 20;
  enterRecursionRule(_localctx, 20, MParser::RuleTypeSpecifier, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(148);
    nonArrayTypeSpecifier();
    _ctx->stop = _input->LT(-1);
    setState(155);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TypeSpecifierContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleTypeSpecifier);
        setState(150);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(151);
        match(MParser::LBracket);
        setState(152);
        match(MParser::RBracket); 
      }
      setState(157);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- VariableDeclarationContext ------------------------------------------------------------------

MParser::VariableDeclarationContext::VariableDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MParser::TypeSpecifierContext* MParser::VariableDeclarationContext::typeSpecifier() {
  return getRuleContext<MParser::TypeSpecifierContext>(0);
}

std::vector<MParser::VariableInitDeclaratorContext *> MParser::VariableDeclarationContext::variableInitDeclarator() {
  return getRuleContexts<MParser::VariableInitDeclaratorContext>();
}

MParser::VariableInitDeclaratorContext* MParser::VariableDeclarationContext::variableInitDeclarator(size_t i) {
  return getRuleContext<MParser::VariableInitDeclaratorContext>(i);
}


size_t MParser::VariableDeclarationContext::getRuleIndex() const {
  return MParser::RuleVariableDeclaration;
}

void MParser::VariableDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableDeclaration(this);
}

void MParser::VariableDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableDeclaration(this);
}


antlrcpp::Any MParser::VariableDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MVisitor*>(visitor))
    return parserVisitor->visitVariableDeclaration(this);
  else
    return visitor->visitChildren(this);
}

MParser::VariableDeclarationContext* MParser::variableDeclaration() {
  VariableDeclarationContext *_localctx = _tracker.createInstance<VariableDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 22, MParser::RuleVariableDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(158);
    typeSpecifier(0);
    setState(159);
    variableInitDeclarator();
    setState(164);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MParser::Comma) {
      setState(160);
      match(MParser::Comma);
      setState(161);
      variableInitDeclarator();
      setState(166);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(167);
    match(MParser::Semi);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableInitDeclaratorContext ------------------------------------------------------------------

MParser::VariableInitDeclaratorContext::VariableInitDeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MParser::VariableInitDeclaratorContext::Identifier() {
  return getToken(MParser::Identifier, 0);
}

MParser::ExpressionContext* MParser::VariableInitDeclaratorContext::expression() {
  return getRuleContext<MParser::ExpressionContext>(0);
}


size_t MParser::VariableInitDeclaratorContext::getRuleIndex() const {
  return MParser::RuleVariableInitDeclarator;
}

void MParser::VariableInitDeclaratorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableInitDeclarator(this);
}

void MParser::VariableInitDeclaratorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableInitDeclarator(this);
}


antlrcpp::Any MParser::VariableInitDeclaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MVisitor*>(visitor))
    return parserVisitor->visitVariableInitDeclarator(this);
  else
    return visitor->visitChildren(this);
}

MParser::VariableInitDeclaratorContext* MParser::variableInitDeclarator() {
  VariableInitDeclaratorContext *_localctx = _tracker.createInstance<VariableInitDeclaratorContext>(_ctx, getState());
  enterRule(_localctx, 24, MParser::RuleVariableInitDeclarator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(169);
    match(MParser::Identifier);
    setState(172);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MParser::Assign) {
      setState(170);
      match(MParser::Assign);
      setState(171);
      expression(0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassDeclarationContext ------------------------------------------------------------------

MParser::ClassDeclarationContext::ClassDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MParser::ClassDeclarationContext::Identifier() {
  return getToken(MParser::Identifier, 0);
}

std::vector<MParser::MemberDeclarationContext *> MParser::ClassDeclarationContext::memberDeclaration() {
  return getRuleContexts<MParser::MemberDeclarationContext>();
}

MParser::MemberDeclarationContext* MParser::ClassDeclarationContext::memberDeclaration(size_t i) {
  return getRuleContext<MParser::MemberDeclarationContext>(i);
}


size_t MParser::ClassDeclarationContext::getRuleIndex() const {
  return MParser::RuleClassDeclaration;
}

void MParser::ClassDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassDeclaration(this);
}

void MParser::ClassDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassDeclaration(this);
}


antlrcpp::Any MParser::ClassDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MVisitor*>(visitor))
    return parserVisitor->visitClassDeclaration(this);
  else
    return visitor->visitChildren(this);
}

MParser::ClassDeclarationContext* MParser::classDeclaration() {
  ClassDeclarationContext *_localctx = _tracker.createInstance<ClassDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 26, MParser::RuleClassDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(174);
    match(MParser::Class);
    setState(175);
    match(MParser::Identifier);
    setState(176);
    match(MParser::LBrace);
    setState(180);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MParser::Bool)
      | (1ULL << MParser::Int)
      | (1ULL << MParser::Void)
      | (1ULL << MParser::String)
      | (1ULL << MParser::Identifier))) != 0)) {
      setState(177);
      memberDeclaration();
      setState(182);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(183);
    match(MParser::RBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MemberDeclarationContext ------------------------------------------------------------------

MParser::MemberDeclarationContext::MemberDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MParser::TypeSpecifierContext* MParser::MemberDeclarationContext::typeSpecifier() {
  return getRuleContext<MParser::TypeSpecifierContext>(0);
}

tree::TerminalNode* MParser::MemberDeclarationContext::Identifier() {
  return getToken(MParser::Identifier, 0);
}

MParser::ClassFunctionDeclarationContext* MParser::MemberDeclarationContext::classFunctionDeclaration() {
  return getRuleContext<MParser::ClassFunctionDeclarationContext>(0);
}


size_t MParser::MemberDeclarationContext::getRuleIndex() const {
  return MParser::RuleMemberDeclaration;
}

void MParser::MemberDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMemberDeclaration(this);
}

void MParser::MemberDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMemberDeclaration(this);
}


antlrcpp::Any MParser::MemberDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MVisitor*>(visitor))
    return parserVisitor->visitMemberDeclaration(this);
  else
    return visitor->visitChildren(this);
}

MParser::MemberDeclarationContext* MParser::memberDeclaration() {
  MemberDeclarationContext *_localctx = _tracker.createInstance<MemberDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 28, MParser::RuleMemberDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(190);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(185);
      typeSpecifier(0);
      setState(186);
      match(MParser::Identifier);
      setState(187);
      match(MParser::Semi);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(189);
      classFunctionDeclaration();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassFunctionDeclarationContext ------------------------------------------------------------------

MParser::ClassFunctionDeclarationContext::ClassFunctionDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MParser::TypeSpecifierContext* MParser::ClassFunctionDeclarationContext::typeSpecifier() {
  return getRuleContext<MParser::TypeSpecifierContext>(0);
}

tree::TerminalNode* MParser::ClassFunctionDeclarationContext::Identifier() {
  return getToken(MParser::Identifier, 0);
}

MParser::BlockStatementContext* MParser::ClassFunctionDeclarationContext::blockStatement() {
  return getRuleContext<MParser::BlockStatementContext>(0);
}

MParser::ParameterDeclarationListContext* MParser::ClassFunctionDeclarationContext::parameterDeclarationList() {
  return getRuleContext<MParser::ParameterDeclarationListContext>(0);
}


size_t MParser::ClassFunctionDeclarationContext::getRuleIndex() const {
  return MParser::RuleClassFunctionDeclaration;
}

void MParser::ClassFunctionDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassFunctionDeclaration(this);
}

void MParser::ClassFunctionDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassFunctionDeclaration(this);
}


antlrcpp::Any MParser::ClassFunctionDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MVisitor*>(visitor))
    return parserVisitor->visitClassFunctionDeclaration(this);
  else
    return visitor->visitChildren(this);
}

MParser::ClassFunctionDeclarationContext* MParser::classFunctionDeclaration() {
  ClassFunctionDeclarationContext *_localctx = _tracker.createInstance<ClassFunctionDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 30, MParser::RuleClassFunctionDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(205);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(192);
      typeSpecifier(0);
      setState(193);
      match(MParser::Identifier);
      setState(194);
      match(MParser::LParen);
      setState(196);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MParser::Bool)
        | (1ULL << MParser::Int)
        | (1ULL << MParser::Void)
        | (1ULL << MParser::String)
        | (1ULL << MParser::Identifier))) != 0)) {
        setState(195);
        parameterDeclarationList();
      }
      setState(198);
      match(MParser::RParen);
      setState(199);
      blockStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(201);
      match(MParser::Identifier);
      setState(202);
      match(MParser::LParen);
      setState(203);
      match(MParser::RParen);
      setState(204);
      blockStatement();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDeclarationContext ------------------------------------------------------------------

MParser::FunctionDeclarationContext::FunctionDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MParser::TypeSpecifierContext* MParser::FunctionDeclarationContext::typeSpecifier() {
  return getRuleContext<MParser::TypeSpecifierContext>(0);
}

tree::TerminalNode* MParser::FunctionDeclarationContext::Identifier() {
  return getToken(MParser::Identifier, 0);
}

MParser::BlockStatementContext* MParser::FunctionDeclarationContext::blockStatement() {
  return getRuleContext<MParser::BlockStatementContext>(0);
}

MParser::ParameterDeclarationListContext* MParser::FunctionDeclarationContext::parameterDeclarationList() {
  return getRuleContext<MParser::ParameterDeclarationListContext>(0);
}


size_t MParser::FunctionDeclarationContext::getRuleIndex() const {
  return MParser::RuleFunctionDeclaration;
}

void MParser::FunctionDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDeclaration(this);
}

void MParser::FunctionDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDeclaration(this);
}


antlrcpp::Any MParser::FunctionDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MVisitor*>(visitor))
    return parserVisitor->visitFunctionDeclaration(this);
  else
    return visitor->visitChildren(this);
}

MParser::FunctionDeclarationContext* MParser::functionDeclaration() {
  FunctionDeclarationContext *_localctx = _tracker.createInstance<FunctionDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 32, MParser::RuleFunctionDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(207);
    typeSpecifier(0);
    setState(208);
    match(MParser::Identifier);
    setState(209);
    match(MParser::LParen);
    setState(211);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MParser::Bool)
      | (1ULL << MParser::Int)
      | (1ULL << MParser::Void)
      | (1ULL << MParser::String)
      | (1ULL << MParser::Identifier))) != 0)) {
      setState(210);
      parameterDeclarationList();
    }
    setState(213);
    match(MParser::RParen);
    setState(214);
    blockStatement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterDeclarationListContext ------------------------------------------------------------------

MParser::ParameterDeclarationListContext::ParameterDeclarationListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MParser::ParameterDeclarationContext *> MParser::ParameterDeclarationListContext::parameterDeclaration() {
  return getRuleContexts<MParser::ParameterDeclarationContext>();
}

MParser::ParameterDeclarationContext* MParser::ParameterDeclarationListContext::parameterDeclaration(size_t i) {
  return getRuleContext<MParser::ParameterDeclarationContext>(i);
}


size_t MParser::ParameterDeclarationListContext::getRuleIndex() const {
  return MParser::RuleParameterDeclarationList;
}

void MParser::ParameterDeclarationListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterDeclarationList(this);
}

void MParser::ParameterDeclarationListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterDeclarationList(this);
}


antlrcpp::Any MParser::ParameterDeclarationListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MVisitor*>(visitor))
    return parserVisitor->visitParameterDeclarationList(this);
  else
    return visitor->visitChildren(this);
}

MParser::ParameterDeclarationListContext* MParser::parameterDeclarationList() {
  ParameterDeclarationListContext *_localctx = _tracker.createInstance<ParameterDeclarationListContext>(_ctx, getState());
  enterRule(_localctx, 34, MParser::RuleParameterDeclarationList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(216);
    parameterDeclaration();
    setState(221);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MParser::Comma) {
      setState(217);
      match(MParser::Comma);
      setState(218);
      parameterDeclaration();
      setState(223);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterDeclarationContext ------------------------------------------------------------------

MParser::ParameterDeclarationContext::ParameterDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MParser::TypeSpecifierContext* MParser::ParameterDeclarationContext::typeSpecifier() {
  return getRuleContext<MParser::TypeSpecifierContext>(0);
}

tree::TerminalNode* MParser::ParameterDeclarationContext::Identifier() {
  return getToken(MParser::Identifier, 0);
}


size_t MParser::ParameterDeclarationContext::getRuleIndex() const {
  return MParser::RuleParameterDeclaration;
}

void MParser::ParameterDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterDeclaration(this);
}

void MParser::ParameterDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterDeclaration(this);
}


antlrcpp::Any MParser::ParameterDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MVisitor*>(visitor))
    return parserVisitor->visitParameterDeclaration(this);
  else
    return visitor->visitChildren(this);
}

MParser::ParameterDeclarationContext* MParser::parameterDeclaration() {
  ParameterDeclarationContext *_localctx = _tracker.createInstance<ParameterDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 36, MParser::RuleParameterDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(224);
    typeSpecifier(0);
    setState(225);
    match(MParser::Identifier);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

MParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MParser::ExpressionContext::getRuleIndex() const {
  return MParser::RuleExpression;
}

void MParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- NewContext ------------------------------------------------------------------

MParser::CreatorContext* MParser::NewContext::creator() {
  return getRuleContext<MParser::CreatorContext>(0);
}

MParser::NewContext::NewContext(ExpressionContext *ctx) { copyFrom(ctx); }

void MParser::NewContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNew(this);
}
void MParser::NewContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNew(this);
}

antlrcpp::Any MParser::NewContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MVisitor*>(visitor))
    return parserVisitor->visitNew(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdentifierContext ------------------------------------------------------------------

tree::TerminalNode* MParser::IdentifierContext::Identifier() {
  return getToken(MParser::Identifier, 0);
}

MParser::IdentifierContext::IdentifierContext(ExpressionContext *ctx) { copyFrom(ctx); }

void MParser::IdentifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifier(this);
}
void MParser::IdentifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifier(this);
}

antlrcpp::Any MParser::IdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MVisitor*>(visitor))
    return parserVisitor->visitIdentifier(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MemberAccessContext ------------------------------------------------------------------

MParser::ExpressionContext* MParser::MemberAccessContext::expression() {
  return getRuleContext<MParser::ExpressionContext>(0);
}

tree::TerminalNode* MParser::MemberAccessContext::Identifier() {
  return getToken(MParser::Identifier, 0);
}

MParser::MemberAccessContext::MemberAccessContext(ExpressionContext *ctx) { copyFrom(ctx); }

void MParser::MemberAccessContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMemberAccess(this);
}
void MParser::MemberAccessContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMemberAccess(this);
}

antlrcpp::Any MParser::MemberAccessContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MVisitor*>(visitor))
    return parserVisitor->visitMemberAccess(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LiteralContext ------------------------------------------------------------------

MParser::ConstantContext* MParser::LiteralContext::constant() {
  return getRuleContext<MParser::ConstantContext>(0);
}

MParser::LiteralContext::LiteralContext(ExpressionContext *ctx) { copyFrom(ctx); }

void MParser::LiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteral(this);
}
void MParser::LiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteral(this);
}

antlrcpp::Any MParser::LiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MVisitor*>(visitor))
    return parserVisitor->visitLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BinaryExprContext ------------------------------------------------------------------

std::vector<MParser::ExpressionContext *> MParser::BinaryExprContext::expression() {
  return getRuleContexts<MParser::ExpressionContext>();
}

MParser::ExpressionContext* MParser::BinaryExprContext::expression(size_t i) {
  return getRuleContext<MParser::ExpressionContext>(i);
}

MParser::BinaryExprContext::BinaryExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void MParser::BinaryExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinaryExpr(this);
}
void MParser::BinaryExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinaryExpr(this);
}

antlrcpp::Any MParser::BinaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MVisitor*>(visitor))
    return parserVisitor->visitBinaryExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SubscriptContext ------------------------------------------------------------------

std::vector<MParser::ExpressionContext *> MParser::SubscriptContext::expression() {
  return getRuleContexts<MParser::ExpressionContext>();
}

MParser::ExpressionContext* MParser::SubscriptContext::expression(size_t i) {
  return getRuleContext<MParser::ExpressionContext>(i);
}

MParser::SubscriptContext::SubscriptContext(ExpressionContext *ctx) { copyFrom(ctx); }

void MParser::SubscriptContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubscript(this);
}
void MParser::SubscriptContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubscript(this);
}

antlrcpp::Any MParser::SubscriptContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MVisitor*>(visitor))
    return parserVisitor->visitSubscript(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunctionCallContext ------------------------------------------------------------------

MParser::ExpressionContext* MParser::FunctionCallContext::expression() {
  return getRuleContext<MParser::ExpressionContext>(0);
}

MParser::ParameterListContext* MParser::FunctionCallContext::parameterList() {
  return getRuleContext<MParser::ParameterListContext>(0);
}

MParser::FunctionCallContext::FunctionCallContext(ExpressionContext *ctx) { copyFrom(ctx); }

void MParser::FunctionCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCall(this);
}
void MParser::FunctionCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCall(this);
}

antlrcpp::Any MParser::FunctionCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MVisitor*>(visitor))
    return parserVisitor->visitFunctionCall(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PostfixIncDecContext ------------------------------------------------------------------

MParser::ExpressionContext* MParser::PostfixIncDecContext::expression() {
  return getRuleContext<MParser::ExpressionContext>(0);
}

MParser::PostfixIncDecContext::PostfixIncDecContext(ExpressionContext *ctx) { copyFrom(ctx); }

void MParser::PostfixIncDecContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPostfixIncDec(this);
}
void MParser::PostfixIncDecContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPostfixIncDec(this);
}

antlrcpp::Any MParser::PostfixIncDecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MVisitor*>(visitor))
    return parserVisitor->visitPostfixIncDec(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnaryExprContext ------------------------------------------------------------------

MParser::ExpressionContext* MParser::UnaryExprContext::expression() {
  return getRuleContext<MParser::ExpressionContext>(0);
}

MParser::UnaryExprContext::UnaryExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void MParser::UnaryExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryExpr(this);
}
void MParser::UnaryExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryExpr(this);
}

antlrcpp::Any MParser::UnaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MVisitor*>(visitor))
    return parserVisitor->visitUnaryExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SubExpressionContext ------------------------------------------------------------------

MParser::ExpressionContext* MParser::SubExpressionContext::expression() {
  return getRuleContext<MParser::ExpressionContext>(0);
}

MParser::SubExpressionContext::SubExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

void MParser::SubExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubExpression(this);
}
void MParser::SubExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubExpression(this);
}

antlrcpp::Any MParser::SubExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MVisitor*>(visitor))
    return parserVisitor->visitSubExpression(this);
  else
    return visitor->visitChildren(this);
}

MParser::ExpressionContext* MParser::expression() {
   return expression(0);
}

MParser::ExpressionContext* MParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  MParser::ExpressionContext *previousContext = _localctx;
  size_t startState = 38;
  enterRecursionRule(_localctx, 38, MParser::RuleExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(242);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MParser::PlusPlus:
      case MParser::MinusMinus: {
        _localctx = _tracker.createInstance<UnaryExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(228);
        dynamic_cast<UnaryExprContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == MParser::PlusPlus

        || _la == MParser::MinusMinus)) {
          dynamic_cast<UnaryExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(229);
        expression(19);
        break;
      }

      case MParser::Plus:
      case MParser::Minus: {
        _localctx = _tracker.createInstance<UnaryExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(230);
        dynamic_cast<UnaryExprContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == MParser::Plus

        || _la == MParser::Minus)) {
          dynamic_cast<UnaryExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(231);
        expression(18);
        break;
      }

      case MParser::Not:
      case MParser::Tilde: {
        _localctx = _tracker.createInstance<UnaryExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(232);
        dynamic_cast<UnaryExprContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == MParser::Not

        || _la == MParser::Tilde)) {
          dynamic_cast<UnaryExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(233);
        expression(17);
        break;
      }

      case MParser::New: {
        _localctx = _tracker.createInstance<NewContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(234);
        match(MParser::New);
        setState(235);
        creator();
        break;
      }

      case MParser::Identifier: {
        _localctx = _tracker.createInstance<IdentifierContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(236);
        match(MParser::Identifier);
        break;
      }

      case MParser::NullLiteral:
      case MParser::BoolConstant:
      case MParser::IntegerConstant:
      case MParser::CharacterConstant:
      case MParser::StringLiteral: {
        _localctx = _tracker.createInstance<LiteralContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(237);
        constant();
        break;
      }

      case MParser::LParen: {
        _localctx = _tracker.createInstance<SubExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(238);
        match(MParser::LParen);
        setState(239);
        expression(0);
        setState(240);
        match(MParser::RParen);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(298);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(296);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(244);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(245);
          dynamic_cast<BinaryExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << MParser::Star)
            | (1ULL << MParser::Div)
            | (1ULL << MParser::Mod))) != 0))) {
            dynamic_cast<BinaryExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(246);
          expression(16);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(247);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(248);
          dynamic_cast<BinaryExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MParser::Plus

          || _la == MParser::Minus)) {
            dynamic_cast<BinaryExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(249);
          expression(15);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(250);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(251);
          dynamic_cast<BinaryExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MParser::LeftShift

          || _la == MParser::RightShift)) {
            dynamic_cast<BinaryExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(252);
          expression(14);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(253);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(254);
          dynamic_cast<BinaryExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MParser::Less

          || _la == MParser::Greater)) {
            dynamic_cast<BinaryExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(255);
          expression(13);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(256);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(257);
          dynamic_cast<BinaryExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MParser::GreaterEqual

          || _la == MParser::LessEqual)) {
            dynamic_cast<BinaryExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(258);
          expression(12);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(259);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(260);
          dynamic_cast<BinaryExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MParser::Equal

          || _la == MParser::NotEqual)) {
            dynamic_cast<BinaryExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(261);
          expression(11);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(262);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(263);
          dynamic_cast<BinaryExprContext *>(_localctx)->op = match(MParser::And);
          setState(264);
          expression(10);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(265);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(266);
          dynamic_cast<BinaryExprContext *>(_localctx)->op = match(MParser::Caret);
          setState(267);
          expression(9);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(268);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(269);
          dynamic_cast<BinaryExprContext *>(_localctx)->op = match(MParser::Or);
          setState(270);
          expression(8);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(271);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(272);
          dynamic_cast<BinaryExprContext *>(_localctx)->op = match(MParser::AndAnd);
          setState(273);
          expression(7);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(274);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(275);
          dynamic_cast<BinaryExprContext *>(_localctx)->op = match(MParser::OrOr);
          setState(276);
          expression(6);
          break;
        }

        case 12: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(277);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(278);
          dynamic_cast<BinaryExprContext *>(_localctx)->op = match(MParser::Assign);
          setState(279);
          expression(4);
          break;
        }

        case 13: {
          auto newContext = _tracker.createInstance<PostfixIncDecContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(280);

          if (!(precpred(_ctx, 23))) throw FailedPredicateException(this, "precpred(_ctx, 23)");
          setState(281);
          dynamic_cast<PostfixIncDecContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MParser::PlusPlus

          || _la == MParser::MinusMinus)) {
            dynamic_cast<PostfixIncDecContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          break;
        }

        case 14: {
          auto newContext = _tracker.createInstance<FunctionCallContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(282);

          if (!(precpred(_ctx, 22))) throw FailedPredicateException(this, "precpred(_ctx, 22)");
          setState(283);
          match(MParser::LParen);
          setState(285);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << MParser::New)
            | (1ULL << MParser::Plus)
            | (1ULL << MParser::Minus)
            | (1ULL << MParser::Not)
            | (1ULL << MParser::Tilde)
            | (1ULL << MParser::PlusPlus)
            | (1ULL << MParser::MinusMinus)
            | (1ULL << MParser::LParen)
            | (1ULL << MParser::NullLiteral)
            | (1ULL << MParser::BoolConstant)
            | (1ULL << MParser::IntegerConstant)
            | (1ULL << MParser::CharacterConstant)
            | (1ULL << MParser::StringLiteral)
            | (1ULL << MParser::Identifier))) != 0)) {
            setState(284);
            parameterList();
          }
          setState(287);
          match(MParser::RParen);
          break;
        }

        case 15: {
          auto newContext = _tracker.createInstance<SubscriptContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(288);

          if (!(precpred(_ctx, 21))) throw FailedPredicateException(this, "precpred(_ctx, 21)");
          setState(289);
          match(MParser::LBracket);
          setState(290);
          expression(0);
          setState(291);
          match(MParser::RBracket);
          break;
        }

        case 16: {
          auto newContext = _tracker.createInstance<MemberAccessContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(293);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(294);
          match(MParser::Dot);
          setState(295);
          match(MParser::Identifier);
          break;
        }

        } 
      }
      setState(300);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- CreatorContext ------------------------------------------------------------------

MParser::CreatorContext::CreatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MParser::CreatorContext::getRuleIndex() const {
  return MParser::RuleCreator;
}

void MParser::CreatorContext::copyFrom(CreatorContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- CreatorErrorContext ------------------------------------------------------------------

MParser::NonArrayTypeSpecifierContext* MParser::CreatorErrorContext::nonArrayTypeSpecifier() {
  return getRuleContext<MParser::NonArrayTypeSpecifierContext>(0);
}

std::vector<MParser::ExpressionContext *> MParser::CreatorErrorContext::expression() {
  return getRuleContexts<MParser::ExpressionContext>();
}

MParser::ExpressionContext* MParser::CreatorErrorContext::expression(size_t i) {
  return getRuleContext<MParser::ExpressionContext>(i);
}

MParser::CreatorErrorContext::CreatorErrorContext(CreatorContext *ctx) { copyFrom(ctx); }

void MParser::CreatorErrorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCreatorError(this);
}
void MParser::CreatorErrorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCreatorError(this);
}

antlrcpp::Any MParser::CreatorErrorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MVisitor*>(visitor))
    return parserVisitor->visitCreatorError(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CreatorNonArrayContext ------------------------------------------------------------------

MParser::NonArrayTypeSpecifierContext* MParser::CreatorNonArrayContext::nonArrayTypeSpecifier() {
  return getRuleContext<MParser::NonArrayTypeSpecifierContext>(0);
}

MParser::CreatorNonArrayContext::CreatorNonArrayContext(CreatorContext *ctx) { copyFrom(ctx); }

void MParser::CreatorNonArrayContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCreatorNonArray(this);
}
void MParser::CreatorNonArrayContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCreatorNonArray(this);
}

antlrcpp::Any MParser::CreatorNonArrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MVisitor*>(visitor))
    return parserVisitor->visitCreatorNonArray(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CreatorArrayContext ------------------------------------------------------------------

MParser::NonArrayTypeSpecifierContext* MParser::CreatorArrayContext::nonArrayTypeSpecifier() {
  return getRuleContext<MParser::NonArrayTypeSpecifierContext>(0);
}

std::vector<MParser::ExpressionContext *> MParser::CreatorArrayContext::expression() {
  return getRuleContexts<MParser::ExpressionContext>();
}

MParser::ExpressionContext* MParser::CreatorArrayContext::expression(size_t i) {
  return getRuleContext<MParser::ExpressionContext>(i);
}

MParser::CreatorArrayContext::CreatorArrayContext(CreatorContext *ctx) { copyFrom(ctx); }

void MParser::CreatorArrayContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCreatorArray(this);
}
void MParser::CreatorArrayContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCreatorArray(this);
}

antlrcpp::Any MParser::CreatorArrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MVisitor*>(visitor))
    return parserVisitor->visitCreatorArray(this);
  else
    return visitor->visitChildren(this);
}
MParser::CreatorContext* MParser::creator() {
  CreatorContext *_localctx = _tracker.createInstance<CreatorContext>(_ctx, getState());
  enterRule(_localctx, 40, MParser::RuleCreator);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(341);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<CreatorContext *>(_tracker.createInstance<MParser::CreatorErrorContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(301);
      nonArrayTypeSpecifier();
      setState(306); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(302);
                match(MParser::LBracket);
                setState(303);
                expression(0);
                setState(304);
                match(MParser::RBracket);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(308); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(312); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(310);
                match(MParser::LBracket);
                setState(311);
                match(MParser::RBracket);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(314); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(320); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(316);
                match(MParser::LBracket);
                setState(317);
                expression(0);
                setState(318);
                match(MParser::RBracket);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(322); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<CreatorContext *>(_tracker.createInstance<MParser::CreatorArrayContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(324);
      nonArrayTypeSpecifier();
      setState(329); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(325);
                match(MParser::LBracket);
                setState(326);
                expression(0);
                setState(327);
                match(MParser::RBracket);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(331); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(337);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(333);
          match(MParser::LBracket);
          setState(334);
          match(MParser::RBracket); 
        }
        setState(339);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
      }
      break;
    }

    case 3: {
      _localctx = dynamic_cast<CreatorContext *>(_tracker.createInstance<MParser::CreatorNonArrayContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(340);
      nonArrayTypeSpecifier();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterListContext ------------------------------------------------------------------

MParser::ParameterListContext::ParameterListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MParser::ExpressionContext *> MParser::ParameterListContext::expression() {
  return getRuleContexts<MParser::ExpressionContext>();
}

MParser::ExpressionContext* MParser::ParameterListContext::expression(size_t i) {
  return getRuleContext<MParser::ExpressionContext>(i);
}


size_t MParser::ParameterListContext::getRuleIndex() const {
  return MParser::RuleParameterList;
}

void MParser::ParameterListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterList(this);
}

void MParser::ParameterListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterList(this);
}


antlrcpp::Any MParser::ParameterListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MVisitor*>(visitor))
    return parserVisitor->visitParameterList(this);
  else
    return visitor->visitChildren(this);
}

MParser::ParameterListContext* MParser::parameterList() {
  ParameterListContext *_localctx = _tracker.createInstance<ParameterListContext>(_ctx, getState());
  enterRule(_localctx, 42, MParser::RuleParameterList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(343);
    expression(0);
    setState(348);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MParser::Comma) {
      setState(344);
      match(MParser::Comma);
      setState(345);
      expression(0);
      setState(350);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantContext ------------------------------------------------------------------

MParser::ConstantContext::ConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MParser::ConstantContext::IntegerConstant() {
  return getToken(MParser::IntegerConstant, 0);
}

tree::TerminalNode* MParser::ConstantContext::CharacterConstant() {
  return getToken(MParser::CharacterConstant, 0);
}

tree::TerminalNode* MParser::ConstantContext::StringLiteral() {
  return getToken(MParser::StringLiteral, 0);
}

tree::TerminalNode* MParser::ConstantContext::NullLiteral() {
  return getToken(MParser::NullLiteral, 0);
}

tree::TerminalNode* MParser::ConstantContext::BoolConstant() {
  return getToken(MParser::BoolConstant, 0);
}


size_t MParser::ConstantContext::getRuleIndex() const {
  return MParser::RuleConstant;
}

void MParser::ConstantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstant(this);
}

void MParser::ConstantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstant(this);
}


antlrcpp::Any MParser::ConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MVisitor*>(visitor))
    return parserVisitor->visitConstant(this);
  else
    return visitor->visitChildren(this);
}

MParser::ConstantContext* MParser::constant() {
  ConstantContext *_localctx = _tracker.createInstance<ConstantContext>(_ctx, getState());
  enterRule(_localctx, 44, MParser::RuleConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(356);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MParser::IntegerConstant: {
        enterOuterAlt(_localctx, 1);
        setState(351);
        dynamic_cast<ConstantContext *>(_localctx)->type = match(MParser::IntegerConstant);
        break;
      }

      case MParser::CharacterConstant: {
        enterOuterAlt(_localctx, 2);
        setState(352);
        dynamic_cast<ConstantContext *>(_localctx)->type = match(MParser::CharacterConstant);
        break;
      }

      case MParser::StringLiteral: {
        enterOuterAlt(_localctx, 3);
        setState(353);
        dynamic_cast<ConstantContext *>(_localctx)->type = match(MParser::StringLiteral);
        break;
      }

      case MParser::NullLiteral: {
        enterOuterAlt(_localctx, 4);
        setState(354);
        dynamic_cast<ConstantContext *>(_localctx)->type = match(MParser::NullLiteral);
        break;
      }

      case MParser::BoolConstant: {
        enterOuterAlt(_localctx, 5);
        setState(355);
        dynamic_cast<ConstantContext *>(_localctx)->type = match(MParser::BoolConstant);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool MParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 10: return typeSpecifierSempred(dynamic_cast<TypeSpecifierContext *>(context), predicateIndex);
    case 19: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool MParser::typeSpecifierSempred(TypeSpecifierContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool MParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 15);
    case 2: return precpred(_ctx, 14);
    case 3: return precpred(_ctx, 13);
    case 4: return precpred(_ctx, 12);
    case 5: return precpred(_ctx, 11);
    case 6: return precpred(_ctx, 10);
    case 7: return precpred(_ctx, 9);
    case 8: return precpred(_ctx, 8);
    case 9: return precpred(_ctx, 7);
    case 10: return precpred(_ctx, 6);
    case 11: return precpred(_ctx, 5);
    case 12: return precpred(_ctx, 4);
    case 13: return precpred(_ctx, 23);
    case 14: return precpred(_ctx, 22);
    case 15: return precpred(_ctx, 21);
    case 16: return precpred(_ctx, 20);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> MParser::_decisionToDFA;
atn::PredictionContextCache MParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN MParser::_atn;
std::vector<uint16_t> MParser::_serializedATN;

std::vector<std::string> MParser::_ruleNames = {
  "program", "programSection", "statement", "blockStatement", "blockItem", 
  "expressionStatement", "selectionStatement", "iterationStatement", "jumpStatement", 
  "nonArrayTypeSpecifier", "typeSpecifier", "variableDeclaration", "variableInitDeclarator", 
  "classDeclaration", "memberDeclaration", "classFunctionDeclaration", "functionDeclaration", 
  "parameterDeclarationList", "parameterDeclaration", "expression", "creator", 
  "parameterList", "constant"
};

std::vector<std::string> MParser::_literalNames = {
  "", "'else'", "'bool'", "'int'", "'void'", "'string'", "'if'", "'for'", 
  "'while'", "'break'", "'continue'", "'return'", "'new'", "'class'", "'this'", 
  "'+'", "'-'", "'*'", "'/'", "'%'", "'<'", "'>'", "'=='", "'!='", "'>='", 
  "'<='", "'&&'", "'||'", "'!'", "'<<'", "'>>'", "'~'", "'|'", "'^'", "'&'", 
  "'='", "'++'", "'--'", "'.'", "'['", "']'", "'('", "')'", "'{'", "'}'", 
  "'?'", "':'", "';'", "','", "'null'"
};

std::vector<std::string> MParser::_symbolicNames = {
  "", "", "Bool", "Int", "Void", "String", "If", "For", "While", "Break", 
  "Continue", "Return", "New", "Class", "This", "Plus", "Minus", "Star", 
  "Div", "Mod", "Less", "Greater", "Equal", "NotEqual", "GreaterEqual", 
  "LessEqual", "AndAnd", "OrOr", "Not", "LeftShift", "RightShift", "Tilde", 
  "Or", "Caret", "And", "Assign", "PlusPlus", "MinusMinus", "Dot", "LBracket", 
  "RBracket", "LParen", "RParen", "LBrace", "RBrace", "Question", "Colon", 
  "Semi", "Comma", "NullLiteral", "BoolConstant", "IntegerConstant", "CharacterConstant", 
  "StringLiteral", "Identifier", "Whitespace", "Newline", "LineComment"
};

dfa::Vocabulary MParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> MParser::_tokenNames;

MParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x3b, 0x169, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x3, 0x2, 0x7, 0x2, 0x32, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x35, 
    0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 
    0x3c, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 
    0x4, 0x43, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x47, 0xa, 0x5, 0xc, 
    0x5, 0xe, 0x5, 0x4a, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 
    0x5, 0x6, 0x50, 0xa, 0x6, 0x3, 0x7, 0x5, 0x7, 0x53, 0xa, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x5, 0x8, 0x5e, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 
    0x9, 0x6a, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x6e, 0xa, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x76, 
    0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x7a, 0xa, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x5, 0x9, 0x7e, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x82, 0xa, 
    0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 
    0xa, 0x8a, 0xa, 0xa, 0x3, 0xa, 0x5, 0xa, 0x8d, 0xa, 0xa, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x94, 0xa, 0xb, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0x9c, 0xa, 
    0xc, 0xc, 0xc, 0xe, 0xc, 0x9f, 0xb, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x7, 0xd, 0xa5, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0xa8, 0xb, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0xaf, 0xa, 
    0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0xb5, 0xa, 0xf, 
    0xc, 0xf, 0xe, 0xf, 0xb8, 0xb, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0xc1, 0xa, 0x10, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0xc7, 0xa, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x5, 0x11, 0xd0, 0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x5, 0x12, 0xd6, 0xa, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x7, 0x13, 0xde, 0xa, 0x13, 0xc, 0x13, 0xe, 0x13, 
    0xe1, 0xb, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x5, 0x15, 0xf5, 0xa, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0x120, 
    0xa, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x7, 0x15, 0x12b, 0xa, 0x15, 
    0xc, 0x15, 0xe, 0x15, 0x12e, 0xb, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x6, 0x16, 0x135, 0xa, 0x16, 0xd, 0x16, 0xe, 0x16, 
    0x136, 0x3, 0x16, 0x3, 0x16, 0x6, 0x16, 0x13b, 0xa, 0x16, 0xd, 0x16, 
    0xe, 0x16, 0x13c, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x6, 0x16, 
    0x143, 0xa, 0x16, 0xd, 0x16, 0xe, 0x16, 0x144, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x6, 0x16, 0x14c, 0xa, 0x16, 0xd, 0x16, 
    0xe, 0x16, 0x14d, 0x3, 0x16, 0x3, 0x16, 0x7, 0x16, 0x152, 0xa, 0x16, 
    0xc, 0x16, 0xe, 0x16, 0x155, 0xb, 0x16, 0x3, 0x16, 0x5, 0x16, 0x158, 
    0xa, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x7, 0x17, 0x15d, 0xa, 0x17, 
    0xc, 0x17, 0xe, 0x17, 0x160, 0xb, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0x167, 0xa, 0x18, 0x3, 0x18, 0x2, 0x4, 
    0x16, 0x28, 0x19, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 
    0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 
    0x2e, 0x2, 0xa, 0x3, 0x2, 0x26, 0x27, 0x3, 0x2, 0x11, 0x12, 0x4, 0x2, 
    0x1e, 0x1e, 0x21, 0x21, 0x3, 0x2, 0x13, 0x15, 0x3, 0x2, 0x1f, 0x20, 
    0x3, 0x2, 0x16, 0x17, 0x3, 0x2, 0x1a, 0x1b, 0x3, 0x2, 0x18, 0x19, 0x2, 
    0x196, 0x2, 0x33, 0x3, 0x2, 0x2, 0x2, 0x4, 0x3b, 0x3, 0x2, 0x2, 0x2, 
    0x6, 0x42, 0x3, 0x2, 0x2, 0x2, 0x8, 0x44, 0x3, 0x2, 0x2, 0x2, 0xa, 0x4f, 
    0x3, 0x2, 0x2, 0x2, 0xc, 0x52, 0x3, 0x2, 0x2, 0x2, 0xe, 0x56, 0x3, 0x2, 
    0x2, 0x2, 0x10, 0x81, 0x3, 0x2, 0x2, 0x2, 0x12, 0x8c, 0x3, 0x2, 0x2, 
    0x2, 0x14, 0x93, 0x3, 0x2, 0x2, 0x2, 0x16, 0x95, 0x3, 0x2, 0x2, 0x2, 
    0x18, 0xa0, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xab, 0x3, 0x2, 0x2, 0x2, 0x1c, 
    0xb0, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xc0, 0x3, 0x2, 0x2, 0x2, 0x20, 0xcf, 
    0x3, 0x2, 0x2, 0x2, 0x22, 0xd1, 0x3, 0x2, 0x2, 0x2, 0x24, 0xda, 0x3, 
    0x2, 0x2, 0x2, 0x26, 0xe2, 0x3, 0x2, 0x2, 0x2, 0x28, 0xf4, 0x3, 0x2, 
    0x2, 0x2, 0x2a, 0x157, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x159, 0x3, 0x2, 0x2, 
    0x2, 0x2e, 0x166, 0x3, 0x2, 0x2, 0x2, 0x30, 0x32, 0x5, 0x4, 0x3, 0x2, 
    0x31, 0x30, 0x3, 0x2, 0x2, 0x2, 0x32, 0x35, 0x3, 0x2, 0x2, 0x2, 0x33, 
    0x31, 0x3, 0x2, 0x2, 0x2, 0x33, 0x34, 0x3, 0x2, 0x2, 0x2, 0x34, 0x36, 
    0x3, 0x2, 0x2, 0x2, 0x35, 0x33, 0x3, 0x2, 0x2, 0x2, 0x36, 0x37, 0x7, 
    0x2, 0x2, 0x3, 0x37, 0x3, 0x3, 0x2, 0x2, 0x2, 0x38, 0x3c, 0x5, 0x1c, 
    0xf, 0x2, 0x39, 0x3c, 0x5, 0x22, 0x12, 0x2, 0x3a, 0x3c, 0x5, 0x18, 0xd, 
    0x2, 0x3b, 0x38, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x39, 0x3, 0x2, 0x2, 0x2, 
    0x3b, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x5, 0x3, 0x2, 0x2, 0x2, 0x3d, 
    0x43, 0x5, 0x8, 0x5, 0x2, 0x3e, 0x43, 0x5, 0xc, 0x7, 0x2, 0x3f, 0x43, 
    0x5, 0xe, 0x8, 0x2, 0x40, 0x43, 0x5, 0x10, 0x9, 0x2, 0x41, 0x43, 0x5, 
    0x12, 0xa, 0x2, 0x42, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x42, 0x3e, 0x3, 0x2, 
    0x2, 0x2, 0x42, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x42, 0x40, 0x3, 0x2, 0x2, 
    0x2, 0x42, 0x41, 0x3, 0x2, 0x2, 0x2, 0x43, 0x7, 0x3, 0x2, 0x2, 0x2, 
    0x44, 0x48, 0x7, 0x2d, 0x2, 0x2, 0x45, 0x47, 0x5, 0xa, 0x6, 0x2, 0x46, 
    0x45, 0x3, 0x2, 0x2, 0x2, 0x47, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x48, 0x46, 
    0x3, 0x2, 0x2, 0x2, 0x48, 0x49, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4b, 0x3, 
    0x2, 0x2, 0x2, 0x4a, 0x48, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4c, 0x7, 0x2e, 
    0x2, 0x2, 0x4c, 0x9, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x50, 0x5, 0x18, 0xd, 
    0x2, 0x4e, 0x50, 0x5, 0x6, 0x4, 0x2, 0x4f, 0x4d, 0x3, 0x2, 0x2, 0x2, 
    0x4f, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x50, 0xb, 0x3, 0x2, 0x2, 0x2, 0x51, 
    0x53, 0x5, 0x28, 0x15, 0x2, 0x52, 0x51, 0x3, 0x2, 0x2, 0x2, 0x52, 0x53, 
    0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 0x3, 0x2, 0x2, 0x2, 0x54, 0x55, 0x7, 
    0x31, 0x2, 0x2, 0x55, 0xd, 0x3, 0x2, 0x2, 0x2, 0x56, 0x57, 0x7, 0x8, 
    0x2, 0x2, 0x57, 0x58, 0x7, 0x2b, 0x2, 0x2, 0x58, 0x59, 0x5, 0x28, 0x15, 
    0x2, 0x59, 0x5a, 0x7, 0x2c, 0x2, 0x2, 0x5a, 0x5d, 0x5, 0x6, 0x4, 0x2, 
    0x5b, 0x5c, 0x7, 0x3, 0x2, 0x2, 0x5c, 0x5e, 0x5, 0x6, 0x4, 0x2, 0x5d, 
    0x5b, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x5e, 0xf, 
    0x3, 0x2, 0x2, 0x2, 0x5f, 0x60, 0x7, 0xa, 0x2, 0x2, 0x60, 0x61, 0x7, 
    0x2b, 0x2, 0x2, 0x61, 0x62, 0x5, 0x28, 0x15, 0x2, 0x62, 0x63, 0x7, 0x2c, 
    0x2, 0x2, 0x63, 0x64, 0x5, 0x6, 0x4, 0x2, 0x64, 0x82, 0x3, 0x2, 0x2, 
    0x2, 0x65, 0x66, 0x7, 0x9, 0x2, 0x2, 0x66, 0x67, 0x7, 0x2b, 0x2, 0x2, 
    0x67, 0x69, 0x5, 0x18, 0xd, 0x2, 0x68, 0x6a, 0x5, 0x28, 0x15, 0x2, 0x69, 
    0x68, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6b, 
    0x3, 0x2, 0x2, 0x2, 0x6b, 0x6d, 0x7, 0x31, 0x2, 0x2, 0x6c, 0x6e, 0x5, 
    0x28, 0x15, 0x2, 0x6d, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6e, 0x3, 0x2, 
    0x2, 0x2, 0x6e, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x70, 0x7, 0x2c, 0x2, 
    0x2, 0x70, 0x71, 0x5, 0x6, 0x4, 0x2, 0x71, 0x82, 0x3, 0x2, 0x2, 0x2, 
    0x72, 0x73, 0x7, 0x9, 0x2, 0x2, 0x73, 0x75, 0x7, 0x2b, 0x2, 0x2, 0x74, 
    0x76, 0x5, 0x28, 0x15, 0x2, 0x75, 0x74, 0x3, 0x2, 0x2, 0x2, 0x75, 0x76, 
    0x3, 0x2, 0x2, 0x2, 0x76, 0x77, 0x3, 0x2, 0x2, 0x2, 0x77, 0x79, 0x7, 
    0x31, 0x2, 0x2, 0x78, 0x7a, 0x5, 0x28, 0x15, 0x2, 0x79, 0x78, 0x3, 0x2, 
    0x2, 0x2, 0x79, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x7b, 0x3, 0x2, 0x2, 
    0x2, 0x7b, 0x7d, 0x7, 0x31, 0x2, 0x2, 0x7c, 0x7e, 0x5, 0x28, 0x15, 0x2, 
    0x7d, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x7e, 
    0x7f, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x80, 0x7, 0x2c, 0x2, 0x2, 0x80, 0x82, 
    0x5, 0x6, 0x4, 0x2, 0x81, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x81, 0x65, 0x3, 
    0x2, 0x2, 0x2, 0x81, 0x72, 0x3, 0x2, 0x2, 0x2, 0x82, 0x11, 0x3, 0x2, 
    0x2, 0x2, 0x83, 0x84, 0x7, 0xc, 0x2, 0x2, 0x84, 0x8d, 0x7, 0x31, 0x2, 
    0x2, 0x85, 0x86, 0x7, 0xb, 0x2, 0x2, 0x86, 0x8d, 0x7, 0x31, 0x2, 0x2, 
    0x87, 0x89, 0x7, 0xd, 0x2, 0x2, 0x88, 0x8a, 0x5, 0x28, 0x15, 0x2, 0x89, 
    0x88, 0x3, 0x2, 0x2, 0x2, 0x89, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8b, 
    0x3, 0x2, 0x2, 0x2, 0x8b, 0x8d, 0x7, 0x31, 0x2, 0x2, 0x8c, 0x83, 0x3, 
    0x2, 0x2, 0x2, 0x8c, 0x85, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x87, 0x3, 0x2, 
    0x2, 0x2, 0x8d, 0x13, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x94, 0x7, 0x5, 0x2, 
    0x2, 0x8f, 0x94, 0x7, 0x4, 0x2, 0x2, 0x90, 0x94, 0x7, 0x7, 0x2, 0x2, 
    0x91, 0x94, 0x7, 0x6, 0x2, 0x2, 0x92, 0x94, 0x7, 0x38, 0x2, 0x2, 0x93, 
    0x8e, 0x3, 0x2, 0x2, 0x2, 0x93, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x93, 0x90, 
    0x3, 0x2, 0x2, 0x2, 0x93, 0x91, 0x3, 0x2, 0x2, 0x2, 0x93, 0x92, 0x3, 
    0x2, 0x2, 0x2, 0x94, 0x15, 0x3, 0x2, 0x2, 0x2, 0x95, 0x96, 0x8, 0xc, 
    0x1, 0x2, 0x96, 0x97, 0x5, 0x14, 0xb, 0x2, 0x97, 0x9d, 0x3, 0x2, 0x2, 
    0x2, 0x98, 0x99, 0xc, 0x4, 0x2, 0x2, 0x99, 0x9a, 0x7, 0x29, 0x2, 0x2, 
    0x9a, 0x9c, 0x7, 0x2a, 0x2, 0x2, 0x9b, 0x98, 0x3, 0x2, 0x2, 0x2, 0x9c, 
    0x9f, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x9e, 
    0x3, 0x2, 0x2, 0x2, 0x9e, 0x17, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x9d, 0x3, 
    0x2, 0x2, 0x2, 0xa0, 0xa1, 0x5, 0x16, 0xc, 0x2, 0xa1, 0xa6, 0x5, 0x1a, 
    0xe, 0x2, 0xa2, 0xa3, 0x7, 0x32, 0x2, 0x2, 0xa3, 0xa5, 0x5, 0x1a, 0xe, 
    0x2, 0xa4, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa8, 0x3, 0x2, 0x2, 0x2, 
    0xa6, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xa7, 
    0xa9, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xaa, 
    0x7, 0x31, 0x2, 0x2, 0xaa, 0x19, 0x3, 0x2, 0x2, 0x2, 0xab, 0xae, 0x7, 
    0x38, 0x2, 0x2, 0xac, 0xad, 0x7, 0x25, 0x2, 0x2, 0xad, 0xaf, 0x5, 0x28, 
    0x15, 0x2, 0xae, 0xac, 0x3, 0x2, 0x2, 0x2, 0xae, 0xaf, 0x3, 0x2, 0x2, 
    0x2, 0xaf, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xb1, 0x7, 0xf, 0x2, 0x2, 
    0xb1, 0xb2, 0x7, 0x38, 0x2, 0x2, 0xb2, 0xb6, 0x7, 0x2d, 0x2, 0x2, 0xb3, 
    0xb5, 0x5, 0x1e, 0x10, 0x2, 0xb4, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb8, 
    0x3, 0x2, 0x2, 0x2, 0xb6, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb7, 0x3, 
    0x2, 0x2, 0x2, 0xb7, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb6, 0x3, 0x2, 
    0x2, 0x2, 0xb9, 0xba, 0x7, 0x2e, 0x2, 0x2, 0xba, 0x1d, 0x3, 0x2, 0x2, 
    0x2, 0xbb, 0xbc, 0x5, 0x16, 0xc, 0x2, 0xbc, 0xbd, 0x7, 0x38, 0x2, 0x2, 
    0xbd, 0xbe, 0x7, 0x31, 0x2, 0x2, 0xbe, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xbf, 
    0xc1, 0x5, 0x20, 0x11, 0x2, 0xc0, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xbf, 
    0x3, 0x2, 0x2, 0x2, 0xc1, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc3, 0x5, 
    0x16, 0xc, 0x2, 0xc3, 0xc4, 0x7, 0x38, 0x2, 0x2, 0xc4, 0xc6, 0x7, 0x2b, 
    0x2, 0x2, 0xc5, 0xc7, 0x5, 0x24, 0x13, 0x2, 0xc6, 0xc5, 0x3, 0x2, 0x2, 
    0x2, 0xc6, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc8, 0x3, 0x2, 0x2, 0x2, 
    0xc8, 0xc9, 0x7, 0x2c, 0x2, 0x2, 0xc9, 0xca, 0x5, 0x8, 0x5, 0x2, 0xca, 
    0xd0, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xcc, 0x7, 0x38, 0x2, 0x2, 0xcc, 0xcd, 
    0x7, 0x2b, 0x2, 0x2, 0xcd, 0xce, 0x7, 0x2c, 0x2, 0x2, 0xce, 0xd0, 0x5, 
    0x8, 0x5, 0x2, 0xcf, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xcb, 0x3, 0x2, 
    0x2, 0x2, 0xd0, 0x21, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd2, 0x5, 0x16, 0xc, 
    0x2, 0xd2, 0xd3, 0x7, 0x38, 0x2, 0x2, 0xd3, 0xd5, 0x7, 0x2b, 0x2, 0x2, 
    0xd4, 0xd6, 0x5, 0x24, 0x13, 0x2, 0xd5, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd5, 
    0xd6, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd8, 
    0x7, 0x2c, 0x2, 0x2, 0xd8, 0xd9, 0x5, 0x8, 0x5, 0x2, 0xd9, 0x23, 0x3, 
    0x2, 0x2, 0x2, 0xda, 0xdf, 0x5, 0x26, 0x14, 0x2, 0xdb, 0xdc, 0x7, 0x32, 
    0x2, 0x2, 0xdc, 0xde, 0x5, 0x26, 0x14, 0x2, 0xdd, 0xdb, 0x3, 0x2, 0x2, 
    0x2, 0xde, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xdd, 0x3, 0x2, 0x2, 0x2, 
    0xdf, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xe0, 0x25, 0x3, 0x2, 0x2, 0x2, 0xe1, 
    0xdf, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe3, 0x5, 0x16, 0xc, 0x2, 0xe3, 0xe4, 
    0x7, 0x38, 0x2, 0x2, 0xe4, 0x27, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe6, 0x8, 
    0x15, 0x1, 0x2, 0xe6, 0xe7, 0x9, 0x2, 0x2, 0x2, 0xe7, 0xf5, 0x5, 0x28, 
    0x15, 0x15, 0xe8, 0xe9, 0x9, 0x3, 0x2, 0x2, 0xe9, 0xf5, 0x5, 0x28, 0x15, 
    0x14, 0xea, 0xeb, 0x9, 0x4, 0x2, 0x2, 0xeb, 0xf5, 0x5, 0x28, 0x15, 0x13, 
    0xec, 0xed, 0x7, 0xe, 0x2, 0x2, 0xed, 0xf5, 0x5, 0x2a, 0x16, 0x2, 0xee, 
    0xf5, 0x7, 0x38, 0x2, 0x2, 0xef, 0xf5, 0x5, 0x2e, 0x18, 0x2, 0xf0, 0xf1, 
    0x7, 0x2b, 0x2, 0x2, 0xf1, 0xf2, 0x5, 0x28, 0x15, 0x2, 0xf2, 0xf3, 0x7, 
    0x2c, 0x2, 0x2, 0xf3, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xe5, 0x3, 0x2, 
    0x2, 0x2, 0xf4, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xea, 0x3, 0x2, 0x2, 
    0x2, 0xf4, 0xec, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xee, 0x3, 0x2, 0x2, 0x2, 
    0xf4, 0xef, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf5, 
    0x12c, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf7, 0xc, 0x11, 0x2, 0x2, 0xf7, 0xf8, 
    0x9, 0x5, 0x2, 0x2, 0xf8, 0x12b, 0x5, 0x28, 0x15, 0x12, 0xf9, 0xfa, 
    0xc, 0x10, 0x2, 0x2, 0xfa, 0xfb, 0x9, 0x3, 0x2, 0x2, 0xfb, 0x12b, 0x5, 
    0x28, 0x15, 0x11, 0xfc, 0xfd, 0xc, 0xf, 0x2, 0x2, 0xfd, 0xfe, 0x9, 0x6, 
    0x2, 0x2, 0xfe, 0x12b, 0x5, 0x28, 0x15, 0x10, 0xff, 0x100, 0xc, 0xe, 
    0x2, 0x2, 0x100, 0x101, 0x9, 0x7, 0x2, 0x2, 0x101, 0x12b, 0x5, 0x28, 
    0x15, 0xf, 0x102, 0x103, 0xc, 0xd, 0x2, 0x2, 0x103, 0x104, 0x9, 0x8, 
    0x2, 0x2, 0x104, 0x12b, 0x5, 0x28, 0x15, 0xe, 0x105, 0x106, 0xc, 0xc, 
    0x2, 0x2, 0x106, 0x107, 0x9, 0x9, 0x2, 0x2, 0x107, 0x12b, 0x5, 0x28, 
    0x15, 0xd, 0x108, 0x109, 0xc, 0xb, 0x2, 0x2, 0x109, 0x10a, 0x7, 0x24, 
    0x2, 0x2, 0x10a, 0x12b, 0x5, 0x28, 0x15, 0xc, 0x10b, 0x10c, 0xc, 0xa, 
    0x2, 0x2, 0x10c, 0x10d, 0x7, 0x23, 0x2, 0x2, 0x10d, 0x12b, 0x5, 0x28, 
    0x15, 0xb, 0x10e, 0x10f, 0xc, 0x9, 0x2, 0x2, 0x10f, 0x110, 0x7, 0x22, 
    0x2, 0x2, 0x110, 0x12b, 0x5, 0x28, 0x15, 0xa, 0x111, 0x112, 0xc, 0x8, 
    0x2, 0x2, 0x112, 0x113, 0x7, 0x1c, 0x2, 0x2, 0x113, 0x12b, 0x5, 0x28, 
    0x15, 0x9, 0x114, 0x115, 0xc, 0x7, 0x2, 0x2, 0x115, 0x116, 0x7, 0x1d, 
    0x2, 0x2, 0x116, 0x12b, 0x5, 0x28, 0x15, 0x8, 0x117, 0x118, 0xc, 0x6, 
    0x2, 0x2, 0x118, 0x119, 0x7, 0x25, 0x2, 0x2, 0x119, 0x12b, 0x5, 0x28, 
    0x15, 0x6, 0x11a, 0x11b, 0xc, 0x19, 0x2, 0x2, 0x11b, 0x12b, 0x9, 0x2, 
    0x2, 0x2, 0x11c, 0x11d, 0xc, 0x18, 0x2, 0x2, 0x11d, 0x11f, 0x7, 0x2b, 
    0x2, 0x2, 0x11e, 0x120, 0x5, 0x2c, 0x17, 0x2, 0x11f, 0x11e, 0x3, 0x2, 
    0x2, 0x2, 0x11f, 0x120, 0x3, 0x2, 0x2, 0x2, 0x120, 0x121, 0x3, 0x2, 
    0x2, 0x2, 0x121, 0x12b, 0x7, 0x2c, 0x2, 0x2, 0x122, 0x123, 0xc, 0x17, 
    0x2, 0x2, 0x123, 0x124, 0x7, 0x29, 0x2, 0x2, 0x124, 0x125, 0x5, 0x28, 
    0x15, 0x2, 0x125, 0x126, 0x7, 0x2a, 0x2, 0x2, 0x126, 0x12b, 0x3, 0x2, 
    0x2, 0x2, 0x127, 0x128, 0xc, 0x16, 0x2, 0x2, 0x128, 0x129, 0x7, 0x28, 
    0x2, 0x2, 0x129, 0x12b, 0x7, 0x38, 0x2, 0x2, 0x12a, 0xf6, 0x3, 0x2, 
    0x2, 0x2, 0x12a, 0xf9, 0x3, 0x2, 0x2, 0x2, 0x12a, 0xfc, 0x3, 0x2, 0x2, 
    0x2, 0x12a, 0xff, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x102, 0x3, 0x2, 0x2, 0x2, 
    0x12a, 0x105, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x108, 0x3, 0x2, 0x2, 0x2, 
    0x12a, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x10e, 0x3, 0x2, 0x2, 0x2, 
    0x12a, 0x111, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x114, 0x3, 0x2, 0x2, 0x2, 
    0x12a, 0x117, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x11a, 0x3, 0x2, 0x2, 0x2, 
    0x12a, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x122, 0x3, 0x2, 0x2, 0x2, 
    0x12a, 0x127, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x12e, 0x3, 0x2, 0x2, 0x2, 
    0x12c, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x12d, 0x3, 0x2, 0x2, 0x2, 
    0x12d, 0x29, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x12f, 
    0x134, 0x5, 0x14, 0xb, 0x2, 0x130, 0x131, 0x7, 0x29, 0x2, 0x2, 0x131, 
    0x132, 0x5, 0x28, 0x15, 0x2, 0x132, 0x133, 0x7, 0x2a, 0x2, 0x2, 0x133, 
    0x135, 0x3, 0x2, 0x2, 0x2, 0x134, 0x130, 0x3, 0x2, 0x2, 0x2, 0x135, 
    0x136, 0x3, 0x2, 0x2, 0x2, 0x136, 0x134, 0x3, 0x2, 0x2, 0x2, 0x136, 
    0x137, 0x3, 0x2, 0x2, 0x2, 0x137, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x138, 
    0x139, 0x7, 0x29, 0x2, 0x2, 0x139, 0x13b, 0x7, 0x2a, 0x2, 0x2, 0x13a, 
    0x138, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x13c, 0x3, 0x2, 0x2, 0x2, 0x13c, 
    0x13a, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x13d, 
    0x142, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x13f, 0x7, 0x29, 0x2, 0x2, 0x13f, 
    0x140, 0x5, 0x28, 0x15, 0x2, 0x140, 0x141, 0x7, 0x2a, 0x2, 0x2, 0x141, 
    0x143, 0x3, 0x2, 0x2, 0x2, 0x142, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x143, 
    0x144, 0x3, 0x2, 0x2, 0x2, 0x144, 0x142, 0x3, 0x2, 0x2, 0x2, 0x144, 
    0x145, 0x3, 0x2, 0x2, 0x2, 0x145, 0x158, 0x3, 0x2, 0x2, 0x2, 0x146, 
    0x14b, 0x5, 0x14, 0xb, 0x2, 0x147, 0x148, 0x7, 0x29, 0x2, 0x2, 0x148, 
    0x149, 0x5, 0x28, 0x15, 0x2, 0x149, 0x14a, 0x7, 0x2a, 0x2, 0x2, 0x14a, 
    0x14c, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x147, 0x3, 0x2, 0x2, 0x2, 0x14c, 
    0x14d, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x14d, 
    0x14e, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x153, 0x3, 0x2, 0x2, 0x2, 0x14f, 
    0x150, 0x7, 0x29, 0x2, 0x2, 0x150, 0x152, 0x7, 0x2a, 0x2, 0x2, 0x151, 
    0x14f, 0x3, 0x2, 0x2, 0x2, 0x152, 0x155, 0x3, 0x2, 0x2, 0x2, 0x153, 
    0x151, 0x3, 0x2, 0x2, 0x2, 0x153, 0x154, 0x3, 0x2, 0x2, 0x2, 0x154, 
    0x158, 0x3, 0x2, 0x2, 0x2, 0x155, 0x153, 0x3, 0x2, 0x2, 0x2, 0x156, 
    0x158, 0x5, 0x14, 0xb, 0x2, 0x157, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x157, 
    0x146, 0x3, 0x2, 0x2, 0x2, 0x157, 0x156, 0x3, 0x2, 0x2, 0x2, 0x158, 
    0x2b, 0x3, 0x2, 0x2, 0x2, 0x159, 0x15e, 0x5, 0x28, 0x15, 0x2, 0x15a, 
    0x15b, 0x7, 0x32, 0x2, 0x2, 0x15b, 0x15d, 0x5, 0x28, 0x15, 0x2, 0x15c, 
    0x15a, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x160, 0x3, 0x2, 0x2, 0x2, 0x15e, 
    0x15c, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x15f, 0x3, 0x2, 0x2, 0x2, 0x15f, 
    0x2d, 0x3, 0x2, 0x2, 0x2, 0x160, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x161, 0x167, 
    0x7, 0x35, 0x2, 0x2, 0x162, 0x167, 0x7, 0x36, 0x2, 0x2, 0x163, 0x167, 
    0x7, 0x37, 0x2, 0x2, 0x164, 0x167, 0x7, 0x33, 0x2, 0x2, 0x165, 0x167, 
    0x7, 0x34, 0x2, 0x2, 0x166, 0x161, 0x3, 0x2, 0x2, 0x2, 0x166, 0x162, 
    0x3, 0x2, 0x2, 0x2, 0x166, 0x163, 0x3, 0x2, 0x2, 0x2, 0x166, 0x164, 
    0x3, 0x2, 0x2, 0x2, 0x166, 0x165, 0x3, 0x2, 0x2, 0x2, 0x167, 0x2f, 0x3, 
    0x2, 0x2, 0x2, 0x27, 0x33, 0x3b, 0x42, 0x48, 0x4f, 0x52, 0x5d, 0x69, 
    0x6d, 0x75, 0x79, 0x7d, 0x81, 0x89, 0x8c, 0x93, 0x9d, 0xa6, 0xae, 0xb6, 
    0xc0, 0xc6, 0xcf, 0xd5, 0xdf, 0xf4, 0x11f, 0x12a, 0x12c, 0x136, 0x13c, 
    0x144, 0x14d, 0x153, 0x157, 0x15e, 0x166, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

MParser::Initializer MParser::_init;
