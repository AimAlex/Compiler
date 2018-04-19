#ifndef IfState_h
#define IfState_h

#include "State.h"
#include "Expr.h"
class IfState : public State{
public:
    size_t position;
    std::shared_ptr <Expr> cond;
    std::shared_ptr <State> then;
    std::shared_ptr<State> otherwise;
};

#endif
