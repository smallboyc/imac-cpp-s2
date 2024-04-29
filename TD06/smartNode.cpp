#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <memory>
#include "smartNode.hpp"
#include "utils.hpp"

std::unique_ptr<SmartNode> create_smart_node(int value)
{
    std::unique_ptr<SmartNode> node{std::make_unique<SmartNode>()};
    node->value = value;
    return node;
}

bool SmartNode::is_leaf() const
{
    if (this->left || this->right)
        return false;
    else
        return true;
}

void SmartNode::insert(int value)
{
    if (value < this->value)
    {
        if (this->left)
            this->left->insert(value);
        else
            this->left = create_smart_node(value);
    }
    else
    {
        if (this->right)
            this->right->insert(value);
        else
            this->right = create_smart_node(value);
    }
}

// 3
std::unique_ptr<SmartNode> &most_left(std::unique_ptr<SmartNode> &node)
{
    if (node->left)
        return (most_left(node->left));
    return node;
}