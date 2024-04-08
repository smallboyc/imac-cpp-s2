#pragma once

struct Node
{
    int value;
    Node *left{nullptr};
    Node *right{nullptr};
    bool is_root{false};
    bool is_leaf() const;
    void insert(int value);
    int height() const;
    void delete_childs();
    void display_infixe() const;
};

Node *create_node(int value);