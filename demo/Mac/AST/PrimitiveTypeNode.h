#ifndef PrimitiveTypeNode_h
#define PrimitiveTypeNode_h

#include "ASTNode.h"

class PrimitiveTypeNode : public ASTNode, public std::enable_shared_from_this<PrimitiveTypeNode>{
public:
    enum Types {
        INT, BOOL, STRING, VOID
    };
    Types type;
    PrimitiveTypeNode(Types ty){
        type = ty;
    }
    void visited(std::shared_ptr<ASTVisitor> visitor){
        visitor -> visit(shared_from_this());
    }
    std::string gettype(){
        if(type == INT){
            return "int";
        }
        else if(type == BOOL){
            return "bool";
        }
        else if(type == STRING){
            return "string";
        }
        else{
            return "void";
        }
    }
    std::shared_ptr<SymbolType> getType(){
        if(type == INT){
            std::shared_ptr<SymbolType> ptr (new VariableType("int", 0));
            ptr -> type = SymbolType::INT;
            return ptr;
        }
        else if(type == BOOL){
            std::shared_ptr<SymbolType> ptr (new VariableType("bool", 0));
            ptr -> type = SymbolType::BOOL;
            return ptr;
        }
        else if(type == STRING){
            std::shared_ptr<SymbolType> ptr (new VariableType("string", 0));
            ptr -> type = SymbolType::STRING;
            return ptr;
        }
        else if(type == VOID){
            std::shared_ptr<SymbolType> ptr (new VariableType("void", 0));
            ptr -> type = SymbolType::VOID;
            return ptr;
        }
        else{
            std::shared_ptr<SymbolType> ptr (new VariableType("class", 0));
            ptr -> type = SymbolType::ClASS;
            return ptr;
        }
    }
};

#endif
