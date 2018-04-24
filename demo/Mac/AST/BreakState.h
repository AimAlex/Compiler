#ifndef BreakState_h
#define BreakState_h
#include "ASTNode.h"

class BreakState : public ASTNode{
public:
    size_t position;
    void accept(std::vector<std::shared_ptr<ASTNode>> /*ptr*/){
    }
};

#endif
