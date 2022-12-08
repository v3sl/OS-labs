#include "pipe.h"

void Pipe::Read(char *pipeName, char *buffer)
{
    int fd = TryCreatePipe(pipeName, O_RDONLY);
    read(fd, buffer, BUFF_SIZE);
    close(fd);
}
void Pipe::Write(char *pipeName, char *buffer)
{
    int fd = TryCreatePipe(pipeName, O_WRONLY);
    write(fd, buffer, strlen(buffer) + 1);
    close(fd);
}
int Pipe::TryCreatePipe(char *pipeName, int flag)
{
    int fd;
    mkfifo(pipeName, PIPE_MODE);
    fd = open(pipeName, flag);
    if (fd == -1)
    {
        fprintf(stderr, "error in opening pipe\n");
    }
    return fd;
}