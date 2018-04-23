#ifndef Expr_h
#define Expr_h
#include "State.h"

class Expr : public State{
public:
    virtual void accept(std::vector<std::shared_ptr<ASTNode>>) = 0;
};

#endif
