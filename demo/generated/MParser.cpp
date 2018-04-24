
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
    setState(51);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MParser::Bool)
      | (1ULL << MParser::Int)
      | (1ULL << MParser::Void)
      | (1ULL << MParser::String)
      | (1ULL << MParser::Class)
      | (1ULL << MParser::Identifier))) != 0)) {
      setState(48);
      programSection();
      setState(53);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(54);
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
    setState(59);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(56);
      classDeclaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(57);
      functionDeclaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(58);
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
    setState(66);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MParser::LBrace: {
        enterOuterAlt(_localctx, 1);
        setState(61);
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
        setState(62);
        expressionStatement();
        break;
      }

      case MParser::If: {
        enterOuterAlt(_localctx, 3);
        setState(63);
        selectionStatement();
        break;
      }

      case MParser::For:
      case MParser::While: {
        enterOuterAlt(_localctx, 4);
        setState(64);
        iterationStatement();
        break;
      }

      case MParser::Break:
      case MParser::Continue:
      case MParser::Return: {
        enterOuterAlt(_localctx, 5);
        setState(65);
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
    setState(68);
    match(MParser::LBrace);
    setState(72);
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
      setState(69);
      blockItem();
      setState(74);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(75);
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
    setState(79);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(77);
      variableDeclaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(78);
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
    setState(82);
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
      setState(81);
      expression(0);
    }
    setState(84);
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
    setState(86);
    match(MParser::If);
    setState(87);
    match(MParser::LParen);
    setState(88);
    expression(0);
    setState(89);
    match(MParser::RParen);
    setState(90);
    statement();
    setState(93);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      setState(91);
      match(MParser::T__0);
      setState(92);
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
    setState(129);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(95);
      match(MParser::While);
      setState(96);
      match(MParser::LParen);
      setState(97);
      expression(0);
      setState(98);
      match(MParser::RParen);
      setState(99);
      statement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(101);
      match(MParser::For);
      setState(102);
      match(MParser::LParen);
      setState(103);
      dynamic_cast<IterationStatementContext *>(_localctx)->declinit = variableDeclaration();
      setState(105);
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
        setState(104);
        dynamic_cast<IterationStatementContext *>(_localctx)->cond = expression(0);
      }
      setState(107);
      match(MParser::Semi);
      setState(109);
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
        setState(108);
        dynamic_cast<IterationStatementContext *>(_localctx)->step = expression(0);
      }
      setState(111);
      match(MParser::RParen);
      setState(112);
      statement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(114);
      match(MParser::For);
      setState(115);
      match(MParser::LParen);
      setState(117);
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
        setState(116);
        dynamic_cast<IterationStatementContext *>(_localctx)->init = expression(0);
      }
      setState(119);
      match(MParser::Semi);
      setState(121);
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
        setState(120);
        dynamic_cast<IterationStatementContext *>(_localctx)->cond = expression(0);
      }
      setState(123);
      match(MParser::Semi);
      setState(125);
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
        setState(124);
        dynamic_cast<IterationStatementContext *>(_localctx)->step = expression(0);
      }
      setState(127);
      match(MParser::RParen);
      setState(128);
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
    setState(140);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MParser::Continue: {
        enterOuterAlt(_localctx, 1);
        setState(131);
        match(MParser::Continue);
        setState(132);
        match(MParser::Semi);
        break;
      }

      case MParser::Break: {
        enterOuterAlt(_localctx, 2);
        setState(133);
        match(MParser::Break);
        setState(134);
        match(MParser::Semi);
        break;
      }

      case MParser::Return: {
        enterOuterAlt(_localctx, 3);
        setState(135);
        match(MParser::Return);
        setState(137);
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
          setState(136);
          expression(0);
        }
        setState(139);
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
    setState(147);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MParser::Int: {
        enterOuterAlt(_localctx, 1);
        setState(142);
        dynamic_cast<NonArrayTypeSpecifierContext *>(_localctx)->type = match(MParser::Int);
        break;
      }

      case MParser::Bool: {
        enterOuterAlt(_localctx, 2);
        setState(143);
        dynamic_cast<NonArrayTypeSpecifierContext *>(_localctx)->type = match(MParser::Bool);
        break;
      }

      case MParser::String: {
        enterOuterAlt(_localctx, 3);
        setState(144);
        dynamic_cast<NonArrayTypeSpecifierContext *>(_localctx)->type = match(MParser::String);
        break;
      }

      case MParser::Void: {
        enterOuterAlt(_localctx, 4);
        setState(145);
        dynamic_cast<NonArrayTypeSpecifierContext *>(_localctx)->type = match(MParser::Void);
        break;
      }

      case MParser::Identifier: {
        enterOuterAlt(_localctx, 5);
        setState(146);
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

std::vector<MParser::LbrContext *> MParser::TypeSpecifierContext::lbr() {
  return getRuleContexts<MParser::LbrContext>();
}

MParser::LbrContext* MParser::TypeSpecifierContext::lbr(size_t i) {
  return getRuleContext<MParser::LbrContext>(i);
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
  TypeSpecifierContext *_localctx = _tracker.createInstance<TypeSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 20, MParser::RuleTypeSpecifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(149);
    nonArrayTypeSpecifier();
    setState(153);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MParser::LBracket) {
      setState(150);
      lbr();
      setState(155);
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

//----------------- LbrContext ------------------------------------------------------------------

MParser::LbrContext::LbrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MParser::LbrContext::getRuleIndex() const {
  return MParser::RuleLbr;
}

void MParser::LbrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLbr(this);
}

void MParser::LbrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLbr(this);
}


antlrcpp::Any MParser::LbrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MVisitor*>(visitor))
    return parserVisitor->visitLbr(this);
  else
    return visitor->visitChildren(this);
}

MParser::LbrContext* MParser::lbr() {
  LbrContext *_localctx = _tracker.createInstance<LbrContext>(_ctx, getState());
  enterRule(_localctx, 22, MParser::RuleLbr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(156);
    match(MParser::LBracket);
    setState(157);
    match(MParser::RBracket);
   
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
  enterRule(_localctx, 24, MParser::RuleVariableDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(159);
    typeSpecifier();
    setState(160);
    variableInitDeclarator();
    setState(165);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MParser::Comma) {
      setState(161);
      match(MParser::Comma);
      setState(162);
      variableInitDeclarator();
      setState(167);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(168);
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
  enterRule(_localctx, 26, MParser::RuleVariableInitDeclarator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(170);
    match(MParser::Identifier);
    setState(173);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MParser::Assign) {
      setState(171);
      match(MParser::Assign);
      setState(172);
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
  enterRule(_localctx, 28, MParser::RuleClassDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(175);
    match(MParser::Class);
    setState(176);
    match(MParser::Identifier);
    setState(177);
    match(MParser::LBrace);
    setState(181);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MParser::Bool)
      | (1ULL << MParser::Int)
      | (1ULL << MParser::Void)
      | (1ULL << MParser::String)
      | (1ULL << MParser::Identifier))) != 0)) {
      setState(178);
      memberDeclaration();
      setState(183);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(184);
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

MParser::VariableDeclarationContext* MParser::MemberDeclarationContext::variableDeclaration() {
  return getRuleContext<MParser::VariableDeclarationContext>(0);
}

MParser::FunctionDeclarationContext* MParser::MemberDeclarationContext::functionDeclaration() {
  return getRuleContext<MParser::FunctionDeclarationContext>(0);
}

MParser::ClassConstructorContext* MParser::MemberDeclarationContext::classConstructor() {
  return getRuleContext<MParser::ClassConstructorContext>(0);
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
  enterRule(_localctx, 30, MParser::RuleMemberDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(189);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(186);
      variableDeclaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(187);
      functionDeclaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(188);
      classConstructor();
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

//----------------- ClassConstructorContext ------------------------------------------------------------------

MParser::ClassConstructorContext::ClassConstructorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MParser::ClassConstructorContext::Identifier() {
  return getToken(MParser::Identifier, 0);
}

MParser::BlockStatementContext* MParser::ClassConstructorContext::blockStatement() {
  return getRuleContext<MParser::BlockStatementContext>(0);
}


size_t MParser::ClassConstructorContext::getRuleIndex() const {
  return MParser::RuleClassConstructor;
}

void MParser::ClassConstructorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassConstructor(this);
}

void MParser::ClassConstructorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassConstructor(this);
}


antlrcpp::Any MParser::ClassConstructorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MVisitor*>(visitor))
    return parserVisitor->visitClassConstructor(this);
  else
    return visitor->visitChildren(this);
}

MParser::ClassConstructorContext* MParser::classConstructor() {
  ClassConstructorContext *_localctx = _tracker.createInstance<ClassConstructorContext>(_ctx, getState());
  enterRule(_localctx, 32, MParser::RuleClassConstructor);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(191);
    match(MParser::Identifier);
    setState(192);
    match(MParser::LParen);
    setState(193);
    match(MParser::RParen);
    setState(194);
    blockStatement();
   
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
  enterRule(_localctx, 34, MParser::RuleFunctionDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(196);
    typeSpecifier();
    setState(197);
    match(MParser::Identifier);
    setState(198);
    match(MParser::LParen);
    setState(200);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MParser::Bool)
      | (1ULL << MParser::Int)
      | (1ULL << MParser::Void)
      | (1ULL << MParser::String)
      | (1ULL << MParser::Identifier))) != 0)) {
      setState(199);
      parameterDeclarationList();
    }
    setState(202);
    match(MParser::RParen);
    setState(203);
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
  enterRule(_localctx, 36, MParser::RuleParameterDeclarationList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(205);
    parameterDeclaration();
    setState(210);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MParser::Comma) {
      setState(206);
      match(MParser::Comma);
      setState(207);
      parameterDeclaration();
      setState(212);
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
  enterRule(_localctx, 38, MParser::RuleParameterDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(213);
    typeSpecifier();
    setState(214);
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
  size_t startState = 40;
  enterRecursionRule(_localctx, 40, MParser::RuleExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(231);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MParser::PlusPlus:
      case MParser::MinusMinus: {
        _localctx = _tracker.createInstance<UnaryExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(217);
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
        setState(218);
        expression(19);
        break;
      }

      case MParser::Plus:
      case MParser::Minus: {
        _localctx = _tracker.createInstance<UnaryExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(219);
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
        setState(220);
        expression(18);
        break;
      }

      case MParser::Not:
      case MParser::Tilde: {
        _localctx = _tracker.createInstance<UnaryExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(221);
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
        setState(222);
        expression(17);
        break;
      }

      case MParser::New: {
        _localctx = _tracker.createInstance<NewContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(223);
        match(MParser::New);
        setState(224);
        creator();
        break;
      }

      case MParser::Identifier: {
        _localctx = _tracker.createInstance<IdentifierContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(225);
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
        setState(226);
        constant();
        break;
      }

      case MParser::LParen: {
        _localctx = _tracker.createInstance<SubExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(227);
        match(MParser::LParen);
        setState(228);
        expression(0);
        setState(229);
        match(MParser::RParen);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(287);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(285);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(233);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(234);
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
          setState(235);
          expression(16);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(236);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(237);
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
          setState(238);
          expression(15);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(239);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(240);
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
          setState(241);
          expression(14);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(242);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(243);
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
          setState(244);
          expression(13);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(245);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(246);
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
          setState(247);
          expression(12);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(248);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(249);
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
          setState(250);
          expression(11);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(251);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(252);
          dynamic_cast<BinaryExprContext *>(_localctx)->op = match(MParser::And);
          setState(253);
          expression(10);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(254);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(255);
          dynamic_cast<BinaryExprContext *>(_localctx)->op = match(MParser::Caret);
          setState(256);
          expression(9);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(257);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(258);
          dynamic_cast<BinaryExprContext *>(_localctx)->op = match(MParser::Or);
          setState(259);
          expression(8);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(260);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(261);
          dynamic_cast<BinaryExprContext *>(_localctx)->op = match(MParser::AndAnd);
          setState(262);
          expression(7);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(263);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(264);
          dynamic_cast<BinaryExprContext *>(_localctx)->op = match(MParser::OrOr);
          setState(265);
          expression(6);
          break;
        }

        case 12: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(266);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(267);
          dynamic_cast<BinaryExprContext *>(_localctx)->op = match(MParser::Assign);
          setState(268);
          expression(4);
          break;
        }

        case 13: {
          auto newContext = _tracker.createInstance<PostfixIncDecContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(269);

          if (!(precpred(_ctx, 23))) throw FailedPredicateException(this, "precpred(_ctx, 23)");
          setState(270);
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
          setState(271);

          if (!(precpred(_ctx, 22))) throw FailedPredicateException(this, "precpred(_ctx, 22)");
          setState(272);
          match(MParser::LParen);
          setState(274);
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
            setState(273);
            parameterList();
          }
          setState(276);
          match(MParser::RParen);
          break;
        }

        case 15: {
          auto newContext = _tracker.createInstance<SubscriptContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(277);

          if (!(precpred(_ctx, 21))) throw FailedPredicateException(this, "precpred(_ctx, 21)");
          setState(278);
          match(MParser::LBracket);
          setState(279);
          expression(0);
          setState(280);
          match(MParser::RBracket);
          break;
        }

        case 16: {
          auto newContext = _tracker.createInstance<MemberAccessContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(282);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(283);
          match(MParser::Dot);
          setState(284);
          match(MParser::Identifier);
          break;
        }

        } 
      }
      setState(289);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
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
  enterRule(_localctx, 42, MParser::RuleCreator);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(330);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<CreatorContext *>(_tracker.createInstance<MParser::CreatorErrorContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(290);
      nonArrayTypeSpecifier();
      setState(295); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(291);
                match(MParser::LBracket);
                setState(292);
                expression(0);
                setState(293);
                match(MParser::RBracket);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(297); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(301); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(299);
                match(MParser::LBracket);
                setState(300);
                match(MParser::RBracket);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(303); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(309); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(305);
                match(MParser::LBracket);
                setState(306);
                expression(0);
                setState(307);
                match(MParser::RBracket);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(311); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<CreatorContext *>(_tracker.createInstance<MParser::CreatorArrayContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(313);
      nonArrayTypeSpecifier();
      setState(318); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(314);
                match(MParser::LBracket);
                setState(315);
                expression(0);
                setState(316);
                match(MParser::RBracket);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(320); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(326);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(322);
          match(MParser::LBracket);
          setState(323);
          match(MParser::RBracket); 
        }
        setState(328);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
      }
      break;
    }

    case 3: {
      _localctx = dynamic_cast<CreatorContext *>(_tracker.createInstance<MParser::CreatorNonArrayContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(329);
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
  enterRule(_localctx, 44, MParser::RuleParameterList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(332);
    expression(0);
    setState(337);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MParser::Comma) {
      setState(333);
      match(MParser::Comma);
      setState(334);
      expression(0);
      setState(339);
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
  enterRule(_localctx, 46, MParser::RuleConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(345);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MParser::IntegerConstant: {
        enterOuterAlt(_localctx, 1);
        setState(340);
        dynamic_cast<ConstantContext *>(_localctx)->type = match(MParser::IntegerConstant);
        break;
      }

      case MParser::CharacterConstant: {
        enterOuterAlt(_localctx, 2);
        setState(341);
        dynamic_cast<ConstantContext *>(_localctx)->type = match(MParser::CharacterConstant);
        break;
      }

      case MParser::StringLiteral: {
        enterOuterAlt(_localctx, 3);
        setState(342);
        dynamic_cast<ConstantContext *>(_localctx)->type = match(MParser::StringLiteral);
        break;
      }

      case MParser::NullLiteral: {
        enterOuterAlt(_localctx, 4);
        setState(343);
        dynamic_cast<ConstantContext *>(_localctx)->type = match(MParser::NullLiteral);
        break;
      }

      case MParser::BoolConstant: {
        enterOuterAlt(_localctx, 5);
        setState(344);
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
    case 20: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool MParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 15);
    case 1: return precpred(_ctx, 14);
    case 2: return precpred(_ctx, 13);
    case 3: return precpred(_ctx, 12);
    case 4: return precpred(_ctx, 11);
    case 5: return precpred(_ctx, 10);
    case 6: return precpred(_ctx, 9);
    case 7: return precpred(_ctx, 8);
    case 8: return precpred(_ctx, 7);
    case 9: return precpred(_ctx, 6);
    case 10: return precpred(_ctx, 5);
    case 11: return precpred(_ctx, 4);
    case 12: return precpred(_ctx, 23);
    case 13: return precpred(_ctx, 22);
    case 14: return precpred(_ctx, 21);
    case 15: return precpred(_ctx, 20);

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
  "nonArrayTypeSpecifier", "typeSpecifier", "lbr", "variableDeclaration", 
  "variableInitDeclarator", "classDeclaration", "memberDeclaration", "classConstructor", 
  "functionDeclaration", "parameterDeclarationList", "parameterDeclaration", 
  "expression", "creator", "parameterList", "constant"
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
    0x3, 0x3b, 0x15e, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x3, 0x2, 0x7, 0x2, 0x34, 0xa, 0x2, 0xc, 
    0x2, 0xe, 0x2, 0x37, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x5, 0x3, 0x3e, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x5, 0x4, 0x45, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 
    0x49, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x4c, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x52, 0xa, 0x6, 0x3, 0x7, 0x5, 0x7, 0x55, 
    0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x60, 0xa, 0x8, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x5, 0x9, 0x6c, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 
    0x70, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x5, 0x9, 0x78, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x7c, 0xa, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x80, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x5, 0x9, 0x84, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x5, 0xa, 0x8c, 0xa, 0xa, 0x3, 0xa, 0x5, 0xa, 0x8f, 0xa, 
    0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x96, 
    0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0x9a, 0xa, 0xc, 0xc, 0xc, 0xe, 
    0xc, 0x9d, 0xb, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0xa6, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0xa9, 
    0xb, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 
    0xb0, 0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 
    0xb6, 0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0xb9, 0xb, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0xc0, 0xa, 0x11, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0xcb, 0xa, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x7, 0x14, 0xd3, 0xa, 0x14, 
    0xc, 0x14, 0xe, 0x14, 0xd6, 0xb, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
    0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0xea, 0xa, 0x16, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
    0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
    0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
    0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
    0x5, 0x16, 0x115, 0xa, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x7, 0x16, 0x120, 
    0xa, 0x16, 0xc, 0x16, 0xe, 0x16, 0x123, 0xb, 0x16, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x6, 0x17, 0x12a, 0xa, 0x17, 0xd, 0x17, 
    0xe, 0x17, 0x12b, 0x3, 0x17, 0x3, 0x17, 0x6, 0x17, 0x130, 0xa, 0x17, 
    0xd, 0x17, 0xe, 0x17, 0x131, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
    0x6, 0x17, 0x138, 0xa, 0x17, 0xd, 0x17, 0xe, 0x17, 0x139, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x6, 0x17, 0x141, 0xa, 0x17, 
    0xd, 0x17, 0xe, 0x17, 0x142, 0x3, 0x17, 0x3, 0x17, 0x7, 0x17, 0x147, 
    0xa, 0x17, 0xc, 0x17, 0xe, 0x17, 0x14a, 0xb, 0x17, 0x3, 0x17, 0x5, 0x17, 
    0x14d, 0xa, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x7, 0x18, 0x152, 
    0xa, 0x18, 0xc, 0x18, 0xe, 0x18, 0x155, 0xb, 0x18, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 0x15c, 0xa, 0x19, 0x3, 0x19, 
    0x2, 0x3, 0x2a, 0x1a, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 
    0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 
    0x2c, 0x2e, 0x30, 0x2, 0xa, 0x3, 0x2, 0x26, 0x27, 0x3, 0x2, 0x11, 0x12, 
    0x4, 0x2, 0x1e, 0x1e, 0x21, 0x21, 0x3, 0x2, 0x13, 0x15, 0x3, 0x2, 0x1f, 
    0x20, 0x3, 0x2, 0x16, 0x17, 0x3, 0x2, 0x1a, 0x1b, 0x3, 0x2, 0x18, 0x19, 
    0x2, 0x189, 0x2, 0x35, 0x3, 0x2, 0x2, 0x2, 0x4, 0x3d, 0x3, 0x2, 0x2, 
    0x2, 0x6, 0x44, 0x3, 0x2, 0x2, 0x2, 0x8, 0x46, 0x3, 0x2, 0x2, 0x2, 0xa, 
    0x51, 0x3, 0x2, 0x2, 0x2, 0xc, 0x54, 0x3, 0x2, 0x2, 0x2, 0xe, 0x58, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0x83, 0x3, 0x2, 0x2, 0x2, 0x12, 0x8e, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0x95, 0x3, 0x2, 0x2, 0x2, 0x16, 0x97, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0x9e, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xa1, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0xac, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xb1, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0xbf, 0x3, 0x2, 0x2, 0x2, 0x22, 0xc1, 0x3, 0x2, 0x2, 0x2, 0x24, 
    0xc6, 0x3, 0x2, 0x2, 0x2, 0x26, 0xcf, 0x3, 0x2, 0x2, 0x2, 0x28, 0xd7, 
    0x3, 0x2, 0x2, 0x2, 0x2a, 0xe9, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x14c, 0x3, 
    0x2, 0x2, 0x2, 0x2e, 0x14e, 0x3, 0x2, 0x2, 0x2, 0x30, 0x15b, 0x3, 0x2, 
    0x2, 0x2, 0x32, 0x34, 0x5, 0x4, 0x3, 0x2, 0x33, 0x32, 0x3, 0x2, 0x2, 
    0x2, 0x34, 0x37, 0x3, 0x2, 0x2, 0x2, 0x35, 0x33, 0x3, 0x2, 0x2, 0x2, 
    0x35, 0x36, 0x3, 0x2, 0x2, 0x2, 0x36, 0x38, 0x3, 0x2, 0x2, 0x2, 0x37, 
    0x35, 0x3, 0x2, 0x2, 0x2, 0x38, 0x39, 0x7, 0x2, 0x2, 0x3, 0x39, 0x3, 
    0x3, 0x2, 0x2, 0x2, 0x3a, 0x3e, 0x5, 0x1e, 0x10, 0x2, 0x3b, 0x3e, 0x5, 
    0x24, 0x13, 0x2, 0x3c, 0x3e, 0x5, 0x1a, 0xe, 0x2, 0x3d, 0x3a, 0x3, 0x2, 
    0x2, 0x2, 0x3d, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3c, 0x3, 0x2, 0x2, 
    0x2, 0x3e, 0x5, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x45, 0x5, 0x8, 0x5, 0x2, 
    0x40, 0x45, 0x5, 0xc, 0x7, 0x2, 0x41, 0x45, 0x5, 0xe, 0x8, 0x2, 0x42, 
    0x45, 0x5, 0x10, 0x9, 0x2, 0x43, 0x45, 0x5, 0x12, 0xa, 0x2, 0x44, 0x3f, 
    0x3, 0x2, 0x2, 0x2, 0x44, 0x40, 0x3, 0x2, 0x2, 0x2, 0x44, 0x41, 0x3, 
    0x2, 0x2, 0x2, 0x44, 0x42, 0x3, 0x2, 0x2, 0x2, 0x44, 0x43, 0x3, 0x2, 
    0x2, 0x2, 0x45, 0x7, 0x3, 0x2, 0x2, 0x2, 0x46, 0x4a, 0x7, 0x2d, 0x2, 
    0x2, 0x47, 0x49, 0x5, 0xa, 0x6, 0x2, 0x48, 0x47, 0x3, 0x2, 0x2, 0x2, 
    0x49, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x48, 0x3, 0x2, 0x2, 0x2, 0x4a, 
    0x4b, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4a, 
    0x3, 0x2, 0x2, 0x2, 0x4d, 0x4e, 0x7, 0x2e, 0x2, 0x2, 0x4e, 0x9, 0x3, 
    0x2, 0x2, 0x2, 0x4f, 0x52, 0x5, 0x1a, 0xe, 0x2, 0x50, 0x52, 0x5, 0x6, 
    0x4, 0x2, 0x51, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x51, 0x50, 0x3, 0x2, 0x2, 
    0x2, 0x52, 0xb, 0x3, 0x2, 0x2, 0x2, 0x53, 0x55, 0x5, 0x2a, 0x16, 0x2, 
    0x54, 0x53, 0x3, 0x2, 0x2, 0x2, 0x54, 0x55, 0x3, 0x2, 0x2, 0x2, 0x55, 
    0x56, 0x3, 0x2, 0x2, 0x2, 0x56, 0x57, 0x7, 0x31, 0x2, 0x2, 0x57, 0xd, 
    0x3, 0x2, 0x2, 0x2, 0x58, 0x59, 0x7, 0x8, 0x2, 0x2, 0x59, 0x5a, 0x7, 
    0x2b, 0x2, 0x2, 0x5a, 0x5b, 0x5, 0x2a, 0x16, 0x2, 0x5b, 0x5c, 0x7, 0x2c, 
    0x2, 0x2, 0x5c, 0x5f, 0x5, 0x6, 0x4, 0x2, 0x5d, 0x5e, 0x7, 0x3, 0x2, 
    0x2, 0x5e, 0x60, 0x5, 0x6, 0x4, 0x2, 0x5f, 0x5d, 0x3, 0x2, 0x2, 0x2, 
    0x5f, 0x60, 0x3, 0x2, 0x2, 0x2, 0x60, 0xf, 0x3, 0x2, 0x2, 0x2, 0x61, 
    0x62, 0x7, 0xa, 0x2, 0x2, 0x62, 0x63, 0x7, 0x2b, 0x2, 0x2, 0x63, 0x64, 
    0x5, 0x2a, 0x16, 0x2, 0x64, 0x65, 0x7, 0x2c, 0x2, 0x2, 0x65, 0x66, 0x5, 
    0x6, 0x4, 0x2, 0x66, 0x84, 0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 0x7, 0x9, 
    0x2, 0x2, 0x68, 0x69, 0x7, 0x2b, 0x2, 0x2, 0x69, 0x6b, 0x5, 0x1a, 0xe, 
    0x2, 0x6a, 0x6c, 0x5, 0x2a, 0x16, 0x2, 0x6b, 0x6a, 0x3, 0x2, 0x2, 0x2, 
    0x6b, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6d, 
    0x6f, 0x7, 0x31, 0x2, 0x2, 0x6e, 0x70, 0x5, 0x2a, 0x16, 0x2, 0x6f, 0x6e, 
    0x3, 0x2, 0x2, 0x2, 0x6f, 0x70, 0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 0x3, 
    0x2, 0x2, 0x2, 0x71, 0x72, 0x7, 0x2c, 0x2, 0x2, 0x72, 0x73, 0x5, 0x6, 
    0x4, 0x2, 0x73, 0x84, 0x3, 0x2, 0x2, 0x2, 0x74, 0x75, 0x7, 0x9, 0x2, 
    0x2, 0x75, 0x77, 0x7, 0x2b, 0x2, 0x2, 0x76, 0x78, 0x5, 0x2a, 0x16, 0x2, 
    0x77, 0x76, 0x3, 0x2, 0x2, 0x2, 0x77, 0x78, 0x3, 0x2, 0x2, 0x2, 0x78, 
    0x79, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7b, 0x7, 0x31, 0x2, 0x2, 0x7a, 0x7c, 
    0x5, 0x2a, 0x16, 0x2, 0x7b, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7c, 0x3, 
    0x2, 0x2, 0x2, 0x7c, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7f, 0x7, 0x31, 
    0x2, 0x2, 0x7e, 0x80, 0x5, 0x2a, 0x16, 0x2, 0x7f, 0x7e, 0x3, 0x2, 0x2, 
    0x2, 0x7f, 0x80, 0x3, 0x2, 0x2, 0x2, 0x80, 0x81, 0x3, 0x2, 0x2, 0x2, 
    0x81, 0x82, 0x7, 0x2c, 0x2, 0x2, 0x82, 0x84, 0x5, 0x6, 0x4, 0x2, 0x83, 
    0x61, 0x3, 0x2, 0x2, 0x2, 0x83, 0x67, 0x3, 0x2, 0x2, 0x2, 0x83, 0x74, 
    0x3, 0x2, 0x2, 0x2, 0x84, 0x11, 0x3, 0x2, 0x2, 0x2, 0x85, 0x86, 0x7, 
    0xc, 0x2, 0x2, 0x86, 0x8f, 0x7, 0x31, 0x2, 0x2, 0x87, 0x88, 0x7, 0xb, 
    0x2, 0x2, 0x88, 0x8f, 0x7, 0x31, 0x2, 0x2, 0x89, 0x8b, 0x7, 0xd, 0x2, 
    0x2, 0x8a, 0x8c, 0x5, 0x2a, 0x16, 0x2, 0x8b, 0x8a, 0x3, 0x2, 0x2, 0x2, 
    0x8b, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x8d, 
    0x8f, 0x7, 0x31, 0x2, 0x2, 0x8e, 0x85, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x87, 
    0x3, 0x2, 0x2, 0x2, 0x8e, 0x89, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x13, 0x3, 
    0x2, 0x2, 0x2, 0x90, 0x96, 0x7, 0x5, 0x2, 0x2, 0x91, 0x96, 0x7, 0x4, 
    0x2, 0x2, 0x92, 0x96, 0x7, 0x7, 0x2, 0x2, 0x93, 0x96, 0x7, 0x6, 0x2, 
    0x2, 0x94, 0x96, 0x7, 0x38, 0x2, 0x2, 0x95, 0x90, 0x3, 0x2, 0x2, 0x2, 
    0x95, 0x91, 0x3, 0x2, 0x2, 0x2, 0x95, 0x92, 0x3, 0x2, 0x2, 0x2, 0x95, 
    0x93, 0x3, 0x2, 0x2, 0x2, 0x95, 0x94, 0x3, 0x2, 0x2, 0x2, 0x96, 0x15, 
    0x3, 0x2, 0x2, 0x2, 0x97, 0x9b, 0x5, 0x14, 0xb, 0x2, 0x98, 0x9a, 0x5, 
    0x18, 0xd, 0x2, 0x99, 0x98, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x9d, 0x3, 0x2, 
    0x2, 0x2, 0x9b, 0x99, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x9c, 0x3, 0x2, 0x2, 
    0x2, 0x9c, 0x17, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x9b, 0x3, 0x2, 0x2, 0x2, 
    0x9e, 0x9f, 0x7, 0x29, 0x2, 0x2, 0x9f, 0xa0, 0x7, 0x2a, 0x2, 0x2, 0xa0, 
    0x19, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa2, 0x5, 0x16, 0xc, 0x2, 0xa2, 0xa7, 
    0x5, 0x1c, 0xf, 0x2, 0xa3, 0xa4, 0x7, 0x32, 0x2, 0x2, 0xa4, 0xa6, 0x5, 
    0x1c, 0xf, 0x2, 0xa5, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa9, 0x3, 0x2, 
    0x2, 0x2, 0xa7, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xa8, 0x3, 0x2, 0x2, 
    0x2, 0xa8, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xa7, 0x3, 0x2, 0x2, 0x2, 
    0xaa, 0xab, 0x7, 0x31, 0x2, 0x2, 0xab, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xac, 
    0xaf, 0x7, 0x38, 0x2, 0x2, 0xad, 0xae, 0x7, 0x25, 0x2, 0x2, 0xae, 0xb0, 
    0x5, 0x2a, 0x16, 0x2, 0xaf, 0xad, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xb0, 0x3, 
    0x2, 0x2, 0x2, 0xb0, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb2, 0x7, 0xf, 
    0x2, 0x2, 0xb2, 0xb3, 0x7, 0x38, 0x2, 0x2, 0xb3, 0xb7, 0x7, 0x2d, 0x2, 
    0x2, 0xb4, 0xb6, 0x5, 0x20, 0x11, 0x2, 0xb5, 0xb4, 0x3, 0x2, 0x2, 0x2, 
    0xb6, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xb7, 
    0xb8, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xba, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xb7, 
    0x3, 0x2, 0x2, 0x2, 0xba, 0xbb, 0x7, 0x2e, 0x2, 0x2, 0xbb, 0x1f, 0x3, 
    0x2, 0x2, 0x2, 0xbc, 0xc0, 0x5, 0x1a, 0xe, 0x2, 0xbd, 0xc0, 0x5, 0x24, 
    0x13, 0x2, 0xbe, 0xc0, 0x5, 0x22, 0x12, 0x2, 0xbf, 0xbc, 0x3, 0x2, 0x2, 
    0x2, 0xbf, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xbe, 0x3, 0x2, 0x2, 0x2, 
    0xc0, 0x21, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc2, 0x7, 0x38, 0x2, 0x2, 0xc2, 
    0xc3, 0x7, 0x2b, 0x2, 0x2, 0xc3, 0xc4, 0x7, 0x2c, 0x2, 0x2, 0xc4, 0xc5, 
    0x5, 0x8, 0x5, 0x2, 0xc5, 0x23, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc7, 0x5, 
    0x16, 0xc, 0x2, 0xc7, 0xc8, 0x7, 0x38, 0x2, 0x2, 0xc8, 0xca, 0x7, 0x2b, 
    0x2, 0x2, 0xc9, 0xcb, 0x5, 0x26, 0x14, 0x2, 0xca, 0xc9, 0x3, 0x2, 0x2, 
    0x2, 0xca, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xcc, 0x3, 0x2, 0x2, 0x2, 
    0xcc, 0xcd, 0x7, 0x2c, 0x2, 0x2, 0xcd, 0xce, 0x5, 0x8, 0x5, 0x2, 0xce, 
    0x25, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xd4, 0x5, 0x28, 0x15, 0x2, 0xd0, 0xd1, 
    0x7, 0x32, 0x2, 0x2, 0xd1, 0xd3, 0x5, 0x28, 0x15, 0x2, 0xd2, 0xd0, 0x3, 
    0x2, 0x2, 0x2, 0xd3, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd2, 0x3, 0x2, 
    0x2, 0x2, 0xd4, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xd5, 0x27, 0x3, 0x2, 0x2, 
    0x2, 0xd6, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd8, 0x5, 0x16, 0xc, 0x2, 
    0xd8, 0xd9, 0x7, 0x38, 0x2, 0x2, 0xd9, 0x29, 0x3, 0x2, 0x2, 0x2, 0xda, 
    0xdb, 0x8, 0x16, 0x1, 0x2, 0xdb, 0xdc, 0x9, 0x2, 0x2, 0x2, 0xdc, 0xea, 
    0x5, 0x2a, 0x16, 0x15, 0xdd, 0xde, 0x9, 0x3, 0x2, 0x2, 0xde, 0xea, 0x5, 
    0x2a, 0x16, 0x14, 0xdf, 0xe0, 0x9, 0x4, 0x2, 0x2, 0xe0, 0xea, 0x5, 0x2a, 
    0x16, 0x13, 0xe1, 0xe2, 0x7, 0xe, 0x2, 0x2, 0xe2, 0xea, 0x5, 0x2c, 0x17, 
    0x2, 0xe3, 0xea, 0x7, 0x38, 0x2, 0x2, 0xe4, 0xea, 0x5, 0x30, 0x19, 0x2, 
    0xe5, 0xe6, 0x7, 0x2b, 0x2, 0x2, 0xe6, 0xe7, 0x5, 0x2a, 0x16, 0x2, 0xe7, 
    0xe8, 0x7, 0x2c, 0x2, 0x2, 0xe8, 0xea, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xda, 
    0x3, 0x2, 0x2, 0x2, 0xe9, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xdf, 0x3, 
    0x2, 0x2, 0x2, 0xe9, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xe3, 0x3, 0x2, 
    0x2, 0x2, 0xe9, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xe5, 0x3, 0x2, 0x2, 
    0x2, 0xea, 0x121, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xec, 0xc, 0x11, 0x2, 0x2, 
    0xec, 0xed, 0x9, 0x5, 0x2, 0x2, 0xed, 0x120, 0x5, 0x2a, 0x16, 0x12, 
    0xee, 0xef, 0xc, 0x10, 0x2, 0x2, 0xef, 0xf0, 0x9, 0x3, 0x2, 0x2, 0xf0, 
    0x120, 0x5, 0x2a, 0x16, 0x11, 0xf1, 0xf2, 0xc, 0xf, 0x2, 0x2, 0xf2, 
    0xf3, 0x9, 0x6, 0x2, 0x2, 0xf3, 0x120, 0x5, 0x2a, 0x16, 0x10, 0xf4, 
    0xf5, 0xc, 0xe, 0x2, 0x2, 0xf5, 0xf6, 0x9, 0x7, 0x2, 0x2, 0xf6, 0x120, 
    0x5, 0x2a, 0x16, 0xf, 0xf7, 0xf8, 0xc, 0xd, 0x2, 0x2, 0xf8, 0xf9, 0x9, 
    0x8, 0x2, 0x2, 0xf9, 0x120, 0x5, 0x2a, 0x16, 0xe, 0xfa, 0xfb, 0xc, 0xc, 
    0x2, 0x2, 0xfb, 0xfc, 0x9, 0x9, 0x2, 0x2, 0xfc, 0x120, 0x5, 0x2a, 0x16, 
    0xd, 0xfd, 0xfe, 0xc, 0xb, 0x2, 0x2, 0xfe, 0xff, 0x7, 0x24, 0x2, 0x2, 
    0xff, 0x120, 0x5, 0x2a, 0x16, 0xc, 0x100, 0x101, 0xc, 0xa, 0x2, 0x2, 
    0x101, 0x102, 0x7, 0x23, 0x2, 0x2, 0x102, 0x120, 0x5, 0x2a, 0x16, 0xb, 
    0x103, 0x104, 0xc, 0x9, 0x2, 0x2, 0x104, 0x105, 0x7, 0x22, 0x2, 0x2, 
    0x105, 0x120, 0x5, 0x2a, 0x16, 0xa, 0x106, 0x107, 0xc, 0x8, 0x2, 0x2, 
    0x107, 0x108, 0x7, 0x1c, 0x2, 0x2, 0x108, 0x120, 0x5, 0x2a, 0x16, 0x9, 
    0x109, 0x10a, 0xc, 0x7, 0x2, 0x2, 0x10a, 0x10b, 0x7, 0x1d, 0x2, 0x2, 
    0x10b, 0x120, 0x5, 0x2a, 0x16, 0x8, 0x10c, 0x10d, 0xc, 0x6, 0x2, 0x2, 
    0x10d, 0x10e, 0x7, 0x25, 0x2, 0x2, 0x10e, 0x120, 0x5, 0x2a, 0x16, 0x6, 
    0x10f, 0x110, 0xc, 0x19, 0x2, 0x2, 0x110, 0x120, 0x9, 0x2, 0x2, 0x2, 
    0x111, 0x112, 0xc, 0x18, 0x2, 0x2, 0x112, 0x114, 0x7, 0x2b, 0x2, 0x2, 
    0x113, 0x115, 0x5, 0x2e, 0x18, 0x2, 0x114, 0x113, 0x3, 0x2, 0x2, 0x2, 
    0x114, 0x115, 0x3, 0x2, 0x2, 0x2, 0x115, 0x116, 0x3, 0x2, 0x2, 0x2, 
    0x116, 0x120, 0x7, 0x2c, 0x2, 0x2, 0x117, 0x118, 0xc, 0x17, 0x2, 0x2, 
    0x118, 0x119, 0x7, 0x29, 0x2, 0x2, 0x119, 0x11a, 0x5, 0x2a, 0x16, 0x2, 
    0x11a, 0x11b, 0x7, 0x2a, 0x2, 0x2, 0x11b, 0x120, 0x3, 0x2, 0x2, 0x2, 
    0x11c, 0x11d, 0xc, 0x16, 0x2, 0x2, 0x11d, 0x11e, 0x7, 0x28, 0x2, 0x2, 
    0x11e, 0x120, 0x7, 0x38, 0x2, 0x2, 0x11f, 0xeb, 0x3, 0x2, 0x2, 0x2, 
    0x11f, 0xee, 0x3, 0x2, 0x2, 0x2, 0x11f, 0xf1, 0x3, 0x2, 0x2, 0x2, 0x11f, 
    0xf4, 0x3, 0x2, 0x2, 0x2, 0x11f, 0xf7, 0x3, 0x2, 0x2, 0x2, 0x11f, 0xfa, 
    0x3, 0x2, 0x2, 0x2, 0x11f, 0xfd, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x100, 0x3, 
    0x2, 0x2, 0x2, 0x11f, 0x103, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x106, 0x3, 
    0x2, 0x2, 0x2, 0x11f, 0x109, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x10c, 0x3, 
    0x2, 0x2, 0x2, 0x11f, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x111, 0x3, 
    0x2, 0x2, 0x2, 0x11f, 0x117, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x11c, 0x3, 
    0x2, 0x2, 0x2, 0x120, 0x123, 0x3, 0x2, 0x2, 0x2, 0x121, 0x11f, 0x3, 
    0x2, 0x2, 0x2, 0x121, 0x122, 0x3, 0x2, 0x2, 0x2, 0x122, 0x2b, 0x3, 0x2, 
    0x2, 0x2, 0x123, 0x121, 0x3, 0x2, 0x2, 0x2, 0x124, 0x129, 0x5, 0x14, 
    0xb, 0x2, 0x125, 0x126, 0x7, 0x29, 0x2, 0x2, 0x126, 0x127, 0x5, 0x2a, 
    0x16, 0x2, 0x127, 0x128, 0x7, 0x2a, 0x2, 0x2, 0x128, 0x12a, 0x3, 0x2, 
    0x2, 0x2, 0x129, 0x125, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x12b, 0x3, 0x2, 
    0x2, 0x2, 0x12b, 0x129, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x12c, 0x3, 0x2, 
    0x2, 0x2, 0x12c, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x12e, 0x7, 0x29, 
    0x2, 0x2, 0x12e, 0x130, 0x7, 0x2a, 0x2, 0x2, 0x12f, 0x12d, 0x3, 0x2, 
    0x2, 0x2, 0x130, 0x131, 0x3, 0x2, 0x2, 0x2, 0x131, 0x12f, 0x3, 0x2, 
    0x2, 0x2, 0x131, 0x132, 0x3, 0x2, 0x2, 0x2, 0x132, 0x137, 0x3, 0x2, 
    0x2, 0x2, 0x133, 0x134, 0x7, 0x29, 0x2, 0x2, 0x134, 0x135, 0x5, 0x2a, 
    0x16, 0x2, 0x135, 0x136, 0x7, 0x2a, 0x2, 0x2, 0x136, 0x138, 0x3, 0x2, 
    0x2, 0x2, 0x137, 0x133, 0x3, 0x2, 0x2, 0x2, 0x138, 0x139, 0x3, 0x2, 
    0x2, 0x2, 0x139, 0x137, 0x3, 0x2, 0x2, 0x2, 0x139, 0x13a, 0x3, 0x2, 
    0x2, 0x2, 0x13a, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x140, 0x5, 0x14, 
    0xb, 0x2, 0x13c, 0x13d, 0x7, 0x29, 0x2, 0x2, 0x13d, 0x13e, 0x5, 0x2a, 
    0x16, 0x2, 0x13e, 0x13f, 0x7, 0x2a, 0x2, 0x2, 0x13f, 0x141, 0x3, 0x2, 
    0x2, 0x2, 0x140, 0x13c, 0x3, 0x2, 0x2, 0x2, 0x141, 0x142, 0x3, 0x2, 
    0x2, 0x2, 0x142, 0x140, 0x3, 0x2, 0x2, 0x2, 0x142, 0x143, 0x3, 0x2, 
    0x2, 0x2, 0x143, 0x148, 0x3, 0x2, 0x2, 0x2, 0x144, 0x145, 0x7, 0x29, 
    0x2, 0x2, 0x145, 0x147, 0x7, 0x2a, 0x2, 0x2, 0x146, 0x144, 0x3, 0x2, 
    0x2, 0x2, 0x147, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x148, 0x146, 0x3, 0x2, 
    0x2, 0x2, 0x148, 0x149, 0x3, 0x2, 0x2, 0x2, 0x149, 0x14d, 0x3, 0x2, 
    0x2, 0x2, 0x14a, 0x148, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x14d, 0x5, 0x14, 
    0xb, 0x2, 0x14c, 0x124, 0x3, 0x2, 0x2, 0x2, 0x14c, 0x13b, 0x3, 0x2, 
    0x2, 0x2, 0x14c, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x2d, 0x3, 0x2, 0x2, 
    0x2, 0x14e, 0x153, 0x5, 0x2a, 0x16, 0x2, 0x14f, 0x150, 0x7, 0x32, 0x2, 
    0x2, 0x150, 0x152, 0x5, 0x2a, 0x16, 0x2, 0x151, 0x14f, 0x3, 0x2, 0x2, 
    0x2, 0x152, 0x155, 0x3, 0x2, 0x2, 0x2, 0x153, 0x151, 0x3, 0x2, 0x2, 
    0x2, 0x153, 0x154, 0x3, 0x2, 0x2, 0x2, 0x154, 0x2f, 0x3, 0x2, 0x2, 0x2, 
    0x155, 0x153, 0x3, 0x2, 0x2, 0x2, 0x156, 0x15c, 0x7, 0x35, 0x2, 0x2, 
    0x157, 0x15c, 0x7, 0x36, 0x2, 0x2, 0x158, 0x15c, 0x7, 0x37, 0x2, 0x2, 
    0x159, 0x15c, 0x7, 0x33, 0x2, 0x2, 0x15a, 0x15c, 0x7, 0x34, 0x2, 0x2, 
    0x15b, 0x156, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x157, 0x3, 0x2, 0x2, 0x2, 
    0x15b, 0x158, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x159, 0x3, 0x2, 0x2, 0x2, 
    0x15b, 0x15a, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x31, 0x3, 0x2, 0x2, 0x2, 0x25, 
    0x35, 0x3d, 0x44, 0x4a, 0x51, 0x54, 0x5f, 0x6b, 0x6f, 0x77, 0x7b, 0x7f, 
    0x83, 0x8b, 0x8e, 0x95, 0x9b, 0xa7, 0xaf, 0xb7, 0xbf, 0xca, 0xd4, 0xe9, 
    0x114, 0x11f, 0x121, 0x12b, 0x131, 0x139, 0x142, 0x148, 0x14c, 0x153, 
    0x15b, 
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
