#include <iostream>
#include <vector>

using namespace std;

/*
 * - Problem:
 * First missing integer
 *
 * - Problem description:
 * Given an unsorted integer array, find the first missing positive integer.
 */

int firstMissingInteger(vector<int>& A) {
    int N = (int) A.size();

    /*
     * We traverse the array and, if A[i] is in [1 : N] range, we swap it with the element with index equals to A[i].
     * The loop does not "advances an iteration" in these cases.
     */
    for (int i = 0; i < N; ++i) {
        if (A[i] > 0 && A[i] <= N) {
            int indexOnBucket = A[i] - 1;

            if (A[i] != A[indexOnBucket]) { // this guarantees that the loop will finish
                swap(A[i], A[indexOnBucket]);
                i--;
            }
        }
    }

    // now we only have to check if there is an element whose value is different from its index
    for (int i = 0; i < N; ++i) {
        if (A[i] != (i + 1)) return (i + 1);
    }

    // the answer will be N + 1 only if all elements of the array are exact one occurrence of [1 : N]
    return (N + 1);
}

void firstMissingIntegerTester() {
    vector<int> A = {3, 4, -1, 1, 2, 12, 6};
    firstMissingInteger(A);
}
