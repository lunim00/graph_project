#include <iostream>
#include <fstream>
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
    unsigned int nodeAmount = 0;

    while (currentNode != startNode + this->size)
    {
        // std::cout << "(node Id: " << currentNode->index << ", time: " << currentNode->dt.toString() << ')' << std::endl;
        // InformedNodes::Node* nextNode = currentNode->nextNode;
        InformedNodes::Node* nextNode = currentNode;
        while (nextNode != nullptr)
        {
            if (nextNode->index != 0)
            {
                std::cout << "{nodeID: " << std::to_string(nextNode->index) << ", time: " << nextNode->dt.toString() << "}\n";
                ++nodeAmount;
            }
            nextNode = nextNode->nextNode;
        }
        ++currentNode;
    }
    std::cout << nodeAmount << " nodes were reached." << std::endl;
}

void InformedNodes::outputNodesToFile(const std::string& filePath) const
{
    std::ofstream output;
    
    std::string outputStr = "";

    InformedNodes::Node* currentNode = this->nodes;
    InformedNodes::Node* startNode = this->nodes;
    unsigned int nodeAmount = 0;

    while (currentNode != startNode + this->size)
    {
        InformedNodes::Node* nextNode = currentNode;
        while (nextNode != nullptr)
        {
            if (nextNode->index != 0)
            {
                outputStr += "{nodeID: " + std::to_string(nextNode->index) + ", time: " + nextNode->dt.toString() + "}\n";
                ++nodeAmount;
            }
            nextNode = nextNode->nextNode;
        }
        ++currentNode;
    }

    std::cout << nodeAmount << " nodes were reached and results were outputed to " << filePath << std::endl;

    output.open(filePath);
    output << outputStr;
    output.close();
}