set -e
cd "$(dirname "$0")"
mkdir -p bin 
i=`find ./demo/Mac/antlr4-cpp-demo/ ./demo/Mac/AST ./demo/generated -name "*.cpp"`
g++ -I ./runtime/src -I ./runtime/src/misc -I ./runtime/src/atn -I ./runtime/src/dfa -I ./runtime/src/tree -I ./runtime/src/support -I ./demo/generated -I ./demo/Mac/AST -L ./lib -l antlr4-runtime -std=c++14 -o ./bin/compiler $i
