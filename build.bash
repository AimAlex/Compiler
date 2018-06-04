set -e
cd "$(dirname "$0")"
mkdir -p bin
i=`find ./demo/Mac/antlr4-cpp-demo/  ./demo/generated -name "*.cpp"`
g++-7 -I ./runtime/src -I ./runtime/src/misc -I ./runtime/src/atn -I ./runtime/src/dfa -I ./runtime/src/tree -I ./runtime/src/support -I ./demo/generated -I ./demo/Mac/AST -I ./demo/Mac/VisitAST -I ./demo/Mac/Symbol -I ./demo/Mac/VisitIR -I ./demo/Mac/IR -std=c++11 -o ./bin/compiler $i ./lib/libantlr4-runtime.a
