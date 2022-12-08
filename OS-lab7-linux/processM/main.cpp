#pragma GCC diagnostic ignored "-Wwrite-strings"

#include <pipe.h>
#include <string>

int main()
{
    char buffer[BUFF_SIZE];
    Pipe::Read("/tmp/processA", buffer);
    std::string newBufferStr = "";
    char *ptr = strtok(buffer, " ");
    while (ptr != NULL)
    {
        newBufferStr += std::to_string(std::atoi(ptr) * 7) + " ";
        ptr = strtok(NULL, " ");
    }
    char newBuffer[BUFF_SIZE];
    strcpy(newBuffer, newBufferStr.c_str());
    Pipe::Write("/tmp/processM", newBuffer);
    return 0;
}