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
    std::map<std::shared_ptr<VirtualRegister>, std::shared_ptr<PhysicalRegister>> mmp;
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
    std::shared_ptr<Register> getDefRegister(){
        return dest;
        
    }
    
    void setDefRegister(std::shared_ptr<Register> reg){
        dest = reg;
    }
    std::vector<std::shared_ptr<Register>> getRegister(){
        std::vector<std::shared_ptr<Register>> vec;
//        if(dest -> getType() == "VirtualRegister"){
//            vec.push_back(dest);
//        }
        for(int i = 0; i < args.size(); ++i){
            if(args[i] -> getType() == "VirtualRegister"){
                vec.push_back(args[i]);
            }
        }
        return vec;
    }
    
    void refreshRegister(std::map<std::shared_ptr<VirtualRegister>, std::shared_ptr<PhysicalRegister>> allocMap){
//        for(int i = 0; i < args.size(); ++i){
//            if(args[i] -> getType() == "VirtualRegister"){
//                args[i] = allocMap[std::dynamic_pointer_cast<VirtualRegister>(args[i])];
//            }
//        }
        for(std::map<std::shared_ptr<VirtualRegister>, std::shared_ptr<PhysicalRegister>>::iterator iter = allocMap.begin(); iter != allocMap.end(); ++iter){
            mmp[iter -> first] = iter -> second;
        }
    }
};
#endif /* Call_h */
