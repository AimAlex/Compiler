#ifndef Decl_h
#define Decl_h
#include "ASTNode.h"
class Decl : public ASTNode {
public:
	virtual void accept(std::vector<std::shared_ptr<ASTNode>>) = 0;
    virtual void acceptStr(std::string);
};

#endif
