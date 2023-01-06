#include "clientSocket.h"

ClientSocket::ClientSocket() : Socket()
{
    ConfigureAndConnect();
}

void ClientSocket::Close()
{
    if (close(socketFileDescriptor) == -1)
    {
        throw std::runtime_error("error in closing");
    }
}

void ClientSocket::Send(const char *message)
{
    if (send(socketFileDescriptor, message, strlen(message), DEFAULT_SEND_FLAG) == -1)
    {
        throw std::runtime_error("error in sending");
    }
}

char *ClientSocket::Read()
{
    if (read(socketFileDescriptor, buffer, BUFF_SIZE) == -1)
    {
        throw std::runtime_error("error in reading");
    }
    return buffer;
}

void ClientSocket::ConfigureAndConnect()
{
    if (inet_pton(AF_INET, "127.0.0.1", &address.sin_addr) <= 0)
    {
        throw std::runtime_error("Invalid address / Address not supported\n");
    }
    if ((connect(socketFileDescriptor, (struct sockaddr *)&address, sizeof(address))) == -1)
    {
        throw std::runtime_error("Connection Failed\n");
    }
}