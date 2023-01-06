#pragma once

#include <sys/shm.h>
#include <string.h>
#include <unistd.h>
#include <stdexcept>

#define SHM_MAX_SIZE 1024
#define SHM_DEFAULT_FLAG 0666
#define SHMAT_DEFAULT_FLAG 0

class SharedMemory
{
public:
    SharedMemory(key_t key);
    void Write(const char* message);
    void WriteAndWait(const char*message);
    char* Read();
    void Close();
private:
    void Wait();
    int shmid;
    char* shm;
};