
// Generated from M.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"


namespace antlrcpptest {


class  MLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, Bool = 2, Int = 3, Void = 4, String = 5, If = 6, For = 7, 
    While = 8, Break = 9, Continue = 10, Return = 11, New = 12, Class = 13, 
    Plus = 14, Minus = 15, Star = 16, Div = 17, Mod = 18, Less = 19, Greater = 20, 
    Equal = 21, NotEqual = 22, GreaterEqual = 23, LessEqual = 24, AndAnd = 25, 
    OrOr = 26, Not = 27, LeftShift = 28, RightShift = 29, Tilde = 30, Or = 31, 
    Caret = 32, And = 33, Assign = 34, PlusPlus = 35, MinusMinus = 36, Dot = 37, 
    LBracket = 38, RBracket = 39, LParen = 40, RParen = 41, LBrace = 42, 
    RBrace = 43, Question = 44, Colon = 45, Semi = 46, Comma = 47, NullLiteral = 48, 
    BoolConstant = 49, IntegerConstant = 50, StringLiteral = 51, Identifier = 52, 
    Whitespace = 53, Newline = 54, LineComment = 55
  };

  MLexer(antlr4::CharStream *input);
  ~MLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace antlrcpptest
