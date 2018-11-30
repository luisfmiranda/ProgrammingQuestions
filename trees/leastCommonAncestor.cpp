#include <iostream>

using namespace std;

/*
 * - Problem:
 * Least Common Ancestor
 *
 * - Problem description:
 * Find the lowest common ancestor in an unordered binary tree given two values in the tree.
 */

// tree node definition
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool leastCommonAncestorHelper(TreeNode* node, int val1, int val2, int& ans) {
    // stopping criterion
    if (node == NULL) return false;

    // keep searching and if one of the recursive calls return true, also returns true
    bool elementFoundOnTheLeft = leastCommonAncestorHelper(node->left, val1, val2, ans);
    bool elementFoundOnTheRight = leastCommonAncestorHelper(node->right, val1, val2, ans);

    // one of the values found
    bool elementFoundCurrNode = (node->val == val1 || node->val == val2);

    // lca found
    if ((elementFoundOnTheLeft && elementFoundOnTheRight) ||
        (elementFoundCurrNode && elementFoundOnTheLeft) ||
        (elementFoundCurrNode && elementFoundOnTheRight)) ans = node->val;

    if (elementFoundCurrNode || elementFoundOnTheLeft || elementFoundOnTheRight) {
        return true;
    } else {
        return false;
    }
}

bool find(TreeNode* root, int val) {
    if (root == NULL) return false;
    if (root->val == val) return true;
    return (find(root->left, val) || find(root->right, val));
}

int leastCommonAncestor(TreeNode* root, int val1, int val2) {
    if (!find(root, val1) && !find(root, val2)) return -1;
    if (val1 == val2) return val1;

    int ans = -1;

    leastCommonAncestorHelper(root, val1, val2, ans);

    return ans;
}

void leastCommonAncestorTester() {
    TreeNode* A = new TreeNode(1);
    TreeNode* B = new TreeNode(2);
    TreeNode* C = new TreeNode(3);
    TreeNode* D = new TreeNode(4);
    TreeNode* E = new TreeNode(5);
    TreeNode* F = new TreeNode(6);
    TreeNode* G = new TreeNode(7);
    TreeNode* H = new TreeNode(8);

    A->left = B;
    A->right = C;
    B->left = D;
    B->right = E;
    C->left = F;
    C->right = G;
    E->left = H;

    cout << leastCommonAncestor(A, 2, 8);
}
