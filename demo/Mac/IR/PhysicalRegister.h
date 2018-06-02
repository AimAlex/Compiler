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
    int no;
    PhysicalRegister(std::string str){
        name = str;
        if(str == "rax"){
            no = 0;
        }
        else if(str == "rbx"){
            no = 1;
        }
        else if(str == "rcx"){
            no = 2;
        }
        else if(str == "rdx"){
            no = 3;
        }
        else if(str == "rsi"){
            no = 4;
        }
        else if(str == "rdi"){
            no = 5;
        }
        else if(str == "rbp"){
            no = 6;
        }
        else if(str == "rsp"){
            no = 7;
        }
        else if(str == "r8"){
            no = 8;
        }
        else if(str == "r9"){
            no = 9;
        }
        else if(str == "r10"){
            no = 10;
        }
        else if(str == "r11"){
            no = 11;
        }
        else if(str == "r12"){
            no = 12;
        }
        else if(str == "r13"){
            no = 13;
        }
        else if(str == "r14"){
            no = 14;
        }
        else {
            no = 15;
        }
//            case "rax":
//                no = //return value;
//            RegisterName[1] = "rbx";
//            RegisterName[2] = "rcx";//par 4
//            RegisterName[3] = "rdx";//par 3
//            RegisterName[4] = "rsi";//par 2
//            RegisterName[5] = "rdi";//par 1
//            RegisterName[6] = "rbp";
//            RegisterName[7] = "rsp";
//            RegisterName[8] = "r8";//par 5
//            RegisterName[9] = "r9";//par 6
//            RegisterName[10] = "r10";
//            RegisterName[11] = "r11";
//            RegisterName[12] = "r12";
//            RegisterName[13] = "r13";
//            RegisterName[14] = "r14";
//            RegisterName[15] = "r15";
    }
    
    PhysicalRegister(int n){
        no = n;
        switch (n) {
            case 0:
                name = "rax";
                break;
            case 1:
                name = "rbx";
                break;
            case 2:
                name = "rcx";
                break;
            case 3:
                name = "rdx";
                break;
            case 4:
                name = "rsi";
                break;
            case 5:
                name = "rdi";
                break;
            case 6:
                name = "rbp";
                break;
            case 7:
                name = "rsp";
                break;
            case 8:
                name = "r8";
                break;
            case 9:
                name = "r9";
                break;
            case 10:
                name = "r10";
                break;
            case 11:
                name = "r11";
                break;
            case 12:
                name = "r12";
                break;
            case 13:
                name = "r13";
                break;
            case 14:
                name = "r14";
                break;
            case 15:
                name = "r15";
                break;
        }
    }
    void visited(std::shared_ptr<IRVisitor> visitor){
        visitor -> visit(shared_from_this());
    }
    std::string getHintName(){
        return name;
    }
    std::string getType(){
        return "PhysicalRegister";
    }
};

#endif /* PhysicalRegister_h */
