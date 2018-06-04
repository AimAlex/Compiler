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
    IRRoot(){
        builtinPrintString  = std::shared_ptr<Function>(new Function(std::shared_ptr<FunctionType>(new FunctionType("print")))) ;
        builtinPrintlnString  = std::shared_ptr<Function>(new Function(std::shared_ptr<FunctionType>(new FunctionType("println"))));
        builtinPrintInt  = std::shared_ptr<Function>(new Function(std::shared_ptr<FunctionType>(new FunctionType("printint"))));
        builtinPrintlnInt  = std::shared_ptr<Function>(new Function(std::shared_ptr<FunctionType>(new FunctionType("printintln"))));
        builtinToString  = std::shared_ptr<Function>(new Function(std::shared_ptr<FunctionType>(new FunctionType("toString"))));
        builtinGetString  = std::shared_ptr<Function>(new Function(std::shared_ptr<FunctionType>(new FunctionType("getString"))));
        builtinGetInt  = std::shared_ptr<Function>(new Function(std::shared_ptr<FunctionType>(new FunctionType("getInt"))));
        builtinStringConcat  = std::shared_ptr<Function>(new Function(std::shared_ptr<FunctionType>(new FunctionType("string.add"))));
        builtinStringEqual  = std::shared_ptr<Function>(new Function(std::shared_ptr<FunctionType>(new FunctionType("string.eq"))));
        builtinStringLess  = std::shared_ptr<Function>(new Function(std::shared_ptr<FunctionType>(new FunctionType("string.le"))));
        builtinStringParseInt  = std::shared_ptr<Function>(new Function(std::shared_ptr<FunctionType>(new FunctionType("string.parseInt"))));
        builtinStringSubString  = std::shared_ptr<Function>(new Function(std::shared_ptr<FunctionType>(new FunctionType("string.substring"))));
        buildinStringLength  = std::shared_ptr<Function>(new Function(std::shared_ptr<FunctionType>(new FunctionType("string.length"))));
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
    std::shared_ptr<Function> buildinStringLength;
};

#endif /* IRRoot_h */
