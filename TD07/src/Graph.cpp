#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include "Graph.hpp"

namespace Graph
{
    void WeightedGraph::add_vertex(int const id)
    {
        // On check si le sommet à ajouter existe déjà.
        if (this->adjacency_list.find(id) != this->adjacency_list.end())
            return;

        // Si le sommet n'existe pas encore, alors on le créer.
        adjacency_list.insert({id, {}});
        std::cout << id << " a été ajouté en sommet !" << std::endl;
    }

    void WeightedGraph::add_directed_edge(int const from, int const to, float const weight)
    {
        // On s'assure d'avoir les deux sommets pour créer une edge.
        add_vertex(from);
        add_vertex(to);

        // On cible le sommet "from" auquel on ajoute le sommet "to" et le poids de l'edge.
        for (auto element : adjacency_list)
        {
            if (this->adjacency_list.find(from) == this->adjacency_list.end())
                return;
            element.second.push_back({to, weight});
        }
        std::cout << "Edge de " << from << " vers " << to << " créée avec succès." << std::endl;
    }

    void WeightedGraph::add_undirected_edge(int const from, int const to, float const weight)
    {
        add_directed_edge(from, to, weight);
        add_directed_edge(to, from, weight);
    }

    bool check_if_adjacency_matrix(std::vector<std::vector<float>> const &adjacency_matrix)
    {
        // On check si la matrice est bien une matrice d'adjacence.
        for (size_t i{0}; i < adjacency_matrix.size(); i++)
            for (size_t j{0}; j < adjacency_matrix.size(); j++)
                if (adjacency_matrix[i][j] != adjacency_matrix[j][i])
                {
                    std::cout << "Ce n'est pas une matrice d'adjacence." << std::endl;
                    return false;
                }
        return true;
    }

    WeightedGraph build_from_adjacency_matrix(std::vector<std::vector<float>> const &adjacency_matrix)
    {
        if(check_if_adjacency_matrix(adjacency_matrix))
        {
            
        }
        
        WeightedGraph graph;
        return graph;
    }
}