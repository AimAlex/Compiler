#ifndef BreakState_h
#define BreakState_h
#include "State.h"

class BreakState : public State{
public:
    size_t position;
    void accept(std::vector<std::shared_ptr<ASTNode>> /*ptr*/){
    }
};

#endif
