#pragma GCC diagnostic ignored "-Wwrite-strings"
#pragma GCC diagnostic ignored "-Wformat-security"

#include <pipe.h>
#include <messageQueue.h>
#include <sharedMemory.h>
#include <fileMapping.h>
#include <serverSocket.h>

void UsePipe()
{
    Pipe pipe("/tmp/A");
    pipe.Write("hello from first process using pipe\n\0");
    printf(pipe.Read());
}

void UseMessageQueue()
{
    MessageQueue queue(ftok("progfile", 65));
    queue.Write("hello from first process using message queue\n\0", 1);
    printf(queue.Read(2));
    queue.Destroy();
}

void UseSharedMemory()
{
    SharedMemory mem(ftok("shmfile", 65));
    mem.WriteAndWait("hello from first process using shared memory\n\0");
    printf(mem.Read());
    mem.Close();
}

void UseFileMapping()
{
    FileMapping file("../../fileMapping/myFile.txt");
    file.WriteAndWait("hello from first process using file mapping\n");
    printf(file.Read());
    file.Close();
}

void UseSocket()
{
    ServerSocket serverSocket;
    serverSocket.Send("hello from first process using socket\n");
    printf(serverSocket.Read());
    serverSocket.Close();
    serverSocket.Shutdown();
}

int main(int argc, char const *argv[])
{
    UseSocket();
    return 0;
}