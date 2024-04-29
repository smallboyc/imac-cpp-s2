#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include "node.hpp"
#include "utils.hpp"

// 1
Node *create_node(int value)
{
    Node *newNode = new Node;
    newNode->value = value;
    return newNode;
}

// 2
bool Node::is_leaf() const
{
    return (this->left == nullptr && this->right == nullptr);
}

// 3
void Node::insert(int value)
{
    if (value < this->value)
    {
        if (this->left != nullptr)
            this->left->insert(value);
        else
            this->left = create_node(value);
    }
    else
    {
        if (this->right != nullptr)
            this->right->insert(value);
        else
            this->right = create_node(value);
    }
}

// 4
int Node::height() const
{
    int leftSize{0};
    int rightSize{0};

    if (this->left != nullptr)
        leftSize += 1 + this->left->height();
    if (this->right != nullptr)
        rightSize += 1 + this->right->height();
    if (this->is_leaf())
        return 1;

    if (leftSize < rightSize)
        return rightSize;
    return leftSize;
}

// 5
void Node::delete_childs()
{

    if (this->right != nullptr)
    {
        this->right->delete_childs();
        this->right = nullptr;
    }
    if (this->left != nullptr)
    {
        this->left->delete_childs();
        this->left = nullptr;
    }

    // si c'est une feuille différente de notre root, on supprime!
    if (this->is_leaf() && !(this->is_root))
    {
        // std::cout << "delete " << this->value << std::endl;
        delete this;
    }
}

// 6
void Node::display_infixe() const
{
    // D'abord, je veux choper l'index le plus à gauche au fond de mon arbre
    if (this->left != nullptr)
        this->left->display_infixe();

    // si je suis au bout (une feuille) j'affiche
    std::cout << this->value << " / ";

    // Après avoir checké à gauche, je check à droite si c'est pas nulle.
    if (this->right != nullptr)
        this->right->display_infixe();
}

// 7
std::vector<Node const *> Node::prefixe() const
{
    std::vector<Node const *> nodes;
    nodes.push_back(this);
    // std::cout << this->value << std::endl;
    if (!(this->is_leaf()))
    {
        if (this->left != nullptr)
        {
            // On utilise les méthodes données par le td pour le prefixe()
            auto left_nodes{this->left->prefixe()};
            nodes.insert(nodes.end(), left_nodes.begin(), left_nodes.end());
        }

        if (this->right != nullptr)
        {
            auto right_nodes{this->right->prefixe()};
            nodes.insert(nodes.end(), right_nodes.begin(), right_nodes.end());
        }
    }
    return nodes;
}

// 8
std::vector<Node const *> Node::postfixe() const
{
    std::vector<Node const *> nodes;
    if (!(this->is_leaf()))
    {
        if (this->left != nullptr)
        {
            auto left_nodes{this->left->postfixe()};
            nodes.insert(nodes.end(), left_nodes.begin(), left_nodes.end());
        }

        if (this->right != nullptr)
        {
            auto right_nodes{this->right->postfixe()};
            nodes.insert(nodes.end(), right_nodes.begin(), right_nodes.end());
        }
    }
    nodes.push_back(this);
    // std::cout << this->value << std::endl;
    return nodes;
}

// 9
Node *&most_left(Node *&node)
{
    if (!(node->is_leaf()) && node->left != nullptr)
        return (most_left(node->left));
    return node;
}

// 10
bool remove(Node *&node, int value)
{

    if (node->value > value)
        remove(node->left, value);
    else if (node->value < value)
        remove(node->right, value);
    else
    {
        // CAS 1 : Node n'a pas de fils
        if (node->is_leaf())
        {
            delete node;
            node = nullptr;
            return true;
        }
        // CAS 2 : Node n'a qu'un seul fils
        else if (node->left != nullptr && node->right == nullptr)
        {
            Node *tmp = node->left;
            delete node;
            node = tmp;
        }
        else if (node->right != nullptr && node->left == nullptr)
        {
            Node *tmp = node->right;
            delete node;
            node = tmp;
        }
        // CAS 3 : Node a deux fils
        else
        {
            Node *less = most_left(node->right);
            node->value = less->value;
            remove(node->right, less->value);
        }
        return true;
    }
    return false;
}

// 11
void delete_tree(Node *node)
{
    node->delete_childs();
    delete node;
    node = nullptr;
}

// 12
int Node::min() const
{
    std::vector<Node const *> getNodes{this->postfixe()};
    int minimum{getNodes[0]->value};
    for (int i{0}; i < getNodes.size(); i++)
        if (minimum >= getNodes[i]->value)
            minimum = getNodes[i]->value;
    return minimum;
}

int Node::max() const
{
    std::vector<Node const *> getNodes{this->prefixe()};
    int maximum{getNodes[0]->value};
    for (int i{0}; i < getNodes.size(); i++)
        if (maximum <= getNodes[i]->value)
            maximum = getNodes[i]->value;
    return maximum;
}

int Node::sum41() const
{
    std::vector<Node const *> getNodes{this->postfixe()};
    int sum{0};
    for (int i{0}; i < getNodes.size(); i++)
        sum += getNodes[i]->value;
    return sum;
}
