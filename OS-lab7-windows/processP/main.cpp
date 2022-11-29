#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <cmath>
#include <pipe.h>

int main()
{
    char buffer[BUFF_SIZE];
    Pipe::Read(TEXT("\\\\.\\pipe\\processM"),buffer);
    std::string newBufferStr = "";
    char* nextPtr = nullptr;
    char *ptr = strtok_s(buffer, " ",&nextPtr);
    while (ptr != NULL)
    {
        newBufferStr += std::to_string((int)std::pow(std::atoi(ptr),3)) + " ";
        ptr = strtok_s(NULL, " ",&nextPtr);
    }
    char newBuffer[BUFF_SIZE];
    strcpy(newBuffer, newBufferStr.c_str());
    Pipe::Write(TEXT("\\\\.\\pipe\\processP"),newBuffer);
    return 0;
}