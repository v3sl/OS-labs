g++ -c Number/number.cpp -o Number/build/number.o
ar r Number/build/libNumber.a Number/build/number.o
g++ -c Vector/vector.cpp -o Vector/build/vector.o -INumber -LNumer/build -lNumber
g++ -shared -o Vector/build/libVector.so Vector/build/vector.o
g++ -INumber -LNumber/build -lNumber -IVector -LVector/build -lVector -c testLibs/main.cpp -o main.out
