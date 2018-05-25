//
//  IntComparison.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/12.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef IntComparison_h
#define IntComparison_h
#include "IRInstruction.h"
class IntComparison : public IRInstruction {
public:
    enum Comparison{
        EQ, NE, GT, GE, LT, LE
    };
    std::shared_ptr<Register> dest;
    Comparison cond;
    std::shared_ptr<Register> lhs;
    std::shared_ptr<Register> rhs;
    
    IntComparison(std::shared_ptr<BasicBlock> Block, std::shared_ptr<Register> Dest, Comparison Cond, std::shared_ptr<Register> Lhs, std::shared_ptr<Register> Rhs) : IRInstruction(Block){
        dest = Dest;
        cond = Cond;
        lhs = Lhs;
        rhs = Rhs;
    }
    void visited(std::shared_ptr<IRVisitor> visitor){
        visitor -> visit(std::dynamic_pointer_cast<IntComparison>(shared_from_this()));
    }
};

#endif /* IntComparison_h */
