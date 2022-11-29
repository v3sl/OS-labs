#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <pipe.h>

int main()
{
    char buffer[BUFF_SIZE];
    Pipe::Read(TEXT("\\\\.\\pipe\\processP"), buffer);
    char *nextPtr = nullptr;
    char *ptr = strtok_s(buffer, " ", &nextPtr);
    int sum = 0;
    while (ptr != NULL)
    {
        sum += std::atoi(ptr);
        ptr = strtok_s(NULL, " ", &nextPtr);
    }
    std::string newBufferStr = std::to_string(sum);
    char newBuffer[BUFF_SIZE];
    strcpy(newBuffer, newBufferStr.c_str());
    Pipe::Write(TEXT("\\\\.\\pipe\\processS"), newBuffer);
    return 0;
}