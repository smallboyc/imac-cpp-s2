#include <iostream>
#include "Graph.hpp"

using namespace Graph;

int main()
{
    std::vector<std::vector<float>> MATRIX{
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 0},
        {0, 1, 0, 0}};
    // WeightedGraph graph;
    // graph.add_undirected_edge(24, 12, 3);
    build_from_adjacency_matrix(MATRIX);
    return 0;
}