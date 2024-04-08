#include <iostream>
#include "node.hpp"
#include "utils.hpp"

Node *create_node(int value)
{
    Node *newNode = new Node;
    newNode->value = value;
    return newNode;
}

bool Node::is_leaf() const
{
    return (this->left == nullptr && this->right == nullptr);
}

void Node::insert(int value)
{
    if (value < this->value)
        this->left = create_node(value);
    else
        this->right = create_node(value);
}

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

// void Node::display_infixe() const
// {

// }