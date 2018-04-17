/* Copyright (c) 2012-2017 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */

//
//  main.cpp
//  antlr4-cpp-demo
//
//  Created by Mike Lischke on 13.03.16.
//

#include <iostream>

#include "antlr4-runtime.h"
#include "MLexer.h"
#include "MParser.h"
#include "ASTListener.h"

using namespace antlrcpptest;
using namespace antlr4;

int main(int , const char **) {
    //    ANTLRFileStream(<#const std::string &fileName#>)
    ANTLRInputStream input(u8"int main () {a = b + c; \n a = a ++;}");
    MLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    
    tokens.fill();
    for (auto token : tokens.getTokens()) {
        std::cout << token->toString() << std::endl;
    }
    
    MParser parser(&tokens);
    tree::ParseTree *tree = parser.program();
    
    std::cout << tree->toStringTree(&parser) << std::endl;
    
    tree::ParseTreeWalker walker = *new tree::ParseTreeWalker();
    walker.walk(new ASTListener(), tree);
    
    return 0;
}
