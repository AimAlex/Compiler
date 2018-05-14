//
//  StaticSpace.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/12.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef StaticSpace_h
#define StaticSpace_h
class StaticSpace : public Register{
public:
    std::string hintName;
    int length;
    StaticSpace(std::string str, int l){
        hintName = str;
        length = l;
    }
};

#endif /* StaticSpace_h */
