#include <iostream>
#include <vector>

using namespace std;

/*
 * - Problem:
 * uniqueBinarySearchTrees
 *
 * - Problem description:
 * Given A, generate all structurally unique BST’s (binary search trees) that store values 1 ... A.
 */

// tree node definition
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode*> uniqueBinarySearchTreesHelper(int lowerLimit, int upperLimit) {
    vector<TreeNode*> currAns;

    if (upperLimit - lowerLimit < 0) return currAns; // stopping criteria

    // each element in the interval [lowerLimit : upperLimit] will be taken as root in each iteration
    for (int i = lowerLimit; i <= upperLimit; i++) {
        // the root divide the interval and the recursive calls find the answer for each partition
        vector<TreeNode*> leftChildren = uniqueBinarySearchTreesHelper(lowerLimit, i - 1);
        vector<TreeNode*> rightChildren = uniqueBinarySearchTreesHelper(i + 1, upperLimit);

        TreeNode* currNode;

        // find the way the lists of trees of each partition should be added to the solution
        if (leftChildren.size() == 0 && rightChildren.size() == 0) {
            currAns.push_back(new TreeNode(i));
        } else if (leftChildren.size() == 0) {
            for (int j = 0; j < rightChildren.size(); j++) {
                currNode = new TreeNode(i);
                currNode->right = rightChildren[j];
                currAns.push_back(currNode);
            }
        } else if (rightChildren.size() == 0) {
            for (int j = 0; j < leftChildren.size(); j++) {
                currNode = new TreeNode(i);
                currNode->left = leftChildren[j];
                currAns.push_back(currNode);
            }
        } else {
            for (int j = 0; j < leftChildren.size(); j++) {
                for (int k = 0; k < rightChildren.size(); k++) {
                    currNode = new TreeNode(i);
                    currNode->left = leftChildren[j];
                    currNode->right = rightChildren[k];
                    currAns.push_back(currNode);
                }
            }
        }
    }

    return currAns;
}

vector<TreeNode*> uniqueBinarySearchTrees(int n) {
    vector<TreeNode*> ans;

    uniqueBinarySearchTreesHelper(1, n);

    return ans;
}

void uniqueBinarySearchTreesTester() {
    vector<TreeNode*> ans = uniqueBinarySearchTrees(3);
}
