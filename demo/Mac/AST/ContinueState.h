#ifndef ContinueState_h
#define ContinueState_h
#include "ASTNode.h"

class CoutinueState : public ASTNode {
public:
    size_t position;
    void accept(std::vector<std::shared_ptr<ASTNode>> /*ptr*/){
    }
};

#endif
