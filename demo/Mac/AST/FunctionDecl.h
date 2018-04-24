#ifndef FunctionDecl_h
#define FunctionDecl_h
#include "ASTNode.h"
#include <vector>
#include "VariableDecl.h"
#include "CompoundState.h"
class FunctionDecl : public ASTNode{
public:
    size_t position;
    std::string name;
    std::shared_ptr<ASTNode> returnType;
    std::vector<std::shared_ptr<ASTNode>> parameterList;
    std::shared_ptr<ASTNode> body;
//    FunctionType functiontype;
    void acceptStr(std::string str) {
        name = str;
    }
    void accept(std::vector<std::shared_ptr<ASTNode>> vec) {
        returnType = vec[0];
        body = vec[1];
    }
    void acceptFunction(std::vector<std::shared_ptr<ASTNode>> vec){
        for(int i = 0; i < vec.size(); ++i){
            parameterList.push_back(vec[i]);
        }
    }
};

#endif
