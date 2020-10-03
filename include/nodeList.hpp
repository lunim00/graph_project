#ifndef NODELIST_HPP
#define NODELIST_HPP
#include "node.hpp"

class NodeList
{
private:
    node::Node* m_pNode;
    NodeList* m_pNextNodeList;

public:
    NodeList();
    NodeList(node::Node* node, NodeList* nextNodeList);
    ~NodeList();

    node::Node*& getNode();
    NodeList*& getNextNodeList();
};

#endif