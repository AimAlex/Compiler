//
//  ArrayType.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/4/29.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef ArrayType_h
#define ArrayType_h
#include "SymbolNode.h"
class ArrayType : public SymbolNode{
public:
    std::string name;
    Types type;
    int demension;
};

#endif /* ArrayType_h */
