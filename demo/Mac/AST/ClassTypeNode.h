#ifndef ClassTypeNode_h
#define ClassTypeNode_h
#include "ASTNode.h"

class ClassTypeNode : public ASTNode {
public:
    std::string name;
    ClassTypeNode(std::string str) {
        name = str;
    }
    void accept(std::vector<std::shared_ptr<ASTNode>>){};
};
#endif
