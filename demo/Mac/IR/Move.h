//
//  Move.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/12.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef Move_h
#define Move_h
#include "IRInstruction.h"
class Move : public IRInstruction {
public:
    std::shared_ptr<Register> dest;
    std::shared_ptr<Register> source;
    Move(std::shared_ptr<BasicBlock> BB, std::shared_ptr<Register> destination, std::shared_ptr<Register> sour) : IRInstruction(BB){
        dest = destination;
        source = sour;
//        reloadUsedRegisterCollection();
    }
    void visited(std::shared_ptr<IRVisitor> visitor){
        visitor -> visit(std::dynamic_pointer_cast<Move>(shared_from_this()));
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
        if(source -> getType() == "VirtualRegister"){
            vec.push_back(source);
        }
        return vec;
    }
    
    void refreshRegister(std::map<std::shared_ptr<VirtualRegister>, std::shared_ptr<PhysicalRegister>> allocMap){
        if(source -> getType() == "VirtualRegister"){
            source = allocMap[std::dynamic_pointer_cast<VirtualRegister>(source)];
        }
    }
};

#endif /* Move_h */
