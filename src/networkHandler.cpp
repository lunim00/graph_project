#include "networkHandler.hpp"
#include "diffusionTime.hpp"

NetworkHandler::NetworkHandler(const std::string& utilityFile)
{
    std::string line;
    input.open(utilityFile);

    while (getline(input, line))
    {
        Node* currentNode = this->network;
        while (currentNode != nullptr)
            currentNode = currentNode->getNextNode();

        unsigned int index = 0;
        
        std::string date[8];

        for (const char& chr : line)
        {
            if (chr == ' ' || chr == '-' || chr == ':')
                ++index;
            date[index] += chr;
        }

        DiffusionTime time[3] ={
                        {
                            stoi(date[2]),
                            stoi(date[3]),
                            stoi(date[4]),
                            stoi(date[5]),
                            stoi(date[6]),
                            stoi(date[7])
                        },
                        {
                            stoi(date[2]),
                            stoi(date[3]),
                            stoi(date[4]),
                            stoi(date[5]),
                            stoi(date[6]),
                            stoi(date[7])
                        },
                        {
                            stoi(date[2]),
                            stoi(date[3]),
                            stoi(date[4]),
                            stoi(date[5]),
                            stoi(date[6]),
                            stoi(date[7])
                        }
                    };

        currentNode = new Node(stoi(date[0]), stoi(date[1]), time, nullptr);
    }
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
        while (network != nullptr)
        {
            if (network->getNodeID())
        }

        // Node* currentNode = network + node;
        // while (currentNode != nullptr)
        // {
        //     returningNodes.emplace_back(currentNode);
        //     currentNode = currentNode->getNextNode();
        // }
    }

    return returningNodes;
}