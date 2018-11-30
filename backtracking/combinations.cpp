#include <iostream>
#include <vector>

using namespace std;

/*
 * - Problem:
 * Combinations
 *
 * - Problem description:
 * Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.
 * Make sure the combinations are sorted.
 */

void combinationsHelper(vector<vector<int>>& ans, vector<int>& currComb, int currValue, int n, int k) {
    //stopping criteria
    if (currValue > n && currComb.size() < k) return;

    // valid combination found
    if (currComb.size() == k) {
        ans.push_back(currComb);
        return;
    }

    // select an elment as the beginning of the combination and find the combinations for it
    for (int i = currValue; i <= n; i++) {
        currComb.push_back(currValue);
        combinationsHelper(ans, currComb, currValue + 1, n, k);
        currComb.pop_back();

        currValue++;
    }
}

vector<vector<int>> combinations(int n, int k) {
    vector<vector<int>> ans;
    vector<int> currComb;

    combinationsHelper(ans, currComb, 1, n, k);

    return ans;
}

void combinationsTester() {
    vector<vector<int>> ans = combinations(4, 2);
}
