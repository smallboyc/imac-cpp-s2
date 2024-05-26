#include <iostream>
#include <string>
#include <unordered_map>
#include "HE.hpp"

std::ostream &operator<<(std::ostream &os, std::unordered_map<char, size_t> chars_width_frequencies)
{
    for (std::pair<char, size_t> c : chars_width_frequencies)
        os << c.first << " -> " << c.second << std::endl;
    return os;
}

// 1
std::unordered_map<char, size_t> frequency(std::string const str)
{
    std::unordered_map<char, size_t> chars_width_frequencies;
    for (char c : str)
    {
        size_t freq{0};
        char current{c};
        for (char other_c : str)
        {
            if (current == other_c)
                freq++;
        }
        chars_width_frequencies.insert({current, freq});
    }
    return chars_width_frequencies;
}

// 2
bool Node::operator<(Node const &node)
{
    if (node.left->frequency < node.right->frequency)
        return true;
    return false;
}

// 3
Node *createNode(char c, size_t freq)
{
    Node *newNode = new Node;
    newNode->character = c;
    newNode->frequency = freq;
    return newNode;
}

// 4
Node *createSymbolNode(Node *n1, Node *n2)
{
    Node *newSymbolNode = createNode('0', n1->frequency + n2->frequency);
    newSymbolNode->left = n1;
    newSymbolNode->right = n2;
    return newSymbolNode;
}