#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include "Graph.hpp"

using namespace Graph;

void WeightedGraph::add_vertex(int const id)
{
    if (this->adjacency_list.size() == 0)
        std::cout << "Hello " << id << std::endl;
}
