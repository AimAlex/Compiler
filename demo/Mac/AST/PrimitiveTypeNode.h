#ifndef PrimitiveTypeNode_h
#define PrimitiveTypeNode_h

#include "ASTNode.h"

class PrimitiveTypeNode : public ASTNode, public std::enable_shared_from_this<PrimitiveTypeNode>{
public:
    enum Types {
        INT, BOOL, STRING, VOID
    };
    Types type;
    PrimitiveTypeNode(Types ty){
        type = ty;
    }
    void visited(std::shared_ptr<ASTVisitor> visitor){
        visitor -> visit(shared_from_this());
    }
};

#endif
