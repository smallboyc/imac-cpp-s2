#include <iostream>
#include <vector>
#include "node.hpp"
#include "utils.hpp"

//1
Node *create_node(int value)
{
    Node *newNode = new Node;
    newNode->value = value;
    return newNode;
}

//2
bool Node::is_leaf() const
{
    return (this->left == nullptr && this->right == nullptr);
}

//3
void Node::insert(int value)
{
    if (value < this->value)
        this->left = create_node(value);
    else
        this->right = create_node(value);
}


//4
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

//5
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
        std::cout << "delete " << this->value << std::endl;
        delete this;
    }
}

//6
void Node::display_infixe() const
{
    // D'abord, je veux choper l'index le plus à gauche au fond de mon arbre
    if (!(this->is_leaf()))
        if (this->left != nullptr)
            this->left->display_infixe();

    // si je suis au bout (une feuille) j'affiche
    std::cout << this->value << std::endl;

    // Après avoir checké à gauche, je check à droite si c'est pas nulle.
    if (this->right != nullptr)
        this->right->display_infixe();
}

//7
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

//9
Node *&most_left(Node *&node)
{
    Node *current = node;
    while (!(current->is_leaf()))
        current = current->left;
    return current;
}

//10 -> Pas fini
bool remove(Node *&node, int value)
{
    if (value == node->value && node->is_leaf())
    {
        delete node;
        node = nullptr;
        return true;
    }
}

//11
void delete_tree(Node *node)
{
    node->delete_childs();
    delete node;
    node = nullptr;
}