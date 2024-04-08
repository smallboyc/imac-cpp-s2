#include <iostream>
#include <memory>
#include "node.hpp"
#include "utils.hpp"

int main()
{
    Node *root = create_node(10);
    root->is_root = true;
    root->insert(4);
    root->insert(11);
    root->right->insert(14);
    root->right->insert(9);
    root->left->insert(5);
    root->left->insert(2);
    root->right->right->insert(27);
    pretty_print_left_right(*root);
    root->display_infixe();
    std::cout << "Hauteur de l'arbre : " << root->height();
    std::cout << std::endl;
    std::cout << "On libère la mémoire : " << std::endl;
    root->delete_childs();
    pretty_print_left_right(*root);
    delete root;
    return 0;
}