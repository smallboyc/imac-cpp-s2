#include <iostream>
#include "Graph.hpp"
#include "utils.hpp"

using namespace Graph;

int main()
{
    // Graph créé à partir d'un matrice
    std::vector<std::vector<float>> MATRIX{
        {0, 1, 1, 0, 0, 0, 0}, // A
        {0, 0, 0, 1, 1, 0, 0}, // B
        {0, 0, 0, 0, 0, 1, 1}, // C
        {0, 0, 0, 0, 0, 0, 0}, // D
        {0, 0, 0, 0, 0, 0, 0}, // E
        {0, 0, 0, 0, 0, 0, 0}, // F
        {0, 0, 0, 0, 0, 0, 0}, // G
    };

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
    std::cout << "Parcours en PROFONDEUR : " << std::endl;
    graph_from_MATRIX.print_DFS(0);
    gap();
    std::cout << "Parcours en LARGEUR : " << std::endl;
    graph_from_MATRIX.print_BFS(0);
    return 0;
}