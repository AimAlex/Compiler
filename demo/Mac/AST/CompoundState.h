#ifndef CompoundState_h
#define CompoundState_h
#include <vector>
#include "ASTNode.h"
class CompoundState : public ASTNode, public std::enable_shared_from_this<CompoundState>{
public:
    std::vector<std::shared_ptr<ASTNode>> stmts;
    void accept(std::vector<std::shared_ptr<ASTNode>> ptr) {
        for(int i = 0; i < ptr.size(); ++i) {
            stmts.push_back(ptr[i]);
        }
    }
    void visited(std::shared_ptr<ASTVisitor> visitor){
        visitor -> visit(shared_from_this());
    }
};

#endif
