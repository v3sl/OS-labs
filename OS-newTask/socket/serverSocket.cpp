#include "serverSocket.h"

ServerSocket::ServerSocket() : Socket()
{
    ConfigureAndConnect();
}

void ServerSocket::Close()
{
    if (close(newSocketFileDescriptor) == -1)
    {
        throw std::runtime_error("error in closing");
    }
}

void ServerSocket::Shutdown()
{
    if (shutdown(socketFileDescriptor, SHUT_RDWR) == -1)
    {
        throw std::runtime_error("error in shutdown");
    }
}

void ServerSocket::Send(const char *message)
{
    if (send(newSocketFileDescriptor, message, strlen(message), DEFAULT_SEND_FLAG) == -1)
    {
        throw std::runtime_error("error in sending");
    }
}

char *ServerSocket::Read()
{
    if (read(newSocketFileDescriptor, buffer, BUFF_SIZE) == -1)
    {
        throw std::runtime_error("error in reading");
    }
    return buffer;
}

void ServerSocket::ConfigureAndConnect()
{
    if (setsockopt(socketFileDescriptor, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &optionValue, sizeof(optionValue)) == -1)
    {
        throw std::runtime_error("setsockopt");
    }
    if (bind(socketFileDescriptor, (struct sockaddr *)&address, sizeof(address)) == -1)
    {
        throw std::runtime_error("bind failed");
    }
    if (listen(socketFileDescriptor, NUMBER_OF_REQUESTS) == -1)
    {
        throw std::runtime_error("listen");
    }
    if ((newSocketFileDescriptor = accept(socketFileDescriptor, (struct sockaddr *)&address,
                                          (socklen_t *)&addrlen)) == -1)
    {
        throw std::runtime_error("accept");
    }
}