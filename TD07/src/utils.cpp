#include <iostream>
#include <unordered_map>
#include <vector>

#include "Graph.hpp"

std::ostream &operator<<(std::ostream &os, const Graph::WeightedGraph graph)
{
    for (std::pair p : graph.adjacency_list)
        for (Graph::WeightedGraphEdge edge : p.second)
            os << p.first << " -> " << edge.to << " ( " << edge.weight << " )" << std::endl;
    return os;
}

std::ostream &operator<<(std::ostream &os, const std::vector<std::vector<float>> adjacency_matrix)
{
    for (size_t i{0}; i < adjacency_matrix.size(); i++)
    {
        os << std::endl;
        for (size_t j{0}; j < adjacency_matrix[i].size(); j++)
            os << adjacency_matrix[i][j] << "  ";
    }
    return os;
}

void gap()
{
    std::cout << std::endl;
    std::cout << std::endl;
}