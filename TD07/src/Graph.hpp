#pragma once
#include <vector>
#include <unordered_map>
#include <utility>

namespace Graph
{
    struct WeightedGraphEdge
    {
        int to{};
        float weight{1.0f};

        bool operator==(WeightedGraphEdge const &other) const = default;
        bool operator!=(WeightedGraphEdge const &other) const = default;
    };

    struct WeightedGraph
    {
        std::unordered_map<int, std::vector<WeightedGraphEdge>> adjacency_list{};

        void add_vertex(int const id);

        void add_directed_edge(int const from, int const to, float const weight);
        void add_undirected_edge(int const from, int const to, float const weight);

        // Même fonctionnement que pour WeightedGraphEdge
        bool operator==(WeightedGraph const &other) const = default;
        bool operator!=(WeightedGraph const &other) const = default;

        void print_DFS(int const start) const;
        void print_BFS(int const start) const;
    };
    WeightedGraph build_from_adjacency_matrix(std::vector<std::vector<float>> const &adjacency_matrix);
    // Dijkstra
    std::unordered_map<int, std::pair<float, int>> dijkstra(WeightedGraph const &graph, int const &start, int const end);
}
