#include <iostream>
#include <vector>

using namespace std;

/*
 * - Problem:
 * Length of Longest Subsequence
 *
 * - Problem description:
 * Given an array of integers, find the length of longest subsequence which is first increasing then decreasing.
 */

int lengthOfLongestSubsequence(const vector<int>& A) {
    int N = (int)A.size();
    int inc[N];
    int dec[N];

    inc[0] = 1;

    // construct an array to stores the longest increasing subsequence ending with A[i].
    for (int i = 0; i < N; i++) {
        inc[i] = 1;

        for (int j = i; j >= 0; j--) {
            if (A[i] > A[j] && inc[i] < (inc[j] + 1)) inc[i] = inc[j] + 1;
        }
    }
    
    dec[N - 1] = 1;

    // construct an array to stores the longest decreasing subsequence ending with A[i].
    for (int i = N - 2; i >= 0; i--) {
        dec[i] = 1;

        for (int j = i + 1; j < N; j++) {
            if (A[i] > A[j] && dec[i] < dec[j] + 1) dec[i] = dec[j] + 1;
        }
    }

    int longestSequence = 0;

    // for each element, the maximum value of (inc[i] + dec[i] - 1) will be the answer until that element
    for (int i = 0; i < N; i++) {
        longestSequence = max(longestSequence, inc[i] + dec[i] - 1);
    }

    return longestSequence;
}

void lengthOfLongestSubsequenceTester() {
    vector<int> A = {1, 11, 2, 10, 4, 5, 2, 1};

    cout << lengthOfLongestSubsequence(A);
}
