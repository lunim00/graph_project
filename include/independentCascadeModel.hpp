#ifndef INDEPENDENTCASCADEMODEL_HPP
#define INDEPENDENTCASCADEMODEL_HPP
#include <vector>
#include <string>
#include <string_view>
#include <cstdlib>
#include "networkHandler.hpp"
#include "diffusionTime.hpp"
#include "informedNodes.hpp"

namespace icm
{
    InformedNodes diffuseInformation(NetworkHandler& networkHandler, const std::vector<unsigned int>& seed, 
                                     const std::size_t& size, const std::string& diffusionTimeCase = "best_case");

    InformedNodes diffuseInformation(NetworkHandler& networkHandler, const std::vector<unsigned int>& seed, 
                                     const std::size_t& size, std::string_view diffusionTimeCase = "best_case");

}

#endif