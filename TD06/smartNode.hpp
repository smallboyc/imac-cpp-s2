#pragma once

#include <vector>


struct SmartNode
{
    int value;
    std::unique_ptr<SmartNode> left{nullptr};
    std::unique_ptr<SmartNode> right{nullptr};

    bool is_leaf() const;
    void insert(int value);

    size_t height() const;

    int min() const;
    int max() const;
};

std::unique_ptr<SmartNode> create_smart_node(int value);
std::unique_ptr<SmartNode> &most_left(std::unique_ptr<SmartNode> &node);
bool remove(std::unique_ptr<SmartNode> &node, int value);