#pragma once
#include "Position.h"

struct TreeNode {
    Position pos;
    TreeNode* left;
    TreeNode* right;

    TreeNode(Position p) : pos(p), left(nullptr), right(nullptr) {}
};

class BST {
private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, Position pos);
    bool search(TreeNode* node, Position pos);
    void destroyTree(TreeNode* node);

public:
    BST() : root(nullptr) {}

    void insert(Position pos);
    bool contains(Position pos);

    ~BST();
};