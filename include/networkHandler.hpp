#ifndef NETWORKHANDLER_HPP
#define NETWORKHANDLER_HPP
#include <vector>
#include "network.hpp"
#include "node.hpp"

template <unsigned int size>
class NetworkHandler
{
private:
    Network network;

public:
    std::vector<const Node*& const> getAdjacentNodes(const std::vector<int>& nodes);
};

std::vector<const Node*& const> getAdjacentNodes(const std::vector<int>& nodes)
{
    std::vector<const Node*& const>&& returningNodes;
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