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
#include "ASTPrinter.h"
#include "ASTClass.h"
using namespace antlrcpptest;
using namespace antlr4;

int main(int , const char **) {
    ANTLRFileStream file("/Users/aimalex/Desktop/Compiler/Mcode/sample.mx");
    ANTLRInputStream input(file);
    MLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    
    tokens.fill();
//    for (auto token : tokens.getTokens()) {
//        std::cout << token->toString() << std::endl;
//    }
    
    MParser parser(&tokens);
    tree::ParseTree *tree = parser.program();
    
//    std::cout << tree->toStringTree(&parser) << std::endl;
    
    tree::ParseTreeWalker walker = *new tree::ParseTreeWalker();
    auto listener = std::make_shared<ASTListener>();
    walker.walk(listener.get(), tree);
    auto printer = std::make_shared<ASTPrinter>();
    (listener->getProgram()) -> visited(printer);
    
    return 0;
}
