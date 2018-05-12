//
//  UnaryOperation.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/12.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef UnaryOperation_h
#define UnaryOperation_h
class UnaryOperation : public IRInstruction {
public:
    enum UnaryOp{
        NEG, NOT
    }
    std::shared_ptr<IntValue> dest;
    UnaryOp op;
    std::shared_ptr<IntValue> operand;
};

#endif /* UnaryOperation_h */
