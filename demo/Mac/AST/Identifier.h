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

class Identifier : public ASTNode{
    std::string name;
    size_t pos;
//    SymbolInfo symbolInfo;
    
};

#endif /* Identifier_h */
