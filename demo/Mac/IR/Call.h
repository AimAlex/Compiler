//
//  Call.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/28.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef Call_h
#define Call_h
#include "IRInstruction.h"
class Call : public IRInstruction{
public:
    std::shared_ptr<Register> dest;
    std::shared_ptr<Function> func;
    std::vector<std::shared_ptr<Register>> args;
    Call (std::shared_ptr<BasicBlock> Block, std::shared_ptr<Register> Dest, std::shared_ptr<Function> Func) : IRInstruction(Block){
        dest = Dest;
        func = Func;
    }
    
    std::string getType(){
        return "Call";
    }
    
    void visited(std::shared_ptr<IRVisitor> visitor){
        visitor -> visit(std::dynamic_pointer_cast<Call>(shared_from_this()));
    }
};
#endif /* Call_h */
