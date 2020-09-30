#include <iostream>
#include <string>
#include <array>
#include "networkHandler.hpp"
#include "IndependentCascadeModel.cpp"

int main(int argc, char** argv)
{
    std::string file = argv[1];
    unsigned int size = stoi(std::string(argv[2]));
    NetworkHandler<size> handler = NetworkHandler<size>(file);


    return 0;
};