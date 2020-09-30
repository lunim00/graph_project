#include "networkHandler.hpp"

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

std::vector<const Node*& const> NetworkHandler::getAdjacentNodes(const std::vector<unsigned int>& nodes)
{
    std::vector<const Node*& const> returningNodes;
    for (const int& informed_node : nodes)
    {
        NodeList* currentNodeList = network + hashingFunction(informed_node, this->networkSize);
        while (currentNodeList->getNode()->getNodeID() != informed_node)
        {
            currentNodeList = currentNodeList->getNextNodeList();
        }
        Node* currentNode = currentNodeList->getNode();
        while (currentNode != nullptr)
        {
            returningNodes.emplace_back(currentNode);
            currentNode = currentNode->getNextNode();
        }
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
            }
            ,
            {
                stoi(data[2]),
                stoi(data[3]),
                stoi(data[4]),
                stoi(data[5]),
                stoi(data[6]),
                stoi(data[7])
            }
            ,
            {
                stoi(data[2]),
                stoi(data[3]),
                stoi(data[4]),
                stoi(data[5]),
                stoi(data[6]),
                stoi(data[7])
            } 
        };
        createNodeList(hashingFunction(stoi(data[0]), this->networkSize), new Node(stoi(data[0]), stoi(data[1]), date, nullptr));
        createNodeList(hashingFunction(stoi(data[1]), this->networkSize), new Node(stoi(data[1]), stoi(data[0]), date, nullptr));
    }

    input.close();
}

void NetworkHandler::createNodeList(const unsigned int& ID, Node* node)
{
    std::size_t index = ID;
    NodeList* nodeListIndex = network + index;
    bool notFoundNodeID = nodeListIndex->getNode() != nullptr && nodeListIndex->getNode()->getNodeID() != ID;
    bool nodeListSlotNotEmpty = nodeListIndex != nullptr;

    while(notFoundNodeID || nodeListSlotNotEmpty)
    {
        nodeListIndex = nodeListIndex->getNextNodeList();
    }
    if (!notFoundNodeID)
    {
        Node* currentNode = nodeListIndex->getNode();
        while (currentNode != nullptr)
        {
            currentNode = currentNode->getNextNode();
        }
        *currentNode = *node;
    }
    else
    {
        *nodeListIndex = NodeList(node, nullptr);      
        //this might cause problems, so you should probably look it over :P
    }
}