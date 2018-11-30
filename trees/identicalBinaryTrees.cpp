#include <iostream>

using namespace std;

/*
 * - Problem:
 * Identical Binary Trees
 *
 * - Problem description:
 * Given two binary trees, write a function to check if they are equal or not.
 * Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
 */

// tree node definition
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool areIdentical(TreeNode* p, TreeNode* q) {
    // stopping criteria
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q == NULL) return false;

    // true when the root values are the same and the left and right subtrees are the same
    return (p->val == q->val && areIdentical(p->left, q->left) && areIdentical(p->right, q->right));
}
