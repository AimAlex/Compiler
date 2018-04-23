#ifndef VariableDecl_h
#define VariableDecl_h

#include "Decl.h"
#include "Expr.h"
#include "TypeNode.h"
#include "StringConst.h"

class VariableDecl : public Decl{
public:
    size_t position;
    std::shared_ptr <ASTNode> type;
    std::string name;
    std::shared_ptr<ASTNode> init;
    void accept(std::vector<std::shared_ptr<ASTNode>> ptr){
        type = ptr[0];
        type = ptr[1];
    }
    void acceptStr(std::string str){
        name = str;
    }
};

#endif
