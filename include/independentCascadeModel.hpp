#ifndef INDEPENDENTCASCADEMODEL_HPP
#define INDEPENDENTCASCADEMODEL_HPP
#include <vector>
#include <string>
#include <random>
#include "networkHandler.hpp"
#include "node.hpp"

namespace ICM
{
    template <unsigned int size>
    NetworkHandler<size> loadFile(const std::string& filePath)
    {
        return NetworkHandler<size>(filePath);
    }

    std::vector<const Node* const> diffuseInformation(const std::string& filePath, const std::vector<unsigned int>& seed, 
                                                      const float& beta = 1.0,     const std::string& diffusionTimeCase = "best_case")
    {
        
    }
}

#endif