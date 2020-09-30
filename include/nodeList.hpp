#ifndef NODELIST_HPP
#define NODELIST_HPP
#include "node.hpp"

class NodeList
{
private:
    Node* m_pNode;
    NodeList* m_pNextNodeList;

public:
    NodeList();
    NodeList(Node* node, NodeList* nextNodeList);
    ~NodeList();

    Node*& getNode();
    NodeList*& getNextNodeList();
};

#endif