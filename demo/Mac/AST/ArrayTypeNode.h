#ifndef ArrayTypeNode_h
#define ArrayTypeNode_h

#include "ASTNode.h"
#include <vector>
class ArrayTypeNode : public ASTNode{
public:
    std::shared_ptr<ASTNode> type;
    int demension;
    void accept(std::vector<std::shared_ptr<ASTNode>> vec){
        type = vec[0];
    }
    void acceptNum(int i) {
        demension = i;
    }
};

#endif
