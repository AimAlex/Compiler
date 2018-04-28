#ifndef VariableDecl_h
#define VariableDecl_h

#include "ASTNode.h"

class VariableDecl : public ASTNode{
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
        visitor -> visit(std::shared_ptr<VariableDecl>(this));
    }
};

#endif
