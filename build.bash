set -e
cd "$(dirname "$0")"
mkdir -p bin 
find ./demo/Mac/antlr4-cpp-demo/ ./demo/Mac/AST ./demo/generated ./runtime -name "*.cpp" | g++ -I ./runtime/src -I ./runtime/src/misc -I ./runtime/src/atn -I ./runtime/src/dfa -I ./runtime/src/tree -I ./runtime/src/support -I ./demo/generated -I ./demo/Mac/AST -std=c++14 -o ./bin/compiler @/dev/stdin