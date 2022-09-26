c++ -c -fpic Number/number.cpp -o Number/build/number.o
ar rvs Number/build/number.a Number/build/number.o
c++ -c -fpic Vector/vector.cpp -o Vector/build/vector.o -INumber
c++ -shared Vector/build/vector.o Number/build/number.a -o Vector/build/vector.so
c++ -c testLibs/main.cpp -o testLibs/main.o -INumber -IVector
c++ -o testLibs/main testLibs/main.o Number/build/number.a Vector/build/vector.so
./testLibs/main
