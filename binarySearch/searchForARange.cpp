#include <iostream>
#include <vector>

using namespace std;

/*
 * - Problem:
 * Search for a range
 *
 * - Problem description:
 * Given a sorted array of integers, find the starting and ending position of a given target value.
 * If the target is not found in the array, return [-1, -1].
 */

vector<int> searchRange(const vector<int> A, int target) {
    int N = (int) A.size();

    int left = 0;
    int right = N - 1;

    // search for the first element in the range
    while (left < right) {
        int mid = (left + right) / 2;

        if (A[mid] >= target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    vector<int> range(2, -1);

    if (A[left] != target) { // for the case in which the target is not in the array
        return range;
    } else {
        range[0] = left;
    }

    right = N - 1; // it is not necessary to set left to 0 for the second search

    // search for the second element in the range
    while (left < right) {
        int mid = ((left + right) / 2) + 1; // make mid biased to the right, so that the search does not get stuck

        if (A[mid] > target) {
            right = mid - 1;
        } else {
            left = mid;
        }
    }

    range[1] = right;
    return range;
}

void searchRangeTester() {
    vector<int> A = {2, 5, 7, 7, 7, 8, 8, 10, 11, 15, 18, 22, 22, 23, 25};
    searchRange(A, 7);
}