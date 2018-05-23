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
#include "BasicBlock.h"
class Function;
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
    
    void prepend(std::shared_ptr<IRInstruction> node){
        if(prev != NULL) {
            prev -> linkNext(node);
        }
        else{
            curBlock -> head = node;
        }
        node -> linkNext(shared_from_this());
    }
    
    void append(std::shared_ptr<BasicBlock> block) {
        if (block -> ended) {
            std::cout<<"Cannot append instruction after a basic block ends."<<std::endl;
            throw (0);
        }
        if (block -> last != NULL) {
            block -> last -> linkNext(shared_from_this());
            block -> last = shared_from_this();
        } else {
            block -> head = block -> last = shared_from_this();
        }
    }
    
    void end(std::shared_ptr<BasicBlock> block) {
        append(block);
        block -> ended = true;
        std::string str = getType();
        if (str == "Branch") {
            block -> addSuccessor(getThen());
            block -> addSuccessor(getElse());
        }
        else if (str == "Jump") {
            block -> addSuccessor(getTarget());
        }
        else if (str == "Return") {
            addReturn(block -> parent);
        }
        else {
            return;
        }
    }
    
    virtual std::string getType();
    virtual std::shared_ptr<BasicBlock> getThen();
    virtual std::shared_ptr<BasicBlock> getElse();
    virtual std::shared_ptr<BasicBlock> getTarget();
    virtual void addReturn(std::shared_ptr<Function>);
};

#endif /* IRInstruction_h */
