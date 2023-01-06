#pragma once

#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <stdexcept>

#define PORT 8080
#define BUFF_SIZE 1024
#define DEFAULT_PROTOCOL 0
#define DEFAULT_SEND_FLAG 0

class Socket
{
public:
    Socket();
    virtual void Close() = 0;
    virtual void Send(const char* message) = 0;
    virtual char* Read() = 0;
protected:
    int socketFileDescriptor;
    struct sockaddr_in address;
    char buffer[BUFF_SIZE] = {0};
};