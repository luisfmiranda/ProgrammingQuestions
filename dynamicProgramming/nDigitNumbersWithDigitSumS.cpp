#include <iostream>
#include <vector>

using namespace std;

/*
 * - Problem:
 * N digit numbers with digit sum S
 *
 * - Problem description:
 * Find out the number of N digit numbers, whose digits on being added equals to a given number S. Note that a valid
 * number starts from digits 1-9 except the number 0 itself.
 * Since the answer can be large, output answer modulo 1000000007
 */

#define MOD 1000000007

int helper(vector<vector<int>>& dp, int digitsLeft, int maxSum) {
    // stopping criteria
    if (maxSum < 0) return 0;
    if (digitsLeft == 0 && maxSum == 0) return 1; // solution found
    if (digitsLeft == 0) return 0;

    if (dp[digitsLeft][maxSum] != -1) return dp[digitsLeft][maxSum]; // memoization

    int ans = 0;

    // for each digit
    for (int i = 0; i < 10; i++) {
        ans = ((ans + helper(dp, digitsLeft - 1, maxSum - i)) % MOD);
    }

    dp[digitsLeft][maxSum] = ans;
    return ans;
}

int nDigitNumbersWithDigitSumS(int N, int S) {
    int ans = 0;
    vector<vector<int>> dp(N + 1, vector<int>(S + 1, -1));

    // for each digit (excluding leading zeros)
    for (int i = 1; i < 10; i++) {
        ans = ((ans + helper(dp, N - 1, S - i)) % MOD);
    }

    return ans;
}

void nDigitNumbersWithDigitSumSTester() {
    cout << nDigitNumbersWithDigitSumS(2, 4);
}
