#include <iostream>
#include <memory>
#include <array>
#include "node.hpp"
#include "smartNode.hpp"
#include "utils.hpp"

std::array<int, 9> numbers_to_insert{3, 7, 2, 4, 6, 8, 1, 9, 0};

int main()
{

    // EXERCICES 1 & 2
    Node *root = create_node(5);
    root->is_root = true;
    for (const int element : numbers_to_insert)
        root->insert(element);
    remove(root, 7);
    pretty_print_left_right(*root);
    std::cout << std::endl;
    std::cout << "Affichage ordre infixe : ";

    root->display_infixe();
    std::cout << std::endl;
    std::cout << "Valeur minimale de l'arbre : " << root->min() << std::endl;
    std::cout << "Valeur maximale de l'arbre : " << root->max() << std::endl;
    std::cout << "Noeud le plus à gauche de l'arbre : " << most_left(root)->value << std::endl;
    std::cout << "Somme des valeurs de l'arbre : " << root->sum41() << std::endl;
    std::cout << "Hauteur de l'arbre : " << root->height();
    delete_tree(root); // On libère la mémoire

    // EXERCICE 3 - Smart Pointer
    // std::unique_ptr<SmartNode> root = create_smart_node(5);
    // std::cout << root->value << std::endl;
    // for (const int element : numbers_to_insert)
    //     root->insert(element);
    // std::cout << most_left(root)->value << std::endl;

    // EXERCICE 4 - Encapsulation

    return 0;
}