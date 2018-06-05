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
#include "Function.h"
#include <algorithm>
#include "IRVisitor.h"
#include <set>
class IRInstruction : public std::enable_shared_from_this<IRInstruction>{
public:
    std::shared_ptr<BasicBlock> curBlock = NULL;
    std::shared_ptr<IRInstruction> prev = NULL;
    std::shared_ptr<IRInstruction> next = NULL;
    bool removed = false;
//    std::vector<Register> usedReg;
//    std::vector<Register> usedIntValue;
    
    std::set<std::shared_ptr<Register>> liveIn;
    std::set<std::shared_ptr<Register>> liveOut;
    
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
            std::cout<<block -> hintName<<" Cannot append instruction after a basic block ends."<<std::endl;
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
    
    void cleanEnd(std::shared_ptr<BasicBlock> block) {
        block -> ended = false;
//        std::cout<<getType()<<std::endl;
        if (getType() == "Branch") {
            block -> delSuccessor(getThen());
            block -> delSuccessor(getElse());
        }
        else if (getType() ==  "Jump") {
            block -> delSuccessor(getTarget());
        }
        else if (getType() == "Return") {
            block -> parent -> retInstruction.erase(find(block -> parent -> retInstruction.begin(),block -> parent -> retInstruction.end(),shared_from_this()));
            
        } else {
            return;
        }
    }
    
    void remove() {
        if(removed) return;
        if (getType() == "Branch" || getType() == "Return" || getType() == "Jump") curBlock -> last -> cleanEnd(curBlock);
        if (prev != NULL) prev -> next = next;
        if (next != NULL) next -> prev = prev;
        if (curBlock -> head == shared_from_this()) curBlock -> head = next;
        if (curBlock -> last == shared_from_this()) curBlock -> last = prev;
        removed = true;
    }
    
    virtual std::string getType(){return "";}
    virtual std::shared_ptr<BasicBlock> getThen(){return NULL;}
    virtual std::shared_ptr<BasicBlock> getElse(){return NULL;}
    virtual std::shared_ptr<BasicBlock> getTarget(){return NULL;}
    virtual void addReturn(std::shared_ptr<Function>){return ;}
    virtual void visited(std::shared_ptr<IRVisitor>){}
    virtual std::shared_ptr<Register> getDefRegister(){return NULL;}
    virtual std::vector<std::shared_ptr<Register>> getRegister(){std::vector<std::shared_ptr<Register>> vec;
        return vec;
    }
};

#endif /* IRInstruction_h */
