#pragma GCC diagnostic ignored "-Wwrite-strings"

#include <pipe.h>
#include <string>

#define N 6

int main()
{
    char buffer[BUFF_SIZE];
    Pipe::Read("/tmp/main", buffer);
    std::string newBufferStr = "";
    char *ptr = strtok(buffer, " ");
    while (ptr != NULL)
    {
        newBufferStr += std::to_string(std::atoi(ptr) + N) + " ";
        ptr = strtok(NULL, " ");
    }
    char newBuffer[BUFF_SIZE];
    strcpy(newBuffer, newBufferStr.c_str());
    Pipe::Write("/tmp/processA", newBuffer);
    return 0;
}