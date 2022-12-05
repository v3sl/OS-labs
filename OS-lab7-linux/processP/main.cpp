#pragma GCC diagnostic ignored "-Wwrite-strings"

#include <pipe.h>
#include <cmath>

int main()
{
    char buffer[BUFF_SIZE];
    Pipe::Read("/tmp/processM", buffer);
    std::string newBufferStr = "";
    char *ptr = strtok(buffer, " ");
    while (ptr != NULL)
    {
        newBufferStr += std::to_string((int)std::pow(std::atoi(ptr), 3)) + " ";
        ptr = strtok(NULL, " ");
    }
    char newBuffer[BUFF_SIZE];
    strcpy(newBuffer, newBufferStr.c_str());
    Pipe::Write("/tmp/processP", newBuffer);
    return 0;
}