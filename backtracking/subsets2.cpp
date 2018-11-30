#include <iostream>
#include <vector>

using namespace std;

/*
 * - Problem:
 * Subsets 2
 *
 * - Problem description:
 * Given a collection of integers that might contain duplicates, S, return all possible subsets.
 * Note:
 *   Elements in a subset must be in non-descending order.
 *   The solution set must not contain duplicate subsets.
 *   The subsets must be sorted lexicographically.
 */

void subsets2Helper(vector<int>& S, int index, vector<int>& curr, vector<vector<int>>& ans) {
    // stopping criteria
    if (index >= S.size()) {
        ans.push_back(curr);
        return;
    }

    /*
     * Find the number of occurrences of the element at current index. There will be currIndex - index number of
     * repeating entries.
     */
    int currIndex = index + 1;
    while ((currIndex < S.size()) && (S[currIndex] == S[index])) {
        currIndex++;
    }

    // now we loop over the number of entries to find the subsets
    for (int i = 0; i <= (currIndex - index); i++) {
        for (int j = 0; j < i; j++) {
            curr.push_back(S[index]);
        }

        subsets2Helper(S, currIndex, curr, ans);

        for (int j = 0; j < i; j++) {
            curr.pop_back();
        }
    }
}

vector<vector<int>> subsets2(vector<int>& S) {
    vector<vector<int>> ans;
    vector<int> curr;

    sort(S.begin(), S.end());

    subsets2Helper(S, 0, curr, ans);

    sort(ans.begin(), ans.end());
    return ans;
}

void subsets2Tester() {
    vector<int> S = {1, 2, 2};
    vector<vector<int>> ans = subsets2(S);
}
