#include <iostream>
#include <vector>

using namespace std;

/*
 * - Problem:
 * Sum of pairwise Hamming Distance
 *
 * - Problem description:
 * Hamming distance between two non-negative integers is defined as the number of positions at which the corresponding
 * bits are different.
 */

#define MOD 1000000007

int sumOfPairwiseHammingDistance(const vector<int> &A) {
    int N = (int)A.size();
    int sum = 0;

    // for every bit position
    for (int i = 0; i < 31; i++) {
        int bitsZeroCounter = 0;
        int bitsOneCounter = 0;

        // for every element
        for (int j = 0; j < N; j++) {
            // check if the current bit of the current element is zero or one
            if (A[j] & (1 << i)) {
                bitsOneCounter++;
            } else {
                bitsZeroCounter++;
            }
        }

        sum = (int)((sum + (2LL * bitsZeroCounter * bitsOneCounter) % MOD) % MOD);
    }

    return sum;
}

void sumOfPairwiseHammingDistanceTester() {
    vector<int> A = {2, 4, 6};
    cout << sumOfPairwiseHammingDistance(A);
}
