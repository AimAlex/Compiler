#ifndef WhileLoop_h
#define WhileLoop_h
#include "State.h"
#include "Expr.h"
class WhileLoop : public State{
public:
    size_t Position;
    std::shared_ptr<ASTNode> cond;
    std::shared_ptr<ASTNode> body;
    void accept(std::vector<std::shared_ptr<ASTNode>> ptr) {
        cond = ptr[0];
        body = ptr[1];
    }
};

#endif
