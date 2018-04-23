#ifndef ReturnState_h
#define ReturnState_h
#include "Expr.h"

class ReturnState : public State {
public:
    std::shared_ptr<ASTNode> value;
    size_t position;
    void accept(std::vector<std::shared_ptr<ASTNode>> ptr){
        value = ptr[0];
    }
};


#endif
