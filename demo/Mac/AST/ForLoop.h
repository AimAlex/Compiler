#ifndef ForLoop_h
#define ForLoop_h
#include "State.h"
#include "Expr.h"
#include "VariableDecl.h"
#include <vector>
class ForLoop : public State{
public:
    size_t position;
    std::vector<std::shared_ptr<ASTNode>> initWithDecl;
    std::shared_ptr<ASTNode> init;
    std::shared_ptr<ASTNode> cond;
    std::shared_ptr<ASTNode> step;
    std::shared_ptr<ASTNode> body;
    void accept(std::vector<std::shared_ptr<ASTNode>> ptr) {
        init = ptr[0];
        cond = ptr[1];
        step = ptr[2];
        body = ptr[3];
        for(int i = 4; i < ptr.size(); ++i) {
            initWithDecl.push_back(ptr[i]);
        }
    }
};
#endif
