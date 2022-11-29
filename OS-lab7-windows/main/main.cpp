#include <iostream>
#include <pipe.h>

int main()
{
    char *input = "0 1 2 3\0";
    Pipe::Write(TEXT("\\\\.\\pipe\\main"), input);
    char buffer[BUFF_SIZE];
    Pipe::Read(TEXT("\\\\.\\pipe\\processS"), buffer);
    std::cout << buffer;
    return (0);
}