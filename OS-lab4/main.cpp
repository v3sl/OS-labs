#include <vector>
#include <chrono>
#include <iostream>
#include <thread>
#include "buffered_channel.h"

std::mutex mutex;

struct Timer
{
    std::chrono::time_point<std::chrono::steady_clock> start, end;
    std::chrono::duration<float> duration;

    Timer()
    {
        start = std::chrono::high_resolution_clock::now();
    }

    ~Timer() = default;

    float GetCurrentMs()
    {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;

        float ms = duration.count() * 1000.0f;
        return ms;
    }
};

std::vector<std::vector<int>> MakeMatrix(size_t size)
{
    srand((unsigned int)time(0));

    std::vector<std::vector<int>> matrix;

    for (size_t i = 0; i < size; ++i)
    {
        std::vector<int> matrixRow;

        for (size_t j = 0; j < size; ++j)
        {
            matrixRow.push_back(rand());
        }

        matrix.push_back(matrixRow);
    }

    return matrix;
}

void addBlocksToChannel(const std::vector<std::vector<int>> &firstMatrix, const std::vector<std::vector<int>> secondMatrix, std::vector<std::vector<int>> &result, size_t matrixSize, size_t blockSize, BufferedChannel<std::pair<size_t, size_t>> &channel)
{
    for (size_t blockI = 0; blockI < matrixSize; blockI += blockSize)
    {
        for (size_t blockJ = 0; blockJ < matrixSize; blockJ += blockSize)
        {
            channel.Send(std::move(std::make_pair(blockI, blockJ)));
        }
    }
}

void MultiplyBlocks(const std::vector<std::vector<int>> &firstMatrix, const std::vector<std::vector<int>> &secondMatrix, std::vector<std::vector<int>> &result, size_t blockI, size_t blockJ, size_t matrixSize, size_t blockSize)
{
    for (size_t i = blockI; i < std::min(blockI + blockSize, matrixSize); ++i)
    {
        for (size_t j = blockJ; j < std::min(blockJ + blockSize, matrixSize); ++j)
        {
            for (size_t k = 0; k < matrixSize; ++k)
            {
                mutex.lock();
                result[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
                mutex.unlock();
            }
        }
    }
}

void MultiplyWhilePossible(const std::vector<std::vector<int>> &firstMatrix, const std::vector<std::vector<int>> &secondMatrix, std::vector<std::vector<int>> &result, BufferedChannel<std::pair<size_t, size_t>> &channel, size_t blockSize, size_t matrixSize)
{
    std::pair<std::pair<size_t, size_t>, bool> currentPair = channel.Recv();

    while (currentPair.second)
    {
        MultiplyBlocks(firstMatrix, secondMatrix, result, currentPair.first.first, currentPair.first.second, matrixSize, blockSize);
        currentPair = channel.Recv();
    }
}

void FindCalculationTime(const std::vector<std::vector<int>> &firstMatrix, const std::vector<std::vector<int>> &secondMatrix, std::vector<std::vector<int>> &result, size_t matrixSize, size_t numberOfThreads)
{
    for (size_t i = 1; i <= matrixSize; ++i)
    {
        Timer time;
        result = std::vector<std::vector<int>>(firstMatrix.size(), std::vector<int>(firstMatrix.size()));
        size_t countOfBlocks = firstMatrix.size() % i == 0 ? firstMatrix.size() / i : firstMatrix.size() / i + 1;
        BufferedChannel<std::pair<size_t, size_t>> channel(countOfBlocks * countOfBlocks);

        addBlocksToChannel(firstMatrix, secondMatrix, result, matrixSize, i, channel);
        channel.Close();

        std::vector<std::thread> threads;

        for (size_t j = 0; j < numberOfThreads; ++j)
        {
            threads.emplace_back(MultiplyWhilePossible, std::cref(firstMatrix), std::cref(secondMatrix), std::ref(result), std::ref(channel), i, matrixSize);
        }
        for (auto &thread : threads)
        {
            thread.join();
        }

        std::cout << "time with block size " << i << " " << time.GetCurrentMs() << std::endl;
    }
}

void PrintMatrix(const std::vector<std::vector<int>> &matrix)
{
    for (const std::vector<int> &row : matrix)
    {
        for (int el : row)
        {
            std::cout << el << " ";
        }

        std::cout << '\n';
    }
}

int main()
{
    size_t sizeOfMatrix;
    std::cout << "Enter size of matrix\n";
    std::cin >> sizeOfMatrix;

    std::vector<std::vector<int>> firstMatrix = MakeMatrix(sizeOfMatrix);
    std::vector<std::vector<int>> secondMatrix = MakeMatrix(sizeOfMatrix);

    std::vector<std::vector<int>> result(sizeOfMatrix, std::vector<int>(sizeOfMatrix));

    FindCalculationTime(firstMatrix, secondMatrix, result, sizeOfMatrix, 17);

    return 0;
}