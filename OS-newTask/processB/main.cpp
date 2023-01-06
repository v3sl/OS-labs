#pragma GCC diagnostic ignored "-Wwrite-strings"
#pragma GCC diagnostic ignored "-Wformat-security"

#include <pipe.h>
#include <messageQueue.h>
#include <sharedMemory.h>
#include <fileMapping.h>
#include <clientSocket.h>

void UsePipe()
{
    Pipe pipe("/tmp/A");
    printf(pipe.Read());
    pipe.Write("hello from second process using pipe\n\0");
}

void UseMessageQueue()
{
    MessageQueue queue(ftok("progfile", 65));
    printf(queue.Read(1));
    queue.Write("hello from second process using message queue\n\0", 2);
}

void UseSharedMemory()
{
    SharedMemory mem(ftok("shmfile", 65));
    printf(mem.Read());
    mem.Write("hello from second process using shared memory\n\0");
}

void UseFileMapping()
{
    FileMapping file("../../fileMapping/myFile.txt");
    printf(file.Read());
    file.Write("hello from second process using file mapping\n");
    file.Close();
}

void UseSocket()
{
    ClientSocket clientSocket;
    printf(clientSocket.Read());
    clientSocket.Send("hello from second process using socket\n");
    clientSocket.Close();
}

int main()
{
    UseSocket();
    return 0;
}