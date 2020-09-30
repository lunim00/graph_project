#ifndef NETWORKHANDLER_HPP
#define NETWORKHANDLER_HPP
#include <vector>
#include <array>
#include <string>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include "node.hpp"
#include "nodeGroup.hpp"

template <std::size_t size>
class NetworkHandler
{
private:

    std::array<NodeGroup*, size> network;

    std::ifstream input;

    void createNodeGroup(const std::size_t& index, Node* node);

    unsigned int hashingFunction(const unsigned int& num, const std::size_t& size) const;
    void createHashTable(const std::string& utilityFile);

public:
    NetworkHandler(const std::string& utilityFile);
    ~NetworkHandler();
    std::vector<const Node*& const> getAdjacentNodes(const std::vector<int>& nodes);
};

template <std::size_t size>
NetworkHandler<size>::NetworkHandler(const std::string& utilityFile)
{
    std::fill(network, network + size, nullptr);
    createHashTable(utilityFile);
}

template <std::size_t size>
NetworkHandler<size>::~NetworkHandler()
{
    if (network != nullptr)
        delete network;
    network = nullptr;
}

template <std::size_t size>
std::vector<const Node*& const> NetworkHandler<size>::getAdjacentNodes(const std::vector<int>& nodes)
{
    std::vector<const Node*& const> returningNodes;
    for (const int& informed_node : nodes)
    {
        NodeGroup* currentNodeGroup = network[hashingFunction(informed_node)];
        while (currentNodeGroup->getNode()->getNodeID() != informed_node)
        {
            currentNodeGroup = currentNodeGroup->getNextNodeGroup();
        }
        Node* currentNode = currentNodeGroup->getNode();
        while (currentNode != nullptr)
        {
            returningNodes.emplace_back(currentNode);
            currentNode = currentNode->getNextNode();
        }
    }

    return returningNodes;
}

template <std::size_t size>
unsigned int NetworkHandler<size>::hashingFunction(const unsigned int& num, const std::size_t& size) const
{
    unsigned int hashedNum = 0;
    unsigned int n = num;
    unsigned int count = 0;
    unsigned int currentNum;

    while (n != 0)
    {
        ++count;
        n /= 10;
    }
    currentNum = num;
    for (int i = 1; i != count; ++i)
    {
        // hashedNum += num / (count - i) * (i + 1);
        unsigned int diff = currentNum % (10 ^ (count - i));
        hashedNum += (currentNum - diff) * i;
        currentNum = diff;
    }

    hashedNum %= size; //se till att detta nummer är större än eller minst lika med storleken, 
                       //annars kommer alla talen hamna på första indexet.

    return hashedNum;
}

template <std::size_t size>
void NetworkHandler<size>::createHashTable(const std::string& utilityFile)
{
    input.open(utilityFile, std::ifstream::in);
    std::string line;

    std::string data[8];

   while (std::getline(input, line))
   {
       unsigned int index;
       for (const char& chr : line)
       {
            if (chr == ' ' || chr == '-' || chr == ':')
                ++index;
            else
                data[index] += chr;
       }
       createNodeGroup(hashingFunction(stoi(data[0])), Node(stoi(data[0]), stoi(data[1]), 
                                                            DiffusionTime(
                                                                            stoi(data[2]),
                                                                            stoi(data[3]),
                                                                            stoi(data[4]),
                                                                            stoi(data[5]),
                                                                            stoi(data[6]),
                                                                            stoi(data[7])
                                                                         )
                                                            ),
                                                            DiffusionTime(
                                                                            stoi(data[2]),
                                                                            stoi(data[3]),
                                                                            stoi(data[4]),
                                                                            stoi(data[5]),
                                                                            stoi(data[6]),
                                                                            stoi(data[7])
                                                                         )
                                                            ),
                                                            DiffusionTime(
                                                                            stoi(data[2]),
                                                                            stoi(data[3]),
                                                                            stoi(data[4]),
                                                                            stoi(data[5]),
                                                                            stoi(data[6]),
                                                                            stoi(data[7])
                                                                         )
                                                            )
                       );
   }

    input.close();
}

template <std::size_t size>
void NetworkHandler<size>::createNodeGroup(const std::size_t& index, Node* node)
{
    NodeGroup* nodeIndex = network[index];
    while(nodeIndex != nullptr)
    {
        nodeIndex = nodeIndex->getNextNodeGroup();
    }
    nodeIndex = new NodeGroup(node, nullptr);
}

#endif