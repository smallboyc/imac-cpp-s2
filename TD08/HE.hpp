#pragma once
#include <iostream>
#include <string>
#include <unordered_map>

struct Node
{
    char character;
    size_t frequency;
    Node *left{nullptr};
    Node *right{nullptr};
    bool operator<(Node const &node);
};

std::ostream &operator<<(std::ostream &os, std::unordered_map<char, size_t> chars_width_frequencies);
std::unordered_map<char, size_t> frequency(std::string const str);
Node *createNode(char c, size_t freq);
Node *createSymbolNode(Node *n1, Node *n2);