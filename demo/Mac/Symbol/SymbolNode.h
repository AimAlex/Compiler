//
//  SymbolNode.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/4/29.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef SymbolNode_h
#define SymbolNode_h
class SymbolTable;
class SymbolNode{
public:
    enum Types {
        INT, BOOL, STRING, VOID, ARRAY, ClASS, FUNCTION, Null
    };
    std::shared_ptr<SymbolTable> table;
};

#endif /* SymbolNode_h */
