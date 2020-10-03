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
    std::string file = argv[1];
    std::cout << "file: " << file << std::endl;
    unsigned int size = stoi(std::string(argv[2]));
    std::cout << "size: " << size << std::endl;
    NetworkHandler handler = NetworkHandler(file, size);

    std::cout << "handler created" << std::endl;

    std::vector<unsigned int> seed = {1};
    auto startTime = std::chrono::steady_clock::now();

    InformedNodes reachedNodes = icm::diffuseInformation(handler, seed, size);

    auto endTime = std::chrono::steady_clock::now();

    auto time = endTime - startTime;

    reachedNodes.outputNodesToTerminal();

    std::cout << "reached end of program" << std::endl;

    return 0;
};