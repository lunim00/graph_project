#include <iostream>
#include <string>
#include <string_view>
#include <charconv>
#include <stdexcept>
#include "networkHandler.hpp"
#include "hashing.hpp"
#include "utility.hpp"

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
        while (currentNodeList != nullptr && currentNodeList->getNode()->getNodeID() != informed_node)
        {
            currentNodeList = currentNodeList->getNextNodeList();
        }

        if (currentNodeList == nullptr)
            throw std::logic_error("Logic error | Inputed start nodes don't exist in network.");

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
    std::string_view currentLine;

    const unsigned int stringOffset = 11;

   while (std::getline(input, line))
   {
        currentLine = line;

        unsigned int node1;
        utility::stringViewToUnsignedInt(currentLine.data(), currentLine.data() + currentLine.find(' '), node1);
        currentLine = currentLine.substr(currentLine.find(" ") + 1, currentLine.length());
        unsigned int node2;
        utility::stringViewToUnsignedInt(currentLine.data(), currentLine.data() + currentLine.find(' '), node2);
        DiffusionTime date[3];

        std::string toFind = "Timestamp('"; 

        for (unsigned int i = 0; i != 3; ++i)
        {
            currentLine = currentLine.substr(currentLine.find(toFind) + stringOffset, currentLine.length());
            unsigned int year, month, day, hour, minute, second;
            utility::stringViewToUnsignedInt(currentLine.data(), currentLine.data() + 4, year);
            utility::stringViewToUnsignedInt(currentLine.data() + 5, currentLine.data() + 7, month);
            utility::stringViewToUnsignedInt(currentLine.data() + 8, currentLine.data() + 10, day);
            utility::stringViewToUnsignedInt(currentLine.data() + 11, currentLine.data() + 13, hour);
            utility::stringViewToUnsignedInt(currentLine.data() + 14, currentLine.data() + 16, minute);
            utility::stringViewToUnsignedInt(currentLine.data() + 17, currentLine.data() + 19, second);
            
            date[i] = DiffusionTime(year, month,
                                    day, hour, 
                                    minute, second);
        }

        // DiffusionTime date[3] = {
        //     {
        //         stoul(line.substr(60, 4)),
        //         stoul(line.substr(65, 2)),
        //         stoul(line.substr(68, 2)),
        //         stoul(line.substr(71, 2)),
        //         stoul(line.substr(74, 2)),
        //         stoul(line.substr(77, 2))
        //     },
        //     {
        //         stoul(line.substr(110, 4)),
        //         stoul(line.substr(115, 2)),
        //         stoul(line.substr(118, 2)),
        //         stoul(line.substr(121, 2)),
        //         stoul(line.substr(124, 2)),
        //         stoul(line.substr(127, 2))
        //     },
        //     {
        //         stoul(line.substr(60, 4)),
        //         stoul(line.substr(65, 2)),
        //         stoul(line.substr(68, 2)),
        //         stoul(line.substr(71, 2)),
        //         stoul(line.substr(74, 2)),
        //         stoul(line.substr(77, 2))
        //     } 
        // };

        // // std::cout << node1 << ' ' << node2 << ' ' << line.substr(60, 4) << ' ' << line.substr(65, 2) << ' ' << line.substr(68, 2) << ' ' << line.substr(71, 2) << ' ' << line.substr(74, 2) << ' ' << line.substr(77, 2) << std::endl;

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