#include "informedNodes.hpp"
#include "hashing.hpp"

InformedNodes::InformedNodes(const std::size_t& size):
nodes(new Node[size]), size(size) //this works as long as there are no ID = 0
{

}

InformedNodes::~InformedNodes()
{
    delete[] nodes;
}

void InformedNodes::addNode(const unsigned int& ID, const DiffusionTime& dt) //timestamp
{
    std::size_t index = hashing::hashingFunction(ID, this->size);
    // InformedNodes::Node* nodeIndexStart = nodes + index;
    InformedNodes::Node* nodeIndexCurrent = nodes + index;

    while (nodeIndexCurrent != nullptr && nodeIndexCurrent->nextNode != nullptr && nodeIndexCurrent->index != 0)
    {
        nodeIndexCurrent = nodeIndexCurrent->nextNode;
    }
    if (nodeIndexCurrent->index == 0)
        *nodeIndexCurrent = InformedNodes::Node(ID, dt, nullptr);
    else if (nodeIndexCurrent->nextNode == nullptr)
        nodeIndexCurrent->nextNode = new InformedNodes::Node(ID, dt, nullptr);
}

InformedNodes::Node* InformedNodes::getNode(const unsigned int& ID)
{
    std::size_t index = hashing::hashingFunction(ID, this->size);
    InformedNodes::Node* nodeIndex = nodes + index;
    
    while (nodeIndex != nullptr && nodeIndex->index != ID)
    {
        nodeIndex = nodeIndex->nextNode;
    }
    return nodeIndex;
}

void InformedNodes::outputNodesToTerminal() const
{
    InformedNodes::Node* currentNode = this->nodes;
    InformedNodes::Node* startNode = this->nodes;
    while (currentNode != startNode + this->size)
    {
        // std::cout << "(node Id: " << currentNode->index << ", time: " << currentNode->dt.toString() << ')' << std::endl;
        // InformedNodes::Node* nextNode = currentNode->nextNode;
        InformedNodes::Node* nextNode = currentNode;
        while (nextNode != nullptr)
        {
            if (nextNode->index != 0)
                std::cout << "(node ID: " << nextNode->index << ", time: " << nextNode->dt.toString() << ')' << std::endl;
            nextNode = nextNode->nextNode;
        }
        ++currentNode;
    }
}