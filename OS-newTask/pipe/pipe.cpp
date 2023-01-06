#include "pipe.h"

Pipe::Pipe(const char *pipeName)
{
    if (mkfifo(pipeName, PIPE_MODE) == -1 && errno != EEXIST)
    {
        throw std::runtime_error("error in creating pipe");
    }
    strcpy(this->pipeName, pipeName);
}

char *Pipe::Read()
{
    fileDescriptor = open(pipeName, O_RDONLY);
    if (read(fileDescriptor, buffer, BUFF_MAX_SIZE) == -1)
    {
        throw std::runtime_error("error in reading");
    }
    Close();
    return buffer;
}
void Pipe::Write(const char *message)
{
    fileDescriptor = open(pipeName, O_WRONLY);
    if (write(fileDescriptor, message, strlen(message)) == -1)
    {
        throw std::runtime_error("error in writing");
    }
    Close();
}

void Pipe::Close()
{
    if (close(fileDescriptor) == -1)
    {
        throw std::runtime_error("error in closing");
    }
}