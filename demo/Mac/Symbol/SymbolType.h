//
//  SymbolType.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/4/30.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef SymbolType_h
#define SymbolType_h
class SymbolType{
public:
    
    enum Types {
        INT, BOOL, STRING, VOID, ARRAY, ClASS, FUNCTION, Null, CONSTRUCT, CLASSTYPE
    };
    Types type;
    virtual std::string getName(){return "NULL";}
};

#endif /* SymbolType_h */
