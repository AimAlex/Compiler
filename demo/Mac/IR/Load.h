//
//  Load.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/12.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef Load_h
#define Load_h
#include "IRInstruction.h"
class Load : public IRInstruction {
public:
    std::shared_ptr <Register> dest;
    int size;
    std::shared_ptr <Register> address;
    int offset;
    bool isStaticData;
    bool isLoadAddress;
    Load(std::shared_ptr<BasicBlock> Block, std::shared_ptr<Register> Dest, int n, std::shared_ptr<Register> Address, int Offset) : IRInstruction(Block){
        dest = Dest;
        size = n;
        address = Address;
        offset = Offset;
        isStaticData = false;
//        
    }
    void visited(std::shared_ptr<IRVisitor> visitor){
        visitor -> visit(std::dynamic_pointer_cast<Load>(shared_from_this()));
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
        if(address -> getType() == "VirtualRegister"){
            vec.push_back(address);
        }
        return vec;
    }
    void refreshRegister(std::map<std::shared_ptr<VirtualRegister>, std::shared_ptr<PhysicalRegister>> allocMap){
        if(address -> getType() == "VirtualRegister"){
            address = allocMap[std::dynamic_pointer_cast<VirtualRegister>(address)];
        }
    }
};

#endif /* Load_h */
