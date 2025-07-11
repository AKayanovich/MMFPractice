#include "BST.h"

TreeNode* BST::insert(TreeNode* node, Position pos) 
{
    if (node == nullptr) {
        return new TreeNode(pos);
    }

    int key1 = pos.x * 1000 + pos.y;
    int key2 = node->pos.x * 1000 + node->pos.y;

    if (key1 < key2) {
        node->left = insert(node->left, pos);
    }
    else if (key1 > key2) {
        node->right = insert(node->right, pos);
    }

    return node;
}

bool BST::search(TreeNode* node, Position pos) 
{
    if (node == nullptr) {
        return false;
    }

    int key1 = pos.x * 1000 + pos.y;
    int key2 = node->pos.x * 1000 + node->pos.y;

    if (key1 == key2) {
        return true;
    }
    else if (key1 < key2) {
        return search(node->left, pos);
    }
    else {
        return search(node->right, pos);
    }
}

void BST::destroyTree(TreeNode* node) 
{
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

void BST::insert(Position pos) 
{
    root = insert(root, pos);
}

bool BST::contains(Position pos) 
{
    return search(root, pos);
}

BST::~BST() 
{
    destroyTree(root);
}