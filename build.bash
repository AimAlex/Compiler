set -e
cd "$(dirname "$0")"
mkdir -p bin
i=`find ./demo/Mac/antlr4-cpp-demo/ ./demo/Mac/AST ./demo/Mac/VisitAST ./demo/generated -name "*.cpp"`
g++-7 -I ./runtime/src -I ./runtime/src/misc -I ./runtime/src/atn -I ./runtime/src/dfa -I ./runtime/src/tree -I ./runtime/src/support -I ./demo/generated -I ./demo/Mac/AST -I ./demo/Mac/VisitAST -L./lib -lantlr4-runtime -std=c++11 -o ./bin/compiler $i
