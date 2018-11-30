#include <iostream>

using namespace std;

/*
 * - Problem:
 * Populate Next Right Pointers Tree
 *
 * - Problem description:
 * Given a binary tree, populate each next pointer to point to its next right node. If there is no next right node, the
 * next pointer should be set to NULL. Initially, all next pointers are set to NULL.
 */

// tree node definition (with a next pointer)
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *next;
    TreeNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void populateNextRightPointersTree(TreeNode* root) {
    TreeNode* leftWall = NULL; // leftmost node of the next level
    TreeNode* prev = NULL; // leading node on the next level
    TreeNode* curr = root; // current node on the current level

    while (curr != NULL) {
        while (curr != NULL) {
            if (curr->left != NULL) {
                if (prev != NULL) {
                    prev->next = curr->left;
                } else {
                    leftWall = curr->left;
                }

                prev = curr->left;
            }

            if (curr->right != NULL) {
                if (prev != NULL) {
                    prev->next = curr->right;
                } else {
                    leftWall = curr->right;
                }

                prev = curr->right;
            }

            curr = curr->next; // move to the next node
        }

        // move to the next level
        curr = leftWall;
        leftWall = NULL;
        prev = NULL;
    }
}

void populateNextRightPointersTreeTester() {
    TreeNode* A = new TreeNode(1);
    TreeNode* B = new TreeNode(2);
    TreeNode* C = new TreeNode(3);
    TreeNode* D = new TreeNode(4);
    TreeNode* E = new TreeNode(5);

    A->left = B;
    A->right = C;
    B->left = D;
    B->right = E;

    populateNextRightPointersTree(A);
}
