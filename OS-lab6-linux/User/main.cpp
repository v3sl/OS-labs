#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <iostream>

int main(int argc, char *argv[])
{
    putenv("PROC_TO_KILL=firefox,chrome");
    pid_t pid, p;
    int i, status;
    if ((pid = fork()) == -1)
    {
        fprintf(stderr, "FORK FAILED\n");
        return -1;
    }
    if (pid == 0)
    {
        execv("./../../Killer/build/Killer", argv);
        _exit(0);
    }
    else
    {
        p = wait(&status);
        _exit(0);
    }
    return 0;
}