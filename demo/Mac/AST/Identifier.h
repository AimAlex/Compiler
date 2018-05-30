//
//  Identifier.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/4/19.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef Identifier_h
#define Identifier_h
#include "ASTNode.h"

class Identifier : public ASTNode, public std::enable_shared_from_this<Identifier>{
public:
    std::string name;
    size_t pos;
    std::shared_ptr<SymbolNode> info;
    void acceptStr(std::string str){
        name = str;
    }
    void visited(std::shared_ptr<ASTVisitor> visitor){
        visitor -> visit(shared_from_this());
    }
    
    bool needMemoryAccess(){
        if(this -> info -> table -> memorysize > 0){
            return true;
        }
        return false;
    }
};

#endif /* Identifier_h */
