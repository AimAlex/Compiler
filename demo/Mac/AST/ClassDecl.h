#ifndef ClassDecl_h
#define ClassDecl_h
#include "ASTNode.h"
#include <vector>
#include "VariableDecl.h"
#include "FunctionDecl.h"
#include "ClassConstructor.h"
class ClassDecl : public ASTNode{
public:
    size_t position;
    std::vector<std::shared_ptr<ASTNode>> variableMembers;
    std::vector<std::shared_ptr<ASTNode>> functionMembers;
    std::shared_ptr<ASTNode> classconstructor;
    std::string name;
    void acceptStr(std::string str) {
        name = str;
    }
    void acceptConstructor(std::shared_ptr<ASTNode> constructor){
        classconstructor = constructor;
    }
    void acceptFunction(std::vector<std::shared_ptr<ASTNode>> funcList){
        for(int i = 0; i < funcList.size(); ++i){
            functionMembers.push_back(funcList[i]);
        }
    }
    void accept(std::vector<std::shared_ptr<ASTNode>> vec){
        for(int i = 0; i < vec.size(); ++i){
            variableMembers.push_back(vec[i]);
        }
    }
    void visited(std::shared_ptr<ASTVisitor> visitor){
        visitor -> visit(std::shared_ptr<ClassDecl>(this));
    }
};

#endif
