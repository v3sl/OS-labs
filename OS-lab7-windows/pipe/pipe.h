#pragma once

#include <string>
#include <windows.h>
#include <stdexcept>

#define BUFF_SIZE 512
#define MAX_INSTANCES 1
#define OUT_BUFFER_SIZE 1024 * 16
#define IN_BUFFER_SIZE 1024 * 16

class Pipe
{
public:
    static void Write(LPCSTR pipeName, char *buffer);
    static void Read(LPCSTR pipeName, char *buffer);
};