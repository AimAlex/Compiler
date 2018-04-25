
// Generated from M.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"


namespace antlrcpptest {


class  MLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, Bool = 2, Int = 3, Void = 4, String = 5, If = 6, For = 7, 
    While = 8, Break = 9, Continue = 10, Return = 11, New = 12, Class = 13, 
    This = 14, Plus = 15, Minus = 16, Star = 17, Div = 18, Mod = 19, Less = 20, 
    Greater = 21, Equal = 22, NotEqual = 23, GreaterEqual = 24, LessEqual = 25, 
    AndAnd = 26, OrOr = 27, Not = 28, LeftShift = 29, RightShift = 30, Tilde = 31, 
    Or = 32, Caret = 33, And = 34, Assign = 35, PlusPlus = 36, MinusMinus = 37, 
    Dot = 38, LBracket = 39, RBracket = 40, LParen = 41, RParen = 42, LBrace = 43, 
    RBrace = 44, Question = 45, Colon = 46, Semi = 47, Comma = 48, NullLiteral = 49, 
    BoolConstant = 50, IntegerConstant = 51, StringLiteral = 52, Identifier = 53, 
    Whitespace = 54, Newline = 55, LineComment = 56
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
