#include <iostream>
#include <vector>

using namespace std;

/*
 * - Problem:
 * Sorted permutation rank
 *
 * - Problem description:
 * Given a string, find the rank of the string amongst its permutations sorted lexicographically.
 * Assume that no characters are repeated.
 */

#define MOD 1000003

void initializeFactorials(int totalLength, vector<int>& fact) {
    long long factorial = 1;

    fact.push_back(1); // 0!

    for (int i = 1; i < totalLength; i++) {
        factorial = (factorial * i) % MOD;
        fact.push_back(factorial);
    }
}

int sortedPermutationRank(string s) {
    int numChars = (int) s.size();

    // count of characters in s
    int charCount[256];
    memset(charCount, 0, sizeof(charCount));
    for (int i = 0; i < numChars; i++) charCount[s[i]]++;

    vector<int> fact; // fact[i] will contain i! % MOD

    initializeFactorials(numChars + 1, fact);

    long long rank = 1;

    for (int i = 0; i < numChars; i++) {
        int less = 0;

        for (int j = 0; j < s[i]; j++) less += charCount[j]; // find the number of characters smaller than s[i]

        rank = (rank + ((long long)fact[numChars - i - 1] * less)) % MOD; // update the rank

        charCount[s[i]]--; // remove the current character from the set
    }

    return (int)rank;
}

void sortedPermutationRankTester() {
    int rank = sortedPermutationRank("view");
}