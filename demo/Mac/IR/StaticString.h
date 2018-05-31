//
//  StaticString.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/12.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef StaticString_h
#define StaticString_h
#include "Register.h"
class StaticString : public Register , public std::enable_shared_from_this<StaticString>{
public:
    std::string hintName;
    std::string value;
    StaticString(std::string str){
        hintName = "string";
        value = str;
    }
    std::string getHintName(){
        return hintName;
    }
    void visited(std::shared_ptr<IRVisitor> visitor){
        visitor -> visit(shared_from_this());
    }
};

#endif /* StaticString_h */
