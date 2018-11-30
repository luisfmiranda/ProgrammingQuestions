#include <iostream>
#include <vector>

using namespace std;

/*
 * - Problem:
 * Combination sum 2
 *
 * - Problem description:
 * Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate
 * numbers sums to T. Each number in C may only be used once in the combination.
 */

void combinationSum2Helper(vector<int>& candidates, int currIndex, vector<int>& currCombination,
                           int currSum, int target, vector<vector<int>>& ans) {
    if (currSum > target) return; //stopping criteria

    // one solution found
    if (currSum == target) {
        ans.push_back(currCombination);
        return;
    }

    int N = (int)candidates.size();

    if (currIndex >= N) return; // another stopping criteria

    int endIndex;
    for (endIndex = currIndex + 1; (endIndex < N) && (candidates[endIndex] == candidates[endIndex - 1]); endIndex++);

    int countIndex = endIndex - currIndex;

    // recursive exploration of possible combinations
    for (int i = 0; i < countIndex; i++) {
        for (int j = 0; j < i; j++) {
            currCombination.push_back(candidates[currIndex]);
        }

        currSum += i * candidates[currIndex];
        combinationSum2Helper(candidates, endIndex, currCombination, currSum, target, ans);
        currSum -= i * candidates[currIndex];

        for (int j = 0; j < i; j++) {
            currCombination.pop_back();
        }
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<int> currCombination;
    vector<vector<int>> ans;

    sort(candidates.begin(), candidates.end());

    combinationSum2Helper(candidates, 0, currCombination, 0, target, ans);

    return ans;
}

void combinationSum2Tester() {
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};

    vector<vector<int>> ans = combinationSum2(candidates, 8);
}
