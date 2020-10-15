#include <iostream>
#include <string>
#include "networkHandler.hpp"
#include "hashing.hpp"

NetworkHandler::NetworkHandler(const std::string& utilityFile, const std::size_t size):
network(new NodeList[size]), networkSize(size)
{
    createHashTable(utilityFile);
}

NetworkHandler::~NetworkHandler()
{
    // if (network != nullptr)
    //     delete network;
    // network = nullptr;
    delete[] network;
}

std::vector<node::Node*> NetworkHandler::getAdjacentNodes(const std::vector<unsigned int>& nodes)
{
    std::vector<node::Node*> returningNodes;
    for (const unsigned int& informed_node : nodes)
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
    // std::cout << "file opened" << std::endl;
    std::string line;
    std::string currentLine;

    const unsigned int stringOffset = 11;

   while (std::getline(input, line))
   {
        currentLine = line;

        int node1 = stoul(currentLine.substr(0, currentLine.find(" ")));
        currentLine = currentLine.substr(currentLine.find(" ") + 1, currentLine.length());
        int node2 = stoul(currentLine.substr(0, currentLine.find(" ")));
        DiffusionTime date[3];

        for (unsigned int i = 0; i != 3; ++i)
        {
            currentLine = currentLine.substr(currentLine.find("Timestamp('") + stringOffset, currentLine.length());
            date[i] = DiffusionTime(stoul(currentLine.substr(0, 4)), stoul(currentLine.substr(5, 2)),
                                    stoul(currentLine.substr(8, 2)), stoul(currentLine.substr(11, 2)), 
                                    stoul(currentLine.substr(14, 2)), stoul(currentLine.substr(17, 2)));
        }

        createNodeList(node1, new node::Node(node1, node2, date, nullptr));
        createNodeList(node2, new node::Node(node2, node1, date, nullptr));
    }

    input.close();
}

void NetworkHandler::createNodeList(const unsigned int& ID, node::Node* node)
{
    std::size_t index = hashing::hashingFunction(ID, this->networkSize);
    NodeList* currentNodeList = this->network + index;

    while (currentNodeList != nullptr && currentNodeList->getNextNodeList() != nullptr && currentNodeList->getNode() != nullptr && currentNodeList->getNode()->getNodeID() != ID)
    {
        currentNodeList = currentNodeList->getNextNodeList();
    }

    if (currentNodeList->getNode() == nullptr)
    {
        currentNodeList->getNode() = node;
    }
    else if (currentNodeList->getNode()->getNodeID() == ID)
    {
        node::Node* currentNode = currentNodeList->getNode();
        while (currentNode->getNextNode() != nullptr)
        {
            currentNode = currentNode->getNextNode();
        }
        currentNode->setNextNode(node);
    }
    else if (currentNodeList->getNextNodeList() == nullptr)
    {
        currentNodeList->getNextNodeList() = new NodeList(node, nullptr);
    }

}