#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
 * - Problem:
 * Two sum
 *
 * - Problem description:
 * Given an array of integers, find two numbers such that they add up to a specific target number.
 * The function twoSum should return indices of the two numbers such that they add up to the target, where
 * index1 < index2. Please note that your returned answers (both index1 and index2 ) are not zero-based.
 * Put both these numbers in order in an array and return the array from your function. If multiple solutions exist,
 * output the one where index2 is minimum. If there are multiple solutions with the minimum index2, choose the one with
 * minimum index1 out of them.
 */

vector<int> twoSum(const vector<int>& A, int target) {
    vector<int> ans;

    int N = (int) A.size();
    if (N < 2) return ans;

    unordered_map<int, int> map; // mapping from numbers in the array to their index

    for (int i = 0; i < N; i++) {
        int wanted = target - A[i];

        if (map.find(wanted) != map.end()) {
            ans.push_back(map[wanted] + 1);
            ans.push_back(i + 1);
            break;
        }

        if (map.find(A[i]) == map.end()) map[A[i]] = i;
    }

    return ans;
}

void twoSumTester() {
    vector<int> A = {2, 7, 11, 15, 9, 3, 1};

    twoSum(A, 10);
}
