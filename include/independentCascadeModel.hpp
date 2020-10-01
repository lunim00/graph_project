#ifndef INDEPENDENTCASCADEMODEL_HPP
#define INDEPENDENTCASCADEMODEL_HPP
#include <vector>
#include <string>
#include <cstdlib>
#include "networkHandler.hpp"
#include "diffusionTime.hpp"
#include "informedNodes.hpp"

namespace icm
{
    struct Node
    {
        unsigned int index;
        DiffusionTime dt;
    };

    InformedNodes diffuseInformation(NetworkHandler& networkHandler, const std::vector<unsigned int>& seed, 
                                                            const std::size_t& size, const float& beta = 1.0, 
                                                            const std::string& diffusionTimeCase = "best_case");

};

#endif