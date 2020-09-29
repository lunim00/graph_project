#include "networkHandler.hpp"
#include "diffusionTime.hpp"

NetworkHandler::NetworkHandler(const std::string& utilityFile)
{
    createHashTable(utilityFile);
}

NetworkHandler::~NetworkHandler()
{
    if (network != nullptr)
        delete network;
    network = nullptr;
}

std::vector<const Node*& const> NetworkHandler::getAdjacentNodes(const std::vector<int>& nodes)
{
    std::vector<const Node*& const> returningNodes;
    for (const int& informed_node : nodes)
    {
        // Node* currentNode = network + node;
        // while (currentNode != nullptr)
        // {
        //     returningNodes.emplace_back(currentNode);
        //     currentNode = currentNode->getNextNode();
        // }    
    }

    return returningNodes;
}

unsigned int NetworkHandler::hashingFunction(const unsigned int& num, const std::size_t& size) const
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

void NetworkHandler::createHashTable(const std::string& utilityFile)
{
    input.open(utilityFile, std::ifstream::in);
    std::string line;

    unsigned int lineCount = 0;

    while (std::getline(input, line))
    {
        ++lineCount;
    }

    lineCount *= 2;

    input.close();


    this->size = lineCount;


    input.open(utilityFile, std::ifstream::in);

    while (std::getline(input, line))
    {
        unsigned int index = input;
    }

    input.close();
}

void NetworkHandler::createNodeGroup(const std::size_t& index, Node* node)
{
    NodeGroup* nodeIndex = network + index;
    while(nodeIndex != nullptr)
    {
        nodeIndex = nodeIndex->getNextNodeGroup();
    }
    nodeIndex = new NodeGroup(node, nullptr);
}