#pragma once

#include <arpa/inet.h>
#include "socket.h"

class ClientSocket : public Socket
{
public:
   ClientSocket();
   void Close() override;
   void Send(const char* message) override;
   char* Read() override;
private:
   void ConfigureAndConnect();
};