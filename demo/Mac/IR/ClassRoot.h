//
//  ClassRoot.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/29.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef ClassRoot_h
#define ClassRoot_h
#include <map>
#include "Function.h"
#include "Register.h"
#include "IRVisitor.h"
class ClassRoot : public std::enable_shared_from_this<ClassRoot>{
public:
    std::string name;
    int size;
    std::map<std::string, std::shared_ptr<Function>> functions;
    std::shared_ptr<Function> constructor;
    std::shared_ptr<Register> reg;
    void visited(std::shared_ptr<IRVisitor> visitor){
        visitor -> visit(shared_from_this());
    }
    ClassRoot(std::string str){
        name = str;
    }
};

#endif /* ClassRoot_h */
