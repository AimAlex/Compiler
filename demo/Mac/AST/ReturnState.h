#ifndef ReturnState_h
#define ReturnState_h
#include "Expr.h"

class ReturnState : public State {
public:
    std::shared_ptr<Expr> value;
    size_t position;
};


#endif
