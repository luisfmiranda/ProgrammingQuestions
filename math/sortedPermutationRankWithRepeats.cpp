#include <iostream>
#include <vector>

using namespace std;

/*
 * - Problem:
 * Sorted Permutation Rank with Repeats
 *
 * - Problem description:
 * Given a string, find the rank of the string amongst its permutations sorted lexicographically.
 * Note that the characters might be repeated.
 * If the characters are repeated, we need to look at the rank in unique permutations.
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

long long getMDI(int num) {
    long long mdi = 1;
    long long base = (long long)num;
    int power = MOD - 2;

    while (power > 0) {
        if (power == 1) return (mdi * base) % MOD;

        if ((power % 2) == 0) {
            base = (base * base) % MOD;
            power /= 2;
        } else {
            mdi = (mdi * base) % MOD;
            power--;
        }
    }

    return mdi;
}

int sortedPermutationRankWithRepeats(string s) {
    int numChars = (int) s.size();

    // count of characters in s
    int charCount[256];
    memset(charCount, 0, sizeof(charCount));
    for (int i = 0; i < numChars; i++) charCount[s[i]]++;

    vector<int> fact; // fact[i] will contain i! % MOD

    initializeFactorials(numChars + 1, fact);

    long long rank = 1;

    for (int i = 0; i < numChars; i++) {
        long long less = 0;
        int remaining = numChars - i - 1;

        for (int j = 0; j < s[i]; j++) {
            if (charCount[j] == 0) continue;

            charCount[j]--;
            long long numPermutations = fact[remaining];

            for (int c = 0; c < 128; c++) {
                if (charCount[c] <= 1) continue;
                numPermutations = (numPermutations * getMDI(fact[charCount[c]])) % MOD;
            }

            charCount[j]++;
            less = (less + numPermutations) % MOD;
        }

        rank = (rank + less) % MOD; // update the rank

        charCount[s[i]]--; // remove the current character from the set
    }

    return (int)rank;
}

void sortedPermutationRankWithRepeatsTester() {
    sortedPermutationRankWithRepeats("that");
}
