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
    // root->right->right->insert(27);

    pretty_print_left_right(*root);
    std::cout << std::endl;
    std::cout << "Affichage ordre infixe : ";
    root->display_infixe();
    std::cout << std::endl;
    // root->prefixe();
    // root->postfixe();
    std::cout << "Valeur minimale de l'arbre : " << root->min() << std::endl;
    std::cout << "Valeur maximale de l'arbre : " << root->max() << std::endl;
    std::cout << "Noeud le plus à gauche de l'arbre : " << most_left(root)->value << std::endl;
    std::cout << "Somme des valeurs de l'arbre : " << root->sum41() << std::endl;
    std::cout << "Hauteur de l'arbre : " << root->height();
    delete_tree(root); // On libère la mémoire
    return 0;
}