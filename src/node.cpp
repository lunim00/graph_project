#include "node.hpp"

Node::Node(const unsigned int& nodeID, const unsigned int& neighborID, const DiffusionTime diffusionTimes[3], Node* nextNode):
nodeID(nodeID),
m_neighborID(neighborID), 
m_diffusionTime{diffusionTimes[0], diffusionTimes[1], diffusionTimes[2]}, 
m_pNextNode(nextNode)
{
}

Node::~Node()
{
    if (m_pNextNode != nullptr)
        delete m_pNextNode;
    m_pNextNode = nullptr;
}

const DiffusionTime& Node::getTimeInterval(const std::string& timeCase) const
{
    try
    {
        if (timeCase == "best_case")
            return m_diffusionTime[0];
        if (timeCase == "average_case")
            return m_diffusionTime[1];
        if (timeCase == "worst_case")
            return m_diffusionTime[2];
        else
            throw std::logic_error("Logic error | undefined case parameter inputed.");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

const unsigned int& Node::getNodeID() const
{
    return this->getNodeID;
}

const unsigned int& Node::getNeighborID() const
{
    return this->m_neighborID;
}

Node* Node::getNextNode() const
{
    return this->m_pNextNode;
}