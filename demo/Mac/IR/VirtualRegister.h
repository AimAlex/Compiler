//
//  VirtualRegister.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/12.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef VirtualRegister_h
#define VirtualRegister_h
class VirtualRegister : public Register, public std::enable_shared_from_this<VirtualRegister>{
public:
    std::string hintName;
    int ssaId = -1;
    std::shared_ptr<Register> oldName = NULL;
    std::shared_ptr<Register> physicalRegister = NULL;
    VirtualRegister(std::string str){
        hintName = str;
    }
    void visited(std::shared_ptr<IRVisitor> visitor){
        visitor -> visit(shared_from_this());
    }
    std::string getType(){
        return "VirtualRegister";
    }
    std::string getHintName(){
        return hintName;
        
    }
};

#endif /* VirtualRegister_h */
