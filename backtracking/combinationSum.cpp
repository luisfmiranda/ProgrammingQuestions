#include <iostream>
#include <vector>

using namespace std;

/*
 * - Problem:
 * Combination sum
 *
 * - Problem description:
 * Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate
 * numbers sums to T. The same repeated number may be chosen from C unlimited number of times.
 */

void combinationSumHelper(vector<int>& uniqueCandidates, int currIndex, vector<int>& currCombination,
                          int currSum, int target, vector<vector<int>>& ans) {
    if (currSum > target) return; // stopping criteria

    // one solution found
    if (currSum == target) {
        ans.push_back(currCombination);
        return;
    }

    // recursive exploration of possible combinations
    for (int i = currIndex; i < uniqueCandidates.size(); i++) {
        currCombination.push_back(uniqueCandidates[i]);
        currSum += uniqueCandidates[i];

        combinationSumHelper(uniqueCandidates, i, currCombination, currSum, target, ans);

        currCombination.pop_back();
        currSum -= uniqueCandidates[i];
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> uniqueCandidates;
    sort(candidates.begin(), candidates.end());

    // create a vector that has no duplicated candidates
    for (int i = 0; i < candidates.size(); i++) {
        if (i == 0 || candidates[i] != candidates[i-1]) {
            uniqueCandidates.push_back(candidates[i]);
        }
    }

    vector<int> currCombination;
    vector<vector<int>> ans;
    int currIndex = 0;
    int currSum = 0;

    combinationSumHelper(uniqueCandidates, currIndex, currCombination, currSum, target, ans);

    return ans;
}

void combinationSumTester() {
    vector<int> candidates = {2, 7, 3, 3, 6};
    combinationSum(candidates, 7);
}