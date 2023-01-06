#pragma once

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdexcept>

#define PIPE_MODE 0666
#define BUFF_MAX_SIZE 512
#define PIPE_NAME_MAX_SIZE 64

class Pipe
{
public:
    Pipe(const char *pipeName);
    char *Read();
    void Write(const char *message);
private:
    void Close();
    char *pipeName = (char *)malloc(PIPE_NAME_MAX_SIZE);
    int fileDescriptor;
    char *buffer = (char *)malloc(BUFF_MAX_SIZE);
};