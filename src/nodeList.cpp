#include "nodeList.hpp"

NodeList::NodeList():
m_pNode(nullptr), m_pNextNodeList(nullptr)
{
}

NodeList::NodeList(Node* node, NodeList* NodeList):
m_pNode(node), m_pNextNodeList(NodeList)
{

}

NodeList::~NodeList()
{
    if (m_pNode != nullptr)
    {
        delete m_pNode;
        m_pNode = nullptr;
    }
    if (m_pNextNodeList != nullptr)
    {
        delete m_pNextNodeList;
        m_pNextNodeList = nullptr;
    }
}

Node*& NodeList::getNode()
{
    return this->m_pNode;
}

NodeList*& NodeList::getNextNodeList()
{
    return this->m_pNextNodeList;
}