#ifndef NODE_HPP
#define NODE_HPP
#include <string>
#include <exception>
#include "diffusionTime.hpp"

class Node
{
private:

    unsigned int m_neighborID
    DiffusionTime m_diffusionTime[3];
    Node* m_pNextNode;

public:
    const TimeInterval& getTimeInterval(const std::string& case) const
    {
        if (case == "best_case")
            return m_diffusionTime[0];
        if (case == "average_case")
            return m_diffustionTime[1];
        if (case == "worst_case")
            return m_diffustionTime[2];
        else
            try
            {
                throw std::logic_error("Logic error | undefined case parameter inputed.");
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            
        
    }
};

#endif