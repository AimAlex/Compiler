//
//  Return.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/12.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef Return_h
#define Return_h
#include "Function.h"
class Return : public IRInstruction {
public:
    std::shared_ptr<Register> ret;
    
    std::string getType(){
        return "Return";
    }
    
    Return(std::shared_ptr<BasicBlock> BB, std::shared_ptr<Register> reg): IRInstruction(BB){
        ret = reg;
    }
    
    void addReturn(std::shared_ptr<Function> func){
        func -> retInstruction.push_back(std::dynamic_pointer_cast<Return>(shared_from_this()));
    }
};

#endif /* Return_h */
