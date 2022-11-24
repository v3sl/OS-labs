#include <signal.h>
#include <iostream>
#include <cstring>

bool IsNumber(const char *string)
{
    for (int i = 0; i < strlen(string); ++i)
    {
        if (!isdigit(string[i]))
        {
            return false;
        }
    }
    return true;
}

void KillProccessByName(const char *name)
{
    int size = 512;
    char buffer[size];
    std::string stringName(name);
    FILE *cmdPipe = popen(("pidof " + stringName).c_str(), "r");
    fgets(buffer, size, cmdPipe);
    pclose(cmdPipe);
    std::string allPID(buffer);
    if (allPID.empty())
    {
        return;
    }
    char *pid = strtok(&allPID.front(), " ");
    while (pid != NULL)
    {
        if (IsNumber(pid))
        {
            kill(std::atoi(pid), SIGTERM);
        }
        pid = strtok(NULL, " ");
    }
}

void KIllProccessByEv()
{
    char *stringEV = getenv("PROC_TO_KILL");
    if (stringEV == NULL)
    {
        return;
    }
    char *proccessName = strtok(stringEV, ",");
    while (proccessName != NULL)
    {
        KillProccessByName(proccessName);
        proccessName = strtok(NULL, ",");
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
