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
#include "Register.h"
#include "IRVisitor.h"
#include "ClassRoot.h"
class IRRoot : public std::enable_shared_from_this<IRRoot>{
public:
    std::map<std::string, std::shared_ptr<Function>> functions;
    std::map<std::string, std::shared_ptr<Register>> strings;
    std::vector<std::shared_ptr<Register>> dataList;
    std::map<std::string, std::shared_ptr<ClassRoot>> classList;
    void visited(std::shared_ptr<IRVisitor> visitor){
        visitor -> visit(shared_from_this());
    }
    std::shared_ptr<Function> builtinPrintString;
    std::shared_ptr<Function> builtinPrintlnString;
    std::shared_ptr<Function> builtinPrintInt;
    std::shared_ptr<Function> builtinPrintlnInt;
    std::shared_ptr<Function> builtinToString;
    std::shared_ptr<Function> builtinGetString;
    std::shared_ptr<Function> builtinGetInt;
    std::shared_ptr<Function> builtinStringConcat;
    std::shared_ptr<Function> builtinStringEqual;
    std::shared_ptr<Function> builtinStringLess;
    std::shared_ptr<Function> builtinStringParseInt;
    std::shared_ptr<Function> builtinStringSubString;
};

#endif /* IRRoot_h */
