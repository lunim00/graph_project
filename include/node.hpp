#ifndef NODE_HPP
#define NODE_HPP
#include <string>
#include <iostream>
#include <stdexcept>
#include "diffusionTime.hpp"

class Node
{
private:
    unsigned int m_nodeID;
    unsigned int m_neighborID;
    DiffusionTime m_diffusionTime[3];
    Node* m_pNextNode;
public:
    Node() = delete;
    Node(const unsigned int& nodeID, const unsigned int& neighborID, const DiffusionTime diffusionTimes[3], Node* nextNode);
    ~Node();

    const DiffusionTime& getTimeInterval(const std::string& timeCase) const;
    const unsigned int& getNodeID() const;
    const unsigned int& getNeighborID() const;
    Node* getNextNode() const;
};

#endif