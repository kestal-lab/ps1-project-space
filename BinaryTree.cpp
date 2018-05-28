#include "BinaryTree.h"

BinaryTree::BinaryTree() : _root(nullptr) {

}

TreeNode* BinaryTree::getRoot() {
    return _root;
}

TreeNode* BinaryTree::insert(int value) {
    TreeNode* node = new TreeNode();
    node->value = value;
    node->left = nullptr;
    node->right = nullptr;
    node->parent = nullptr;

    TreeNode** p = &_root;
    while (*p) {
        node ->parent = *p;
        if ((*p)->value > value)
            p = &(*p)->left;
        else
            p = &(*p)->right;
    }
    *p = node;
    return node;
}

TreeNode* BinaryTree::search(int value) {
    TreeNode* node = _root;
    while (node && node->value != value) {
        if (node->value > value)
            node = node->left;
        else
            node = node->right;
    }
    return node;
}

void BinaryTree::remove(TreeNode* node) {
    if (!node)
        return;

    if (node->left && node->right) {
        TreeNode* nodeSucc = node->right;
        while (nodeSucc->left)
            nodeSucc = nodeSucc->left;
        if (nodeSucc == node->right) {
            _transfer(node, nodeSucc);
            nodeSucc->left = node->left;
            nodeSucc->left->parent = nodeSucc;
        }
        else {
            _transfer(nodeSucc, nodeSucc->right);
            _transfer(node, nodeSucc);
            nodeSucc->left = node->left;
            nodeSucc->right = node->right;
            nodeSucc->left->parent = nodeSucc;
            nodeSucc->right->parent = nodeSucc;
        }
    }
    else if (node->left)
        _transfer(node, node->left);
    else
        _transfer(node, node->right);

    delete node;
}

TreeNode* BinaryTree::update(TreeNode* node, int value) {
    remove(node);
    return insert(value);
}

void BinaryTree::clear() {
    _clear(_root);
    _root = nullptr;
}

void BinaryTree::_transfer(TreeNode* a, TreeNode* b) {
    if (b)
        b->parent = a->parent;
    if (!a->parent)
        _root = b;
    else if (a == a->parent->left)
        a->parent->left = b;
    else
        a->parent->right = b;
}

void BinaryTree::_clear(TreeNode* node) {
    if (!node)
        return;
    _clear(node->left);
    _clear(node->right);
    delete node;
}

