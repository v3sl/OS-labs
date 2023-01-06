#pragma once

#include <sys/msg.h>
#include <string.h>
#include <stdexcept>

#define MSG_SIZE 1024
#define MSG_DEFAULT_FLAG 0666
#define MSGSND_DEFAULT_FLAG 0

class MessageQueue
{
public:
    MessageQueue(key_t key);
    void Write(char *messageText, long messageType);
    char* Read(long messageType);
    void Destroy();
private:
    int messageId;
    struct messageBuffer
    {
        long messageType;
        char messageText[MSG_SIZE];
    } message;
};