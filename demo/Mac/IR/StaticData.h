//
//  StaticData.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/12.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef StaticData_h
#define StaticData_h
class StaticData : public Register, public std::enable_shared_from_this<StaticData>{
public:
    std::string hintName;
    void visited(std::shared_ptr<IRVisitor> visitor){
        visitor -> visit(shared_from_this());
    }
    std::string getHintName(){
        return hintName;
    }
};

#endif /* StaticData_h */
