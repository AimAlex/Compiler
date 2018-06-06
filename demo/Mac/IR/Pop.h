//
//  Pop.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/6/6.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef Pop_h
#define Pop_h
class Pop : public IRInstruction {
public:
    std::string getType(){
        return "Pop";
    }
    void visited(std::shared_ptr<IRVisitor> visitor){
        visitor -> visit(std::dynamic_pointer_cast<Load>(shared_from_this()));
    }
};



#endif /* Pop_h */
