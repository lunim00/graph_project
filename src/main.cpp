#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <chrono>
#include "networkHandler.hpp"
#include "independentCascadeModel.hpp"
#include "informedNodes.hpp"
#include "node.hpp"

int main(int argc, char** argv)
{

    if (argc < 6)
    {
        std::cerr << "To few arguments" << std::endl;
        return 1;
    }

    auto totalStartTime = std::chrono::steady_clock::now();
    auto startTime = std::chrono::steady_clock::now();
    std::string file = argv[1];
    // std::cout << "file: " << file << std::endl;
    unsigned int size = std::stoul(std::string(argv[2]));
    // std::cout << "size: " << size << std::endl;
    std::string dtCase = argv[3];
    float beta = stof(std::string(argv[4]));
    std::cout << dtCase << std::endl;
    NetworkHandler handler = NetworkHandler(file, size);
    auto endTime = std::chrono::steady_clock::now();

    std::cout << "Input read" << std::endl;

    std::chrono::duration<double> time = endTime - startTime;

    std::cout << "took: " << time.count() << " seconds." << std::endl;

    std::vector<unsigned int> seed;
    for (int i = 5; i != argc; ++i)
    {
        seed.push_back(std::stoul(argv[i]));
    }
    // std::vector<unsigned int> seed = {1000205}; //1000205
    startTime = std::chrono::steady_clock::now();

    InformedNodes reachedNodes = icm::diffuseInformation(handler, seed, size, beta, dtCase);

    endTime = std::chrono::steady_clock::now();
    time = endTime - startTime;

    std::cout << "Ran ICM algorithm" << std::endl;
    std::cout << "took: " << time.count() << " seconds." << std::endl;

    time = endTime - startTime;

    reachedNodes.outputNodesToTerminal();

    std::cout << "reached end of program" << std::endl;

    endTime = std::chrono::steady_clock::now();
    time = endTime - totalStartTime;

    std::cout << "took in total: " << time.count() << " sec" << std::endl;

    return 0;
}