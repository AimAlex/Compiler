#ifndef IfState_h
#define IfState_h

#include "State.h"
#include "Expr.h"
class IfState : public State{
public:
    size_t position;
    std::shared_ptr <ASTNode> cond;
    std::shared_ptr <ASTNode> then;
    std::shared_ptr<ASTNode> otherwise;
    void accept(std::vector<std::shared_ptr<ASTNode>> ptr){
        cond = ptr[0];
        then = ptr[1];
        otherwise = ptr[2];
    }
};

#endif
