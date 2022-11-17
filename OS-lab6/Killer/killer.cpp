#include "killer.h"

void KillProcess(HANDLE hProcess)
{
    if (!TerminateProcess(hProcess, NULL))
    {
        std::cerr << "Terminate proccess failed with code " << GetLastError() << '\n';
    }
    if (!CloseHandle(hProcess))
    {
        std::cerr << "Close handle failed with code " << GetLastError() << '\n';
    }
}

void KillProcessByName(const char *filename)
{
    HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, NULL);
    PROCESSENTRY32 pEntry;
    pEntry.dwSize = sizeof(pEntry);
    BOOL hRes = Process32First(hSnapShot, &pEntry);
    while (hRes)
    {
        if (strcmp(pEntry.szExeFile, filename) == 0)
        {
            HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, 0,
                                          (DWORD)pEntry.th32ProcessID);
            if (hProcess != NULL)
            {
                KillProcess(hProcess);
            }
        }
        hRes = Process32Next(hSnapShot, &pEntry);
    }
    CloseHandle(hSnapShot);
}

void KillProcessByID(INT32 id)
{
    HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, 0, id);
    if (hProcess == NULL)
    {
        return;
    }
    KillProcess(hProcess);
}

void KillProcessByEV()
{
    DWORD bufferSize = 65535;
    std::wstring buff;
    buff.resize(bufferSize);
    bufferSize = GetEnvironmentVariableW(L"PROC_TO_KILL", &buff[0], bufferSize);
    if (!bufferSize)
    {
        std::cout << "error in getting environment variable\n";
    }
    buff.resize(bufferSize);
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
    std::string args = converter.to_bytes(buff);
    char *nextPtr = NULL;
    char *ptr = strtok_s(&args.front(), ",", &nextPtr);
    while (ptr != NULL)
    {
        KillProcessByName(ptr);
        ptr = strtok_s(NULL, ",", &nextPtr);
    }
}