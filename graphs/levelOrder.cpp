#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

/*
 * - Problem:
 * Level Order
 *
 * - Problem description:
 * Given a binary tree, return the level order traversal of its nodes’ values (ie, from left to right, level by level).
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int n);
};

TreeNode::TreeNode(int n) : val(n) , left(nullptr), right(nullptr) {}

vector<vector<int>> levelTraversal(TreeNode* root) {
    vector<vector<int>> result;
    vector<int> nodesOnCurrLvl;
    unordered_map<TreeNode*, int> lvlOfNode;
    queue<TreeNode*> openNodesQueue;

    int currLvl = 1;

    openNodesQueue.push(root);
    lvlOfNode[root] = 1;

    while (!openNodesQueue.empty()) {
        TreeNode* currNode = openNodesQueue.front();

        // true when we reached a new level
        if (lvlOfNode[currNode] != currLvl) {
            result.push_back(nodesOnCurrLvl); // add the values of the previous nodes to the result
            nodesOnCurrLvl.erase(nodesOnCurrLvl.begin(), nodesOnCurrLvl.end());
            currLvl++;
        }

        nodesOnCurrLvl.push_back(currNode->val);
        openNodesQueue.pop(); // mark the current node as "done"

        // add the child nodes to the queue
        if (currNode->left != nullptr) {
            openNodesQueue.push(currNode->left);
            lvlOfNode[currNode->left] = lvlOfNode[currNode] + 1;
        }
        if (currNode->right != nullptr) {
            openNodesQueue.push(currNode->right);
            lvlOfNode[currNode->right] = lvlOfNode[currNode] + 1;
        }
    }

    result.push_back(nodesOnCurrLvl);
    return result;
}

void levelTraversalTester() {
    auto* A = new TreeNode(1);
    auto* B = new TreeNode(2);
    auto* C = new TreeNode(3);
    auto* D = new TreeNode(4);
    auto* E = new TreeNode(5);

    A->left = B;
    A->right = C;
    B->left = D;
    B ->right = E;

    levelTraversal(A);
}
