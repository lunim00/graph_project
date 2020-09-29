#ifndef NODEGROUP_HPP
#define NODEGROUP_HPP
#include "node.hpp"

class NodeGroup
{
private:
    Node* m_node;
    NodeGroup* m_nextNodeGroup;

public:
    NodeGroup(Node* node, NodeGroup* nextNodeGroup);
    ~NodeGroup();

    Node*& getNode();
    NodeGroup*& getNextNodeGroup();
};

#endif