#include <iostream>

using namespace std;

/*
 * - Problem:
 * Symmetric Binary Tree
 *
 * - Problem description:
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 */

// tree node definition
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool helper(TreeNode* n1, TreeNode* n2) {
    if (n1 == NULL && n2 == NULL) return true;
    if (n1 == NULL || n2 == NULL) return false;

    return ((n1->val == n2->val) && helper(n1->left, n2->right) && helper(n1->right, n2->left));
}

bool SymmetricBinaryTree(TreeNode* root) {
    return helper(root->left, root->right);
}

void SymmetricBinaryTreeTester() {
    TreeNode* A = new TreeNode(1);
    TreeNode* B = new TreeNode(2);
    TreeNode* C = new TreeNode(2);
    TreeNode* D = new TreeNode(4);
    TreeNode* E = new TreeNode(5);
    TreeNode* F = new TreeNode(5);
    TreeNode* G = new TreeNode(4);
    TreeNode* H = new TreeNode(8);

    A->left = B;
    A->right = C;
    B->left = D;
    B->right = E;
    C->left = F;
    C->right = G;
    E->left = H;

    cout << SymmetricBinaryTree(A);
}
