#ifndef NETWORKHANDLER_HPP
#define NETWORKHANDLER_HPP
#include <vector>
#include <array>
#include <string>
#include <cstdlib>
#include <fstream>
#include "node.hpp"

class NetworkHandler
{
private:
    Node* network;
    std::size_t size = 0;

    std::ifstream input;

    unsigned int hashingFunction(const unsigned int& num, const std::size_t& size) const;
    //createHashTable()

public:
    NetworkHandler(const std::string& utilityFile);
    ~NetworkHandler();
    std::vector<const Node*& const> getAdjacentNodes(const std::vector<int>& nodes);
};

#endif