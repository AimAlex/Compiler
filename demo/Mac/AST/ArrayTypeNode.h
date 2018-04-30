#ifndef ArrayTypeNode_h
#define ArrayTypeNode_h

#include "ASTNode.h"
#include <vector>
class ArrayTypeNode : public ASTNode, public std::enable_shared_from_this<ArrayTypeNode>{
public:
    std::shared_ptr<ASTNode> type;
    int demension;
    void accept(std::vector<std::shared_ptr<ASTNode>> vec){
        type = vec[0];
    }
    void acceptNum(int i) {
        demension = i;
    }
    void visited(std::shared_ptr<ASTVisitor> visitor){
        visitor -> visit(shared_from_this());
    }
    std::shared_ptr<SymbolType> getType(){
        std::string t = type -> gettype();
        std::shared_ptr<SymbolType> ptr (new VariableType(t, demension));
        if(t == "int"){
            ptr -> type = SymbolType::INT;
        }
        else if(t == "bool"){
            ptr -> type = SymbolType::BOOL;
        }
        else if(t == "string"){
            ptr -> type = SymbolType::STRING;
        }
        else if(t == "void"){
            ptr -> type = SymbolType::VOID;
        }
        else{
            ptr -> type = SymbolType::ClASS;
        }
        return ptr;
    }
};

#endif
