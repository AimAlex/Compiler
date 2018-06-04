//
//  StaticString.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/12.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef StaticString_h
#define StaticString_h
#include "Register.h"
class StaticString : public Register , public std::enable_shared_from_this<StaticString>{
public:
    std::string hintName;
    std::string value;
    std::string memValue;
    int size;
    int no;
    StaticString(std::string str){
        hintName = "string";
        value = str;
        memValue = toInt(str);
        no = 0;
    }
    std::string getHintName(){
        return hintName;
    }
    void visited(std::shared_ptr<IRVisitor> visitor){
        visitor -> visit(shared_from_this());
    }
    std::string getType(){
        return "StaticString";
    }
    std::string toInt(std::string str){
        size = 0;
        std::string ans;
        for(int i = 0; i < str.size(); ++i) {
            if(str[i] == '\\'){
                ++i;
                ++size;
                if(str[i] == 'n'){
                    ans += " 10,";
                }
                if(str[i] == '\"'){
                    ans += " 34,";
                }
                if(str[i] == '\\'){
                    ans += " 92,";
                }
            }
            else{
                ++size;
                ans += " ";
                ans += std::to_string((int)str[i]);
                ans.push_back(',');
            }
        }
        ans += " 0\n";
        return ans;
    }
};

#endif /* StaticString_h */
