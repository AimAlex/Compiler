//
//  Branch.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/12.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef Branch_h
#define Branch_h
#include "IRInstruction.h"
class Branch : public IRInstruction{
public:
    std::shared_ptr<Register> cond;
    std::shared_ptr<BasicBlock> then;
    std::shared_ptr<BasicBlock> otherwise;
    
    std::string getType(){
        return "Branch";
    }
    
    std::shared_ptr<BasicBlock> getThen(){
        return then;
    }
    
    std::shared_ptr<BasicBlock> getElse(){
        return otherwise;
    }
    
    Branch (std::shared_ptr<BasicBlock> Block, std::shared_ptr<Register> Cond, std::shared_ptr<BasicBlock> Then, std::shared_ptr<BasicBlock> Otherwise) :IRInstruction(Block){
        cond = Cond;
        then = Then;
        otherwise = Otherwise;
    }
    void visited(std::shared_ptr<IRVisitor> visitor){
        visitor -> visit(std::dynamic_pointer_cast<Branch>(shared_from_this()));
    }
};

#endif /* Branch_h */
