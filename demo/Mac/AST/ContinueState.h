#ifndef ContinueState_h
#define ContinueState_h
#include "State.h"

class CoutinueState : public State {
public:
    size_t position;
    void accept(std::vector<std::shared_ptr<ASTNode>> /*ptr*/){
    }
};

#endif
