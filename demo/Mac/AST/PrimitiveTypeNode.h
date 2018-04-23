#ifndef PrimitiveTypeNode_h
#define PrimitiveTypeNode_h
#include "TypeNode.h"

class PrimitiveTypeNode : public TypeNode {
public:
    enum Types {
        INT, BOOL, STRING, VOID
    };
    Types type;
    PrimitiveTypeNode(Types ty){
        type = ty;
    }
    void accept(std::vector<std::shared_ptr<ASTNode>>){};
};

#endif
