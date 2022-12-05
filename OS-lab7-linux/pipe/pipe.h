#ifndef PIPE_H
#define PIPE_H

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdexcept>

#define PIPE_MODE 0666
#define BUFF_SIZE 512

class Pipe
{
public:
    static void Read(char *pipeName, char *buffer);
    static void Write(char *pipeName, char *buffer);

private:
    static int TryCreatePipe(char *pipeName, int flag);
};

#endif