#ifndef State_h
#define State_h
#include "ASTNode.h"

class State : public ASTNode {
public:
    virtual void accept(std::vector<std::shared_ptr<ASTNode>>) = 0;
};

#endif
