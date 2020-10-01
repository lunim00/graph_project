#ifndef INFORMEDNODES_HPP
#define INFORMEDNODES_HPP
#include <cstdlib>
#include "diffusionTime.hpp"

class InformedNodes
{
public:
    struct Node
    {
        unsigned int index;
        DiffusionTime dt;
        InformedNodes::Node* nextNode;
    };

private:
    InformedNodes::Node* nodes;
    std::size_t size;

public:
    InformedNodes(const std::size_t& size);
    ~InformedNodes();
    void addNode(const unsigned int& ID, const DiffusionTime& dt);
    InformedNodes::Node* getNode(const unsigned int& ID);
    
};

#endif