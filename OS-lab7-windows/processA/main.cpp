#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <pipe.h>

#define N 6 

int main()
{
    char buffer[BUFF_SIZE];
    Pipe::Read(TEXT("\\\\.\\pipe\\main"),buffer);
    std::string newBufferStr = "";
    char* nextPtr = nullptr;
    char *ptr = strtok_s(buffer, " ",&nextPtr);
    while (ptr != NULL)
    {
        newBufferStr += std::to_string(std::atoi(ptr) + N) + " ";
        ptr = strtok_s(NULL, " ",&nextPtr);
    }
    char newBuffer[BUFF_SIZE];
    strcpy(newBuffer, newBufferStr.c_str());
    Pipe::Write(TEXT("\\\\.\\pipe\\processA"),newBuffer);
    return 0;
}