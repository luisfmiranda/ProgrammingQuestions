#include <iostream>
#include <vector>

using namespace std;

/*
 * - Problem:
 * Kth Permutation Sequence
 *
 * - Problem description:
 * The set [1,2,3,…,n] contains a total of n! unique permutations.
 * By listing and labeling all of the permutations in order, we get the following sequence (ie, for n = 3 ):
 * 1. "123"
 * 2. "132"
 * 3. "213"
 * 4. "231"
 * 5. "312"
 * 6. "321"
 * Given n and k, return the kth permutation sequence.
 */

int computeFactorial(int n) {
    if (n > 12) return INT_MAX;

    int fact = 1;
    for (int i = 2; i <= n; i++)
        fact *= i;

    return fact;
}

string getPermutation(int k, vector<int> &candidateSet) {
    int n = candidateSet.size();

    if (n == 0) return ""; // stopping criterion
    if (k > computeFactorial(n)) return ""; // invalid condition

    // number of existing permutations after selecting the current candidate
    int numPermAfterSelection = computeFactorial(n - 1);

    // 0 based position of the candidate that should be selected in this step
    int posRightCandidate = k / numPermAfterSelection;

    k %= numPermAfterSelection;

    string selectedCandidate = to_string(candidateSet[posRightCandidate]);

    // remove the selected candidate from the candidate set
    candidateSet.erase(candidateSet.begin() + posRightCandidate);

    return selectedCandidate + getPermutation(k, candidateSet);
}

string kthPermutationSequence(int n, int k) {
    vector<int> candidateSet;

    for (int i = 1; i <= n; i++)
        candidateSet.push_back(i);

    return getPermutation(k - 1, candidateSet);
}

void kthPermutationSequenceTester() {
    cout << kthPermutationSequence(3, 4);
}
