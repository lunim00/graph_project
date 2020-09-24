#ifndef NETWORK_HPP
#define NETWORK_HPP
#include <array>
#include "timeInterval.hpp"
#include "node.hpp"

template <unsigned int size>
class Network
{
private:
    std::array<Node*, size> m_pNodes;

public:
    Network() = delete;
    Node*& operator[](unsigned int index) const;

};

template <unsigned int size>
Node*& Network<size>::operator[](unsigned int index) const
{
    if (index < 0)
        return nullptr;
    return m_pNodes[index];    
}

#endif