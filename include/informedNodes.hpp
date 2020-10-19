#ifndef INFORMEDNODES_HPP
#define INFORMEDNODES_HPP
#include <cstdlib>
#include <string>
#include "diffusionTime.hpp"

class InformedNodes
{
public:
    struct Node
    {
        unsigned int index;
        DiffusionTime dt;
        InformedNodes::Node* nextNode;

        Node(): index(0), dt(DiffusionTime(0, 0, 0, 0, 0, 0)), nextNode(nullptr)
        {

        }

        Node(const unsigned int& index, const DiffusionTime& dt, Node* nextNode):
        index(index), dt(dt), nextNode(nextNode)
        {
        }
    };

private:
    InformedNodes::Node* nodes;
    std::size_t size;

public:
    InformedNodes(const std::size_t& size);
    ~InformedNodes();
    void addNode(const unsigned int& ID, const DiffusionTime& dt);
    InformedNodes::Node* getNode(const unsigned int& ID);
    void outputNodesToTerminal() const;
    void outputNodesToFile(const std::string& filePath) const;
};

#endif