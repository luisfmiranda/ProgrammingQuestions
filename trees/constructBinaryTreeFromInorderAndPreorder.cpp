#include <iostream>
#include <vector>

using namespace std;

/*
 * - Problem:
 * Construct binary tree from inorder and preorder
 *
 * - Problem description:
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * You may assume that duplicates do not exist in the tree.
 */

// tree node definition
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTreeHelper(vector<int>::iterator prl, vector<int>::iterator prr,
                          vector<int>::iterator inl, vector<int>::iterator inr) {
    // stopping criteria
    if (prl >= prr) {
        return NULL;
    }

    int rootValue = *prl;
    TreeNode* root = new TreeNode(rootValue);

    // the find function return an pointer for the element inside the inorder traversal vector that represents the root
    vector<int>::iterator rootIndex = find(inl, inr, rootValue);

    // the size_type means: declare x as a variable of a type suitable for holding the size of a vector
    vector<int>::size_type leftSize = rootIndex - inl;

    // set all parameters for the recursive calls, which will fill the nodes for the children
    root->left = buildTreeHelper(prl + 1, prl + 1 + leftSize, inl, rootIndex);
    root->right = buildTreeHelper(prl + 1 + leftSize, prr, rootIndex + 1, inr);

    return root;
}

TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.size() == 0) return NULL;
    return buildTreeHelper(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
}

void buildTreeTester() {
    vector<int> preorder = {1, 2, 3, 4, 5, 6, 7};
    vector<int> inorder = {3, 2, 4, 1, 6, 5, 7};

    buildTree(preorder, inorder);
}
