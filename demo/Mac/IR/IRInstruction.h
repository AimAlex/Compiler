//
//  IRInstruction.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/12.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef IRInstruction_h
#define IRInstruction_h
#include "Register.h"
#include <vector>
class BasicBlock;
class IRInstruction : public std::enable_shared_from_this<IRInstruction>{
public:
    std::shared_ptr<BasicBlock> curBlock = NULL;
    std::shared_ptr<IRInstruction> prev = NULL;
    std::shared_ptr<IRInstruction> next = NULL;
    bool removed = false;
    std::vector<Register> usedReg;
    std::vector<Register> usedIntValue;
    IRInstruction(std::shared_ptr<BasicBlock> curBB) {
        curBlock = curBB;
    }
    void linkNext(std::shared_ptr<IRInstruction> node) {
        next = node;
        node -> prev = shared_from_this();
    }
    virtual std::string getType();
    virtual std::shared_ptr<BasicBlock> getThen();
    virtual std::shared_ptr<BasicBlock> getElse();
    virtual std::shared_ptr<BasicBlock> getTarget();
};

#endif /* IRInstruction_h */
