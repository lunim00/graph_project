#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <chrono>
#include "networkHandler.hpp"
#include "IndependentCascadeModel.cpp"
#include "node.hpp"

int main(int argc, char** argv)
{
    std::string file = argv[1];
    unsigned int size = stoi(std::string(argv[2]));
    NetworkHandler handler = NetworkHandler(file, size);

    std::vector<unsigned int> seed;
    auto startTime = std::chrono::steady_clock::now();

    std::vector<const Node* const> reachedNodes = ICM::diffuseInformation(handler, seed);

    auto endTime = std::chrono::steady_clock::now();

    auto time = endTime - startTime;

    return 0;
};