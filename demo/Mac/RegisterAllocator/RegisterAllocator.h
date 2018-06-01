//
//  RegisterAllocator.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/6/1.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef RegisterAllocator_h
#define RegisterAllocator_h
#include <vector>
class RegisterAllocator{
public:
    std::vector<std::string>  RegisterName;
    RegisterAllocator(){
        RegisterName[0] = "%rax";//return value;
        RegisterName[1] = "%rbx";
        RegisterName[2] = "%rcx";//par 4
        RegisterName[3] = "%rdx";//par 3
        RegisterName[4] = "%rsi";//par 2
        RegisterName[5] = "%rdi";//par 1
        RegisterName[6] = "%rbp";
        RegisterName[7] = "%rsp";
        RegisterName[8] = "%r8";//par 5
        RegisterName[9] = "%r9";//par 6
        RegisterName[10] = "%r10";
        RegisterName[11] = "%r11";
        RegisterName[12] = "%r12";
        RegisterName[13] = "%r13";
        RegisterName[14] = "%r14";
        RegisterName[15] = "%r15";
    }
};

#endif /* RegisterAllocator_h */
