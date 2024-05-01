#include <iostream>
#include "Graph.hpp"
#include "utils.hpp"

using namespace Graph;

int main()
{
    // Graph créé à partir d'un matrice
    std::vector<std::vector<float>> MATRIX{
        {0, 1, 1},
        {2, 0, 1},
        {1, 1, 0}};

    std::cout << "Matrice adjacente : " << std::endl;
    std::cout << MATRIX << std::endl;

    gap();

    WeightedGraph graph_from_MATRIX{build_from_adjacency_matrix(MATRIX)};
    std::cout << "Graphe / from BUILD : " << std::endl;
    std::cout << std::endl;
    std::cout << graph_from_MATRIX << std::endl;

    gap();

    // Graph créé en dur
    WeightedGraph graph_from_SCRATCH;
    graph_from_SCRATCH.add_vertex(0);
    graph_from_SCRATCH.add_vertex(1);
    graph_from_SCRATCH.add_vertex(2);
    graph_from_SCRATCH.add_undirected_edge(0, 1, 1);
    graph_from_SCRATCH.add_undirected_edge(0, 2, 1);
    graph_from_SCRATCH.add_undirected_edge(1, 2, 1);

    std::cout << "Graphe / from SCRATCH : " << std::endl;
    std::cout << std::endl;
    std::cout << graph_from_SCRATCH << std::endl;

    gap();

    // On compare graph_from_MATRIX & graph_from_SCRATCH
    if (graph_from_MATRIX == graph_from_SCRATCH)
        std::cout << "Graphes identiques !" << std::endl;
    else
        std::cout << "Graphes différents !" << std::endl;

    gap();
    return 0;
}