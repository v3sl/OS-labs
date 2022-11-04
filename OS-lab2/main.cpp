#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

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

std::vector<float> threadCalculationResults;
std::vector<float> defaultCalculationResults;

void MultiplyWithoutThreads(const std::vector<std::vector<int>> &firstMatrix, const std::vector<std::vector<int>> secondMatrix, std::vector<std::vector<int>> &result, size_t matrixSize, size_t blockSize)
{
    for (size_t blockI = 0; blockI < matrixSize; blockI += blockSize)
    {
        for (size_t blockJ = 0; blockJ < matrixSize; blockJ += blockSize)
        {
            MultiplyBlocks(firstMatrix, secondMatrix, result, blockI, blockJ, matrixSize, blockSize);
        }
    }
}

void MultiplyWithThreads(const std::vector<std::vector<int>> &firstMatrix, const std::vector<std::vector<int>> &secondMatrix, std::vector<std::vector<int>> &result, size_t matrixSize, size_t blockSize)
{
    std::vector<std::thread> threads;
    for (size_t blockI = 0; blockI < matrixSize; blockI += blockSize)
    {
        for (size_t blockJ = 0; blockJ < matrixSize; blockJ += blockSize)
        {
            threads.emplace_back(MultiplyBlocks, std::cref(firstMatrix), std::cref(secondMatrix), std::ref(result), blockI, blockJ, matrixSize, blockSize);
        }
    }
    for (std::thread &thread : threads)
    {
        thread.join();
    }
}

void FindThreadsCalculationTime(const std::vector<std::vector<int>> &firstMatrix, const std::vector<std::vector<int>> &secondMatrix, std::vector<std::vector<int>> &result, size_t matrixSize)
{
    for (size_t i = 1; i <= matrixSize; ++i)
    {
        Timer time;
        result = std::vector<std::vector<int>>(firstMatrix.size(), std::vector<int>(firstMatrix.size()));
        MultiplyWithThreads(firstMatrix, secondMatrix, result, matrixSize, i);
        threadCalculationResults.push_back(time.GetCurrentMs());
    }
}

void FindDefaultCalculationTime(const std::vector<std::vector<int>> &firstMatrix, const std::vector<std::vector<int>> &secondMatrix, std::vector<std::vector<int>> &result, size_t matrixSize)
{

    for (size_t i = 1; i <= matrixSize; ++i)
    {
        Timer time;
        result = std::vector<std::vector<int>>(firstMatrix.size(), std::vector<int>(firstMatrix.size()));
        MultiplyWithoutThreads(firstMatrix, secondMatrix, result, matrixSize, i);
        defaultCalculationResults.push_back(time.GetCurrentMs());
    }
}

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

    std::vector<std::vector<int>> firstMatrix =  MakeMatrix(sizeOfMatrix);
    std::vector<std::vector<int>> secondMatrix = MakeMatrix(sizeOfMatrix);
    std::vector<std::vector<int>> result(sizeOfMatrix, std::vector<int>(sizeOfMatrix));

    FindDefaultCalculationTime(firstMatrix, firstMatrix, result, sizeOfMatrix);
    FindThreadsCalculationTime(firstMatrix, firstMatrix, result, sizeOfMatrix);

    for (int i = 0; i < threadCalculationResults.size(); ++i)
    {
        std::cout << "calculation ratio with block size " << i + 1 << " " << defaultCalculationResults[i] / threadCalculationResults[i] << '\n';
    }

    PrintMatrix(result);
    return 0;
}
