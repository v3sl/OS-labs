#include "socket.h"

Socket::Socket()
{
    socketFileDescriptor = socket(AF_INET, SOCK_STREAM, DEFAULT_PROTOCOL);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
}