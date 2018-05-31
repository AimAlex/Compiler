//
//  StaticSpace.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/12.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef StaticSpace_h
#define StaticSpace_h
#include "Register.h"
class StaticSpace : public Register, public std::enable_shared_from_this<StaticSpace>{
public:
    std::string hintName;
    int length;
    StaticSpace(std::string str, int l){
        hintName = str;
        length = l;
    }
    std::string getHintName(){
        return hintName;
    }
    void visited(std::shared_ptr<IRVisitor> visitor){
        visitor -> visit(shared_from_this());
    }
};

#endif /* StaticSpace_h */
