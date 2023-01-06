#pragma once

#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdexcept>
#include  <functional>

#define DEFAULT_MODE 0644
#define DEFAULT_OFFSET 0

class FileMapping
{   
public:
    FileMapping(const char* filePath);
    char* Read();
    void Write(const char* message);
    void WriteAndWait(const char* message);
    void Close();
    ~FileMapping();
private:
    void WriteAndSync(const char* message);
    void UpdateFileSize();
    void Wait();
    struct stat fileStatus;
    size_t fileSize = 0;
    int fileDescriptor;
    void* address = nullptr;
};
