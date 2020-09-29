#ifndef NETWORKHANDLER_HPP
#define NETWORKHANDLER_HPP
#include <vector>
#include <array>
#include <string>
#include <cstdlib>
#include <fstream>
#include "node.hpp"
#include "nodeGroup.hpp"

template <unsigned int size>
class NetworkHandler
{
private:

    NodeGroup* network;
    std::size_t size = 0;

    std::ifstream input;

    void createNodeGroup(const std::size_t& index, Node* node);

    unsigned int hashingFunction(const unsigned int& num, const std::size_t& size) const;
    void createHashTable(const std::string& utilityFile);

public:
    NetworkHandler(const std::string& utilityFile);
    ~NetworkHandler();
    std::vector<const Node*& const> getAdjacentNodes(const std::vector<int>& nodes);
};

#endif