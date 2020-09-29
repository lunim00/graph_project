#include "nodeGroup.hpp"

NodeGroup::NodeGroup(Node* node, NodeGroup* nodeGroup):
m_node(node), m_nextNodeGroup(nodeGroup)
{

}

NodeGroup::~NodeGroup()
{
    if (m_node != nullptr)
    {
        delete m_node;
        m_node = nullptr;
    }
    if (m_nextNodeGroup != nullptr)
    {
        delete m_nextNodeGroup;
        m_nextNodeGroup = nullptr;
    }
}

Node*& NodeGroup::getNode()
{
    return this->m_node;
}

NodeGroup*& NodeGroup::getNextNodeGroup()
{
    return this->m_nextNodeGroup;
}