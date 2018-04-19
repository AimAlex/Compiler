#ifndef WhileLoop_h
#define WhileLoop_h
#include "State.h"
#include "Expr"
class WhileLoop : public State{
public:
    size_t Position;
    shared_ptr<Expr> cond;
    shared_ptr<Expr> body;
};

#endif
