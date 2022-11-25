#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    putenv("PROC_TO_KILL=firefox,chrome");
    pid_t pid = fork();
    switch (pid)
    {
    case -1:
        fprintf(stderr, "FORK FAILED\n");
        return -1;
    case 0:
        execv("./../../Killer/build/Killer", argv);
        _exit(0);
    default:
        wait(NULL);
        _exit(0);
    }
    unsetenv("PROC_TO_KILL"); 
    return 0;
}