#include "sharedMemory.h"

SharedMemory::SharedMemory(key_t key)
{
    shmid = shmget(key, SHM_MAX_SIZE, IPC_CREAT | 0666);
    shm = (char *)shmat(shmid, NULL, SHMAT_DEFAULT_FLAG);
}

void SharedMemory::Write(const char *message)
{
    strcpy(shm, "");
    sleep(1);
    strcpy(shm, message);
}

void SharedMemory::WriteAndWait(const char *message)
{
    Write(message);
    Wait();
}

char *SharedMemory::Read()
{
    return shm;
}

void SharedMemory::Close()
{
    if (shmdt(shm) == -1)
    {
        throw std::runtime_error("error in detaching");
    }
    if (shmctl(shmid, IPC_RMID, NULL) == -1)
    {
        throw std::runtime_error("error in closing");
    }
}

void SharedMemory::Wait()
{
    while (strcmp(shm, "") != 0)
    {
        sleep(1);
    }
    while (strcmp(shm, "") == 0)
    {
        sleep(1);
    }
}