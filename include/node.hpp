#ifndef NODE_HPP
#define NODE_HPP
#include <string>
#include <string_view>
#include <iostream>
#include <stdexcept>
#include "diffusionTime.hpp"

namespace node
{
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
        Node(const node::Node& other);
        ~Node();

        const DiffusionTime& getTimeInterval(std::string_view timeCase) const;
        const unsigned int& getNodeID() const;
        const unsigned int& getNeighborID() const;
        void setNextNode(node::Node* nextNode);
        Node* getNextNode() const;
    };
}


#endif