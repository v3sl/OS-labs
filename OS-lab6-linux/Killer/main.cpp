#include <signal.h>
#include <sys/types.h>
#include <iostream>
#include <cstring>
#include <iostream>
#include <vector>

void KillProccessByName(const char *name)
{
    char buf[512];
    std::string str(name);
    FILE *cmdPipe = popen(("pidof " + str).c_str(), "r");
    fgets(buf, 512, cmdPipe);
    pid_t pid = strtoul(buf, NULL, 10);
    std::string allPID(buf);
    pclose(cmdPipe);
    if (allPID.empty())
    {
        return;
    }
    char *ptr = strtok(&allPID.front(), " ");
    while (ptr != NULL)
    {
        kill(std::atoi(ptr), SIGTERM);
        ptr = strtok(NULL, " ");
    }
}

void KIllProccessByEv()
{
    char *cstr = getenv("PROC_TO_KILL");
    if (cstr == NULL)
    {
        return;
    }
    char *ptr = strtok(cstr, ",");
    while (ptr != NULL)
    {
        KillProccessByName(ptr);
        ptr = strtok(NULL, ",");
    }
}

int main(int argc, char const *argv[])
{
    KIllProccessByEv();
    for (int i = 0; i < argc; ++i)
    {
        if (strcmp(argv[i], "--id") == 0)
        {
            kill(std::atoi(argv[i + 1]), SIGTERM);
        }
        if (strcmp(argv[i], "--name") == 0)
        {
            KillProccessByName(argv[i + 1]);
        }
    }
    return 0;
}
