//
//  UnaryOperation.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/12.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef UnaryOperation_h
#define UnaryOperation_h
#include "IRInstruction.h"
class UnaryOperation : public IRInstruction {
public:
    enum UnaryOp{
        NEG, NOT
    };
    std::shared_ptr<Register> dest;
    UnaryOp op;
    std::shared_ptr<Register> operand;
    
    UnaryOperation(std::shared_ptr<BasicBlock> Block, std::shared_ptr<Register> Dest, UnaryOp Op, std::shared_ptr<Register> Operand) : IRInstruction(Block) {
        dest = Dest;
        op = Op;
        operand = Operand;
    }
};

#endif /* UnaryOperation_h */
