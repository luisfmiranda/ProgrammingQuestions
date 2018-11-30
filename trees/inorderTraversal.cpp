#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/*
 * - Problem:
 * Inorder Traversal
 *
 * - Problem description:
 * Given a binary tree, return the inorder traversal of its nodes’ values.
 */

// tree node definition
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;

    stack<TreeNode*> s;
    TreeNode* curr = root;

    while (!s.empty() || curr != NULL) {
        if (curr != NULL) {
            s.push(curr);
            curr = curr->left;
        } else {
            TreeNode* aux = s.top();
            ans.push_back(aux->val);
            s.pop();
            curr = aux->right;
        }
    }

    return ans;
}

void inorderTraversalTester() {
    TreeNode* A = new TreeNode(1);
    TreeNode* B = new TreeNode(2);
    TreeNode* C = new TreeNode(3);
    TreeNode* D = new TreeNode(4);
    TreeNode* E = new TreeNode(5);

    A->left = B;
    A->right = C;
    B->left = D;
    B->right = E;

    vector<int> ans = inorderTraversal(A);
}
