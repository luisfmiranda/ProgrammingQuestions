#include <iostream>
#include <vector>

using namespace std;

/*
 * - Problem:
 * Remove Duplicates from Sorted Array 2
 *
 * - Problem description:
 * Given a sorted array, remove the duplicates in place such that each element can appear atmost twice and return the
 * new length. Do not allocate extra space for another array, you must do this in place with constant memory.
 */

int removeDuplicatesFromSortedArray2(vector<int> A) {
    int count = 0;
    int N = (int)A.size();

    for (int i = 0; i < N; i++) {
        // if both A[i + 1] and A[i + 2] elements are the same than A[i]
        if ((i < (N - 2)) && (A[i] == A[i + 1]) && (A[i] == A[i + 2])) continue;

        A[count] = A[i];
        count++;
    }

    return count;
}

void removeDuplicatesFromSortedArray2Tester() {
    vector<int> A = {1, 1, 1, 2};
    cout << removeDuplicatesFromSortedArray2(A);
}