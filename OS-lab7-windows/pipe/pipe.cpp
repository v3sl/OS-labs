#include "pipe.h"

void Pipe::Write(LPCSTR pipeName, char *buffer)
{
    DWORD dwWritten;
    HANDLE pipe = CreateFile(pipeName, GENERIC_READ | GENERIC_WRITE, NULL, NULL, OPEN_EXISTING, NULL, NULL);
    if (pipe == INVALID_HANDLE_VALUE)
    {
        return;
    }
    WriteFile(pipe, buffer, BUFF_SIZE, &dwWritten, NULL);
    CloseHandle(pipe);
}
void Pipe::Read(LPCSTR pipeName, char *buffer)
{
    DWORD dwRead;
    HANDLE pipe = CreateNamedPipe(pipeName, PIPE_ACCESS_DUPLEX, PIPE_TYPE_BYTE | PIPE_READMODE_BYTE | PIPE_WAIT, MAX_INSTANCES, OUT_BUFFER_SIZE, IN_BUFFER_SIZE, NMPWAIT_USE_DEFAULT_WAIT, NULL);
    if (!ConnectNamedPipe(pipe, NULL))
    {
        return;
    }
    ReadFile(pipe, buffer, strlen(buffer), &dwRead, NULL);
    DisconnectNamedPipe(pipe);
    CloseHandle(pipe);
}