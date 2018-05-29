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
};

#endif /* IRRoot_h */
