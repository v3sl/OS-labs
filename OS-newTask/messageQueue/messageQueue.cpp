#include "messageQueue.h"

MessageQueue::MessageQueue(key_t key)
{
    messageId = msgget(key, MSG_DEFAULT_FLAG | IPC_CREAT);
}

void MessageQueue::Write(char *messageText, long msgType)
{
    message.messageType = msgType;
    strcpy(message.messageText, messageText);
    if (msgsnd(messageId, &message, sizeof(message), MSGSND_DEFAULT_FLAG) == -1)
    {
        throw std::runtime_error("error in sending message");
    }
}

char *MessageQueue::Read(long msgType)
{
    if (msgrcv(messageId, &message, sizeof(message), msgType, 0) == -1)
    {
        throw std::runtime_error("error in receiving message");
    }
    return message.messageText;
}

void MessageQueue::Destroy()
{
    if (msgctl(messageId, IPC_RMID, NULL) == -1)
    {
        throw std::runtime_error("error in destroying queue");
    }
}
