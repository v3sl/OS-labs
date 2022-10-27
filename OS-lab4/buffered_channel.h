#ifndef BUFFERED_CHANNEL_H_
#define BUFFERED_CHANNEL_H_

#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <atomic>

template <class T>
class BufferedChannel
{
public:
    explicit BufferedChannel(size_t capacity = 0) : capacity(capacity), isClosed(false)
    {
    }

    void Send(T &&item)
    {
        if (isClosed)
        {
            throw std::runtime_error("Channel is closed");
        }

        std::unique_lock<std::mutex> lock(mutexLock);
        check.wait(lock, [this]()
                   { return capacity > container.size(); });

        container.push(std::move(item));
        check.notify_one();
    }

    std::pair<T, bool> Recv()
    {
        std::unique_lock<std::mutex> lock(mutexLock);

        if (isClosed && container.empty())
        {
            return std::make_pair(T(), false);
        }

        check.wait(lock, [this]()
                   { return !container.empty(); });

        T item = container.front();
        container.pop();
        check.notify_one();
        return std::make_pair(item, true);
    }

    void Close()
    {
        isClosed = true;
        check.notify_all();
    }

    ~BufferedChannel() = default;

private:
    size_t capacity;
    std::atomic<bool> isClosed;
    std::queue<T> container;
    std::mutex mutexLock;
    std::condition_variable check;
};

#endif