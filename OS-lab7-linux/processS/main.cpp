#pragma GCC diagnostic ignored "-Wwrite-strings"

#include <pipe.h>
#include <string>

int main()
{
    char buffer[BUFF_SIZE];
    Pipe::Read("/tmp/processP", buffer);
    std::string newBufferStr = "";
    char *ptr = strtok(buffer, " ");
    int sum = 0;
    while (ptr != NULL)
    {
        sum += std::atoi(ptr);
        ptr = strtok(NULL, " ");
    }
    newBufferStr += std::to_string(sum);
    char newBuffer[BUFF_SIZE];
    strcpy(newBuffer, newBufferStr.c_str());
    Pipe::Write("/tmp/processS", newBuffer);
    return 0;
}