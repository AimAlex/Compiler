#ifndef VariableDecl_h
#define VariableDecl_h

#include "Decl.h"
#include "Expr.h"
#include "TypeNode.h"

class VariableDecl : public Decl{
public:
    size_t position;
    std::shared_ptr <TypeNode> type;
    std::string name;
    std::shared_ptr<Expr> init;
};

#endif
