#ifndef TypeNode_h
#define TypeNode_h
#include "ASTNode.h"

class TypeNode : public ASTNode {
public:
    virtual void accept(std::vector<std::shared_ptr<ASTNode>>) = 0;
	
};

#endif
