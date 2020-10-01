#include "independentCascadeModel.hpp"
#include "nodeList.hpp"
#include "node.hpp"
#include "diffusionTime.hpp"
#include "informedNodes.hpp"

InformedNodes icm::diffuseInformation(NetworkHandler& networkHandler, const std::vector<unsigned int>& seed, 
                                                             const std::size_t& size, const float& beta = 1.0, 
                                                             const std::string& diffusionTimeCase = "best_case")
{
    InformedNodes informedNodes = InformedNodes(size);

    std::vector<unsigned int> informedNodesIDs;

    for (const unsigned int node : seed)
    {
        informedNodes.addNode(node, DiffusionTime(0, 0, 0, 0, 0, 0));
        informedNodesIDs.emplace_back(node);
    }

    bool changed = true;
    while (changed)
    {
        for (const node::Node* const node : networkHandler.getAdjacentNodes(informedNodesIDs))
        {
            changed = false;
            //random not needed unless it's fast enough to use beta
            DiffusionTime uDT = informedNodes.getNode(node->getNodeID())->dt;
            if (uDT == DiffusionTime(0, 0, 0, 0, 0, 0) || uDT < node->getTimeInterval(diffusionTimeCase))
            {
                //if (random < beta)
                if (informedNodes.getNode(node->getNeighborID()) == nullptr)
                {
                    informedNodes.addNode(node->getNeighborID(), node->getTimeInterval(diffusionTimeCase));
                    informedNodesIDs.emplace_back(node->getNeighborID());
                    changed = true;
                }
                else if (node->getTimeInterval(diffusionTimeCase) < informedNodes.getNode(node->getNeighborID())->dt)
                {
                    informedNodes.getNode(node->getNeighborID())->dt = node->getTimeInterval(diffusionTimeCase);
                    changed = true;
                }
            }
        }
    }
    return informedNodes;
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