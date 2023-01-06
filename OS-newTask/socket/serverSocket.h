#pragma once

#include "socket.h"

#define NUMBER_OF_REQUESTS 10

class ServerSocket : public Socket
{
public:
    ServerSocket();
    void Close() override;
    void Shutdown();
    void Send(const char* message) override;
    char* Read() override;
private:
    void ConfigureAndConnect();
    int newSocketFileDescriptor;
    int optionValue = 1;
    int addrlen = sizeof(address);
};