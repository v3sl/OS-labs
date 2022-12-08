#pragma GCC diagnostic ignored "-Wwrite-strings"

#include <pipe.h>
#include <iostream>

int main()
{
    Pipe::Write("/tmp/main","0 1 2 3\0");
    char buffer[BUFF_SIZE];
    Pipe::Read("/tmp/processS",buffer);
    std::cout << buffer << std::endl;
    return 0;
}