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
class Function;
class BasicBlock{
public:
    std::shared_ptr<IRInstruction> head = NULL;
    std::shared_ptr<IRInstruction> last = NULL;
    bool ended = false;
    std::string hintName;
    std::shared_ptr<Function> parent;
    std::map<std::shared_ptr<Register>, std::shared_ptr<IRInstruction>> phi;
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
    
//    void end(std::shared_ptr<IRInstruction> next) {
//        append(next);
//        ended = true;
//        if (next instanceof Branch) {
//            addSucc(((Branch) next).getThen());
//            addSucc(((Branch) next).getElse());
//        } else if (next instanceof Jump) {
//            addSucc(((Jump) next).getTarget());
//        } else if (next instanceof Return) {
//            parent.retInstruction.add((Return) next);
//        } else {
//            assert false;
//        }
//    }
};

#endif /* BasicBlock_h */
