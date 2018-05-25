//
//  IntImmediate.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/12.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef IntImmediate_h
#define IntImmediate_h
class IntImmediate : public Register, public std::enable_shared_from_this<IntImmediate>{
public:
    int value;
    IntImmediate(int v){
        value = v;
    }
    void visited(std::shared_ptr<IRVisitor> visitor){
        visitor -> visit(shared_from_this());
    }
};

#endif /* IntImmediate_h */
