//
//  IRRoot.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/12.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef IRRoot_h
#define IRRoot_h
#include <map>
#include "Function.h"
#include "IntValue.h"
class IRRoot{
public:
    std::map<std::string, std::shared_ptr<Function>> functions;
    std::map<std::string, std::shared_ptr<IntValue>> strings;
    std::map<std::string, std::shared_ptr<IntValue>> dataList;
};

#endif /* IRRoot_h */
