//
//  Return.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/12.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef Return_h
#define Return_h
class Return : public Branch {
public:
    std::shared_ptr<IntValue> ret;
};

#endif /* Return_h */