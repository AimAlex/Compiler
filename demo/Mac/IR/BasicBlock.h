//
//  BasicBlock.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/12.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef BasicBlock_h
#define BasicBlock_h
#include <map>
#include "Register.h"
#include "IRInstruction.h"
#include "Function.h"
class BasicBlock : public std::enable_shared_from_this<BasicBlock>{
public:
    std::shared_ptr<IRInstruction> head = NULL;
    std::shared_ptr<IRInstruction> last = NULL;
    bool ended = false;
    std::string hintName;
    std::shared_ptr<Function> parent;
    std::map<std::shared_ptr<Register>, std::shared_ptr<IRInstruction>> phi;
    std::vector<std::shared_ptr<BasicBlock>> successor;
    std::vector<std::shared_ptr<BasicBlock>> predecessor;
    BasicBlock(std::shared_ptr<Function> func, std::string str) {
        parent = func;
        if(str == ""){
            hintName = "block";
        }
        else{
            hintName = str;
        }
    }
    
    void append(std::shared_ptr<IRInstruction> next) {
        if (ended) {
            std::cout<<"Cannot append instruction after a basic block ends."<<std::endl;
            throw (0);
        }
        if (last != NULL) {
            last -> linkNext(next);
            last = next;
        } else {
            head = last = next;
        }
    }
    
    void end(std::shared_ptr<IRInstruction> next) {
        append(next);
        ended = true;
        std::string str = next -> getType();
        if (str == "Branch") {
            addSuccessor(next
                         -> getThen());
            addSuccessor(next -> getElse());
        } else if (str == "Jump") {
            addSuccessor(next -> getTarget());
        } else if (str == "Return") {
            parent -> retInstruction.push_back(next);
        } else {
            return;
        }
    }
    
    void addSuccessor(std::shared_ptr<BasicBlock> BB) {
        if (BB == NULL) return;
        successor.push_back(BB);
        BB -> predecessor.push_back(shared_from_this());
    }
};

#endif /* BasicBlock_h */
