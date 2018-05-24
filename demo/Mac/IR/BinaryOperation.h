//
//  BinaryOperation.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/12.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef BinaryOperation_h
#define BinaryOperation_h
#include "IRInstruction.h"
class BinaryOperation : public IRInstruction{
public:
    enum BinaryOp {
        ADD, SUB, MUL, DIV, MOD, SHL, SHR, AND, OR, XOR
    };
    std::shared_ptr<Register> dest;
    BinaryOp op;
    std::shared_ptr<Register> lhs;
    std::shared_ptr<Register> rhs;
    
    BinaryOperation(std::shared_ptr<BasicBlock> Block, std::shared_ptr<Register> destination, BinaryOp Op, std::shared_ptr<Register> Lhs, std::shared_ptr<Register> Rhs) : IRInstruction(Block){
        dest = destination;
        op = Op;
        lhs = Lhs;
        rhs = Rhs;
    }
};

#endif /* BinaryOperation_h */
