#ifndef NETWORK_HPP
#define NETWORK_HPP
#include <array>
#include "timeInterval.hpp"

template <unsigned int size>
class Network
{
public:
   struct Node 
    {
        unsigned int m_neighborID;
        timeInterval m_diffusionTime;
        Node* m_pNextNode;
    };

private:
    std::array<Node*, size> m_pNodes;

public:
    Network() = delete;
    Node*& operator[](unsigned int index) const;

};

template <unsigned int size>
Network<size>::Node*& Network<size>::operator[](unsigned int index) const
{
    if (index < 0)
        return nullptr;
    return m_pNodes[index];    
}

#endif