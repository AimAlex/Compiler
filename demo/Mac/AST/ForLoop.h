#ifndef ForLoop_h
#define ForLoop_h
#include "State.h"
#include "Expr.h"
#include "VariableDecl.h"
#include <vector>
class ForLoop : public State{
public:
    size_t position;
    std::vector<std::shared_ptr<VariableDecl>> initWithDecl;
    std::shared_ptr<Expr> init;
    std::shared_ptr<Expr> cond;
    std::shared_ptr<Expr> step;
    std::shared_ptr<State> body;
};
