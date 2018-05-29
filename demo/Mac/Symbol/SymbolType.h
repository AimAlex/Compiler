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
    virtual int getDemension(){return 0;}
    virtual std::vector<std::shared_ptr<SymbolType>> getFunction(){std::vector<std::shared_ptr<SymbolType>> vec; return vec;}
    virtual int getsize(){
        return 0;
    }
    bool sameType(std::shared_ptr<SymbolType> ptr){
        if(this -> type == Null && ptr -> type == ClASS){
            return 1;
        }
        if(this -> type == Null && ptr -> getDemension()  != 0){
            return 1;
        }
        if(ptr == NULL) {
            return 0;
        }
        if(this -> type == ClASS && ptr -> type == Null) {
            return 1;
        }
        if(this -> getDemension() != 0 && ptr -> type == Null) {
            return 1;
        }
        if(ptr -> type != this -> type){
            return 0;
        }
        if(ptr -> type == ClASS && ptr -> getName() != this -> getName()){
            return 0;
        }
        if(ptr -> getDemension() != this -> getDemension()){
            return 0;
        }
        return 1;
    }
};

#endif /* SymbolType_h */
