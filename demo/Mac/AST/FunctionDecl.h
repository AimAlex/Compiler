#ifndef FunctionDecl_h
#define FunctionDecl_h
#include "ASTNode.h"
#include <vector>
#include "VariableDecl.h"
#include "CompoundState.h"
class FunctionDecl : public ASTNode, public std::enable_shared_from_this<FunctionDecl>{
public:
    size_t position;
    std::string name;
    std::shared_ptr<ASTNode> returnType;
    std::vector<std::shared_ptr<ASTNode>> parameterList;
    std::shared_ptr<ASTNode> body;
    std::shared_ptr<SymbolTable> functionTable;
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
    void visited(std::shared_ptr<ASTVisitor> visitor){
        visitor -> visit(shared_from_this());
    }
};

#endif
