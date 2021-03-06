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
    void visited(std::shared_ptr<IRVisitor> visitor){
        visitor -> visit(std::dynamic_pointer_cast<Return>(shared_from_this()));
    }
    std::shared_ptr<Register> getDefRegister(){
        return NULL;
        
    }
    std::vector<std::shared_ptr<Register>> getRegister(){
        std::vector<std::shared_ptr<Register>> vec;
        if(ret != NULL){
            if(ret -> getType() == "VirtualRegister"){
                vec.push_back(ret);
            }
        }
        return vec;
    }
    void refreshRegister(std::map<std::shared_ptr<VirtualRegister>, std::shared_ptr<PhysicalRegister>> allocMap){
        if(ret -> getType() == "VirtualRegister"){
            ret = allocMap[std::dynamic_pointer_cast<VirtualRegister>(ret)];
        }
    }
};

#endif /* Return_h */
