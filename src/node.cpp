#include "node.hpp"

    const DiffusionTime& Node::getTimeInterval(const std::string& timeCase) const
    {
        if (timeCase == "best_case")
            return m_diffusionTime[0];
        if (timeCase == "average_case")
            return m_diffusionTime[1];
        if (timeCase == "worst_case")
            return m_diffusionTime[2];
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