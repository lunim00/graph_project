#ifndef NETWORKHANDLER_HPP
#define NETWORKHANDLER_HPP
#include <vector>
#include <array>
#include <string>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include "node.hpp"
#include "nodeList.hpp"
#include "diffusionTime.hpp"

class NetworkHandler
{
private:
    NodeList* network;
    std::size_t networkSize;

    std::ifstream input;

    void createNodeList(const unsigned int& ID, Node* node);

    unsigned int hashingFunction(const unsigned int& num, const std::size_t& size) const;
    void createHashTable(const std::string& utilityFile);

public:
    NetworkHandler(const std::string& utilityFile, const std::size_t size);
    ~NetworkHandler();
    std::vector<const Node*& const> getAdjacentNodes(const std::vector<unsigned int>& nodes);
};

#endif