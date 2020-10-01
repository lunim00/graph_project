#include "networkHandler.hpp"
#include "hashing.hpp"

NetworkHandler::NetworkHandler(const std::string& utilityFile, const std::size_t size):
network(new NodeList[size]), networkSize(size)
{
    createHashTable(utilityFile);
}

NetworkHandler::~NetworkHandler()
{
    if (network != nullptr)
        delete network;
    network = nullptr;
    delete[] network;
}

std::vector<const node::Node*& const> NetworkHandler::getAdjacentNodes(const std::vector<unsigned int>& nodes)
{
    std::vector<const node::Node*& const> returningNodes;
    for (const int& informed_node : nodes)
    {
        NodeList* currentNodeList = network + hashing::hashingFunction(informed_node, this->networkSize);
        while (currentNodeList->getNode()->getNodeID() != informed_node)
        {
            currentNodeList = currentNodeList->getNextNodeList();
        }
        node::Node* currentNode = currentNodeList->getNode();
        while (currentNode != nullptr)
        {
            returningNodes.emplace_back(currentNode);
            currentNode = currentNode->getNextNode();
        }
    }

    return returningNodes;
}

void NetworkHandler::createHashTable(const std::string& utilityFile)
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
       DiffusionTime date[3] = {
            {
                stoi(data[2]),
                stoi(data[3]),
                stoi(data[4]),
                stoi(data[5]),
                stoi(data[6]),
                stoi(data[7])
            },
            {
                stoi(data[2]),
                stoi(data[3]),
                stoi(data[4]),
                stoi(data[5]),
                stoi(data[6]),
                stoi(data[7])
            },
            {
                stoi(data[2]),
                stoi(data[3]),
                stoi(data[4]),
                stoi(data[5]),
                stoi(data[6]),
                stoi(data[7])
            } 
        };
        createNodeList(stoi(data[0]), new node::Node(stoi(data[0]), stoi(data[1]), date, nullptr));
        createNodeList(stoi(data[1]), new node::Node(stoi(data[1]), stoi(data[0]), date, nullptr));
    }

    input.close();
}

void NetworkHandler::createNodeList(const unsigned int& ID, node::Node* node)
{
    std::size_t index = hashing::hashingFunction(ID, this->networkSize);
    NodeList* nodeListIndex = network + index;
    bool nodeExists = nodeListIndex->getNode()->getNodeID() == ID;
    bool foundEmptySlot = nodeListIndex->getNode() == nullptr;

    while(!foundEmptySlot && !nodeExists)
    {
        nodeListIndex = nodeListIndex->getNextNodeList();
        nodeExists = nodeListIndex->getNode()->getNodeID() == ID;
        foundEmptySlot = nodeListIndex->getNode() == nullptr;
    }
    if (nodeExists)
    {
        node::Node* currentNode = nodeListIndex->getNode();
        while (currentNode != nullptr)
        {
            currentNode = currentNode->getNextNode();
        }
        *currentNode = *node;
    }
    else
    {
        *nodeListIndex = NodeList(node, nullptr);      
        //this might cause problems, so you should probably look at it :P
    }
}