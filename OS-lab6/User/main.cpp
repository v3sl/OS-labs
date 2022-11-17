#include <windows.h>
#include <vector>
#include <iostream>

void TrySetProcToKill(LPCWSTR value)
{
    if (!SetEnvironmentVariableW(L"PROC_TO_KILL", value))
    {
        std::cerr << "Set environment variable failed with error code" << GetLastError() << '\n';
    }
}

std::wstring StringToWString(const std::string &str)
{
    int sizeNeeded = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
    std::wstring wstrTo(sizeNeeded, 0);
    MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstrTo[0], sizeNeeded);
    return wstrTo;
}

std::vector<std::wstring> GetArgs(int argc, char *argv[])
{
    std::vector<std::wstring> args;
    for (int i = 1; i < argc; ++i)
    {
        args.push_back(StringToWString(argv[i]));
    }
    return args;
}

std::string CreateCommandLine(const std::vector<std::wstring> &args)
{
    std::string commandLine = "../../../Killer/build/Debug/Killer.exe";
    for (auto arg : args)
    {
        commandLine += " " + std::string(arg.begin(), arg.end());
    }
    return commandLine;
}

void CallKiller(std::string cmd)
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));
    if (!CreateProcess(NULL, &cmd.front(), NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi))
    {
        std::cerr << "CreateProcess failed with error code " << GetLastError() << '\n';
    }
    WaitForSingleObject(pi.hProcess, INFINITE);
    if (!CloseHandle(pi.hProcess) && !CloseHandle(pi.hThread))
    {
        std::cerr << "Close handle failed with error code " << GetLastError() << '\n';
    }
}

int main(int argc, char *argv[])
{
    TrySetProcToKill(L"Telegram.exe,mspaint.exe");
    std::vector<std::wstring> args = GetArgs(argc, argv);
    std::string cmd = CreateCommandLine(args);
    CallKiller(cmd);
    TrySetProcToKill(NULL);
    return 0;
}