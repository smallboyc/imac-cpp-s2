#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>

#include "Graph.hpp"

std::ostream &operator<<(std::ostream &os, const Graph::WeightedGraph graph);
std::ostream &operator<<(std::ostream &os, const std::vector<std::vector<float>> adjacency_matrix);
void gap();