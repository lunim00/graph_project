#ifndef NETWORKHANDLER_HPP
#define NETWORKHANDLER_HPP
#include <vector>
#include "network.hpp"

template <unsigned int size>
class NetworkHandler
{
private:
    Network network;

public:
    std::vector<const Network<size>::Node*& const> getAdjacentNodes(const std::vector<int>& nodes);
};

template <unsigned int size>
std::vector<const Network<size>::Node*& const> getAdjacentNodes(const std::vector<int>& nodes)
{
    std::vector<const Network<size>::Node*& const>&& returningNodes;
    for (const int& node : nodes)
    {
        Node* currentNode = network[node];
        while (currentNode != nullptr)
        {
            returningNodes.append(currentNode);
            currentNode = currentNode->m_pNextNode;
        }
    }

    return std::move(returningNodes);
}

#endif