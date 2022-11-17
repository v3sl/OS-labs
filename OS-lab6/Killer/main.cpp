#include "killer.h"

int main(int argc, char *argv[])
{
    KillProcessByEV();
    for (int i = 0; i < argc; ++i)
    {
        if (strcmp(argv[i], "--name") == 0)
        {
            KillProcessByName(argv[i + 1]);
        }
        if (strcmp(argv[i], "--id") == 0)
        {
            KillProcessByID(std::stoi(argv[i + 1]));
        }
    }
    return 0;
}
