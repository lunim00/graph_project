#include <vector>
#include <string>
#include <random>
#include "networkHandler.hpp"
#include "node.hpp"

namespace ICM
{
    std::vector<const Node* const> diffuseInformation(NetworkHandler& networkHandler, const std::vector<unsigned int>& seed, 
                                                      const float& beta = 1.0, const std::string& diffusionTimeCase = "best_case")
    {
        std::vector<unsigned int> informedNodes;

        for (const unsigned int node : seed)
            informedNodes.emplace_back(node);

        for (const Node* const node : networkHandler.getAdjacentNodes(informedNodes))
        {
            //random not needed unless it's fast enought to use beta
            
        }

    }
}

// def diffuse_information(G: nx.MultiGraph, seed: list, beta: float=1.0, case='best_case'):       
//     informed_nodes = {n: None for n in seed}
//     changed = True

//     while changed:
//         for u, v, dt in G.edges(nbunch=informed_nodes, data='diffusion_time'):
//             changed = False
//             if informed_nodes[u] == None or informed_nodes[u] < dt[case]: # shall we 
//                 if random.random() < beta:
//                     if v not in informed_nodes or dt[case] < informed_nodes[v]:
//                         informed_nodes[v] = dt[case]
//                         changed = True
//     return informed_nodes