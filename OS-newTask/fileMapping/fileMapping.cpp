#include "fileMapping.h"

FileMapping::FileMapping(const char *filePath)
{
    fileDescriptor = open(filePath, O_CREAT | O_RDWR, DEFAULT_MODE);
    if (fileDescriptor == -1)
    {
        throw std::runtime_error("error in creating file descriptor");
    }
}

char *FileMapping::Read()
{
    UpdateFileSize();
    address = mmap(NULL, fileSize, PROT_READ, MAP_SHARED, fileDescriptor,
                   DEFAULT_OFFSET);
    return (char *)address;
}

void FileMapping::Write(const char *message)
{
    UpdateFileSize();
    address = mmap(NULL, fileSize, PROT_WRITE, MAP_SHARED, fileDescriptor,
                   DEFAULT_OFFSET);
    char temp[fileSize] = {0};
    WriteAndSync(temp);
    sleep(1);
    fileSize = strlen(message) + 1;
    address = mmap(NULL, fileSize, PROT_WRITE, MAP_SHARED, fileDescriptor,
                   DEFAULT_OFFSET);
    WriteAndSync(message);
}

void FileMapping::WriteAndWait(const char *message)
{
    Write(message);
    Wait();
}

void FileMapping::Close()
{
    UpdateFileSize();
    if (munmap(address, fileSize) == -1)
    {
        throw std::runtime_error("error in deallocating");
    }
    if (close(fileDescriptor))
    {
        throw std::runtime_error("error in closing");
    }
}

FileMapping::~FileMapping()
{
    try
    {
        Close();
    }
    catch (std::exception &e)
    {
        return;
    }
}

void FileMapping::WriteAndSync(const char *message)
{
    memcpy(address, message, fileSize);
    if (msync(address, fileSize, MS_SYNC))
    {
        throw std::runtime_error("error in synchronizing");
    }
}

void FileMapping::UpdateFileSize()
{
    if (fstat(fileDescriptor, &fileStatus))
    {
        throw std::runtime_error("error in getting attributes of file");
    }
    fileSize = fileStatus.st_size;
}

void FileMapping::Wait()
{
    while (*(char *)address != '\0')
    {
        sleep(1);
    }
    while (*(char *)address == '\0')
    {
        sleep(1);
    }
}