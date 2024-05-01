#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include "Graph.hpp"

namespace Graph
{
    void WeightedGraph::add_vertex(int const id)
    {
        // Si le sommet n'existe pas encore, alors on le créer.
        if (this->adjacency_list.find(id) == this->adjacency_list.end())
            adjacency_list.insert({id, {}});
    }

    void WeightedGraph::add_directed_edge(int const from, int const to, float const weight)
    {
        // On s'assure d'avoir les deux sommets pour créer une edge.
        add_vertex(from);
        add_vertex(to);
        // On cible le sommet "from" auquel on ajoute le sommet "to" et le poids de l'edge.
        for (auto &element : this->adjacency_list)
        {
            if (element.first == from)
            {
                element.second.push_back({to, weight});
                break;
            }
        }
        // std::cout << "Edge de " << from << " vers " << to << " créée avec succès." << std::endl;
    }

    void WeightedGraph::add_undirected_edge(int const from, int const to, float const weight)
    {
        add_directed_edge(from, to, weight);
        add_directed_edge(to, from, weight);
    }

    WeightedGraph build_from_adjacency_matrix(std::vector<std::vector<float>> const &adjacency_matrix)
    {
        WeightedGraph graph;
        for (size_t i{0}; i < adjacency_matrix.size(); i++)
            for (size_t j{0}; j < adjacency_matrix.size(); j++)
                if (adjacency_matrix[i][j] != 0)
                    graph.add_directed_edge(i, j, adjacency_matrix[i][j]);
        return graph;
    }
}
