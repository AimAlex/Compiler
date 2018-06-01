//
//  PhysicalRegister.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/12.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef PhysicalRegister_h
#define PhysicalRegister_h
#include "Register.h"
class PhysicalRegister : public Register, public std::enable_shared_from_this<PhysicalRegister>{
public:
    std::string name;
    PhysicalRegister(std::string str){
        name = str;
    }
    void visited(std::shared_ptr<IRVisitor> visitor){
        visitor -> visit(shared_from_this());
    }
};

#endif /* PhysicalRegister_h */
