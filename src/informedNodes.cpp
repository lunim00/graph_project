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
    InformedNodes::Node* nodeIndex = nodes + index;

    while (nodeIndex->index != 0) // == 0 is just for testing purposes... this should be changed, will cause problems if this is nullptr
    {
        nodeIndex->nextNode;
    }
    // if (nodeIndex == nullptr)
    //     *nodeIndex = {ID, nullptr};
    // else
    //     *nodeIndex = {ID, nullptr};
    *nodeIndex = Node(ID, dt, nullptr);
}

InformedNodes::Node* InformedNodes::getNode(const unsigned int& ID)
{
    std::size_t index = hashing::hashingFunction(ID, this->size);
    InformedNodes::Node* nodeIndex = nodes + index;
    
    while (nodeIndex != nullptr && nodeIndex->index != index)
    {
        nodeIndex = nodeIndex->nextNode;
    }
    return nodeIndex;
}

void InformedNodes::outputNodesToTerminal() const
{
    InformedNodes::Node* currentNode = this->nodes;
    while (currentNode != currentNode + this->size)
    {
        // std::cout << "(node Id: " << currentNode->index << ", time: " << currentNode->dt.toString() << ')' << std::endl;
        // InformedNodes::Node* nextNode = currentNode->nextNode;
        InformedNodes::Node* nextNode = currentNode;
        while (nextNode != nullptr)
        {
            std::cout << "(node ID: " << nextNode->index << ", time: " << nextNode->dt.toString() << ')' << std::endl;
            nextNode = nextNode->nextNode;
        }
        ++currentNode;
    }
}