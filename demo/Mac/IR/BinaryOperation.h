//
//  BinaryOperation.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/12.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef BinaryOperation_h
#define BinaryOperation_h
#include "IRInstruction"
#include "IntValue"
class BinaryOperation : public IRInstruction{
public:
    enum BinaryOp {
        ADD, SUB, MUL, DIV, MOD, SHL, SHR, AND, OR, XOR
    }
    std::shared_ptr<IntValue> dest;
    BinaryOp op;
    std::shared_ptr<IntValue> lhs;
    std::shared_ptr<IntValue> rhs;
};

#endif /* BinaryOperation_h */
