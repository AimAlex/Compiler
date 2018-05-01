//
//  ClassTypeNode.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/4/25.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef ClassTypeNode_h
#define ClassTypeNode_h
#include "ASTNode.h"

class ClassTypeNode : public ASTNode, public std::enable_shared_from_this<ClassTypeNode> {
public:
    std::string name;
    ClassTypeNode(std::string str) {
        name = str;
    }
    void visited(std::shared_ptr<ASTVisitor> visitor){
        visitor -> visit(shared_from_this());
    }
    std::string gettype(){
        return name;
    }
    std::shared_ptr<SymbolType> getType(){
        std::shared_ptr<SymbolType> ptr (new VariableType(name, 0));
        ptr -> type = SymbolType::ClASS;
        return ptr;
    }
};

#endif /* ClassTypeNode_h */
