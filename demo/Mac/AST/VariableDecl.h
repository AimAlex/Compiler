#ifndef VariableDecl_h
#define VariableDecl_h

#include "ASTNode.h"

class VariableDecl : public ASTNode, public std::enable_shared_from_this<VariableDecl>{
public:
    size_t position;
    std::shared_ptr <ASTNode> type;
    std::string name;
    std::shared_ptr<ASTNode> init;
    void accept(std::vector<std::shared_ptr<ASTNode>> ptr){
        type = ptr[0];
        init = ptr[1];
    }
    void acceptStr(std::string str){
        name = str;
    }
    void visited(std::shared_ptr<ASTVisitor> visitor){
        visitor -> visit(shared_from_this());
    }
    std::shared_ptr<SymbolType> getType(){
        return type -> getType();
    }
};

#endif
