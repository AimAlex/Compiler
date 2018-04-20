//
//  MemberAccess.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/4/20.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef MemberAccess_h
#define MemberAccess_h
class MemberAccess{
    std::shared_ptr <Expr> record;
    std::string member;
    size_t position;
    
};

#endif /* MemberAccess_h */
