g++ -c  Number/number.cpp -o Number/build/number.o
ar cr Number/build/libNumber.a Number/build/number.o 
g++ -c Vector/vector.cpp -o Vector/build/vector.o -INumber -LNumber/build -lNumber
g++ -shared -fpic -o Vector/build/libVector.so Vector/build/vector.o
g++ -o testLibs/main testLibs/main.cpp -INumber -LNumber/build -lNumber -IVector  -LVector/build -lVector 
cd testLibs
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:../Vector/build
./main
cd ../
