#ifndef BINARYTREE_H
#define BINARYTREE_H


struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
};

class BinaryTree {
    private:
        TreeNode* _root;

    public:
        BinaryTree();

        TreeNode* getRoot();
        TreeNode* insert(int value);
        void remove(TreeNode* node);
        TreeNode* search(int value);
        TreeNode* update(TreeNode* node, int value);
        void clear();

    private:
        void _transfer(TreeNode* a, TreeNode* b);
        void _clear(TreeNode* node);
};

#endif // BINARYTREE_H

