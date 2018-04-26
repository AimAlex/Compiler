set -e
cd "$(dirname "$0")"
mkdir -p bin 
i=`find ./runtime/ -name "*.cpp"`
g++-5 -I ./runtime/src -I ./runtime/src/misc -I ./runtime/src/atn -I ./runtime/src/dfa -I ./runtime/src/tree -I ./runtime/src/support -fPIC -shared -std=c++11 -o libantlr.so $i
