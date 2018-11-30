#include <iostream>
#include <vector>

using namespace std;

/*
 * - Problem:
 * Max Sum Contiguous Subarray
 *
 * - Problem description:
 * Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 */

int maxSumContiguousSubarray(const vector<int>& A) {
    int maxSumContiguousSubarray = numeric_limits<int>::lowest();
    int sumCurrSubArray = 0;

    for (int currElement : A) {
        sumCurrSubArray += currElement;
        maxSumContiguousSubarray = max(maxSumContiguousSubarray, sumCurrSubArray);
        if (sumCurrSubArray < 0) sumCurrSubArray = 0;
    }

    return maxSumContiguousSubarray;
}

void MaxSumContiguousSubarrayTester() {
    vector<int> A = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSumContiguousSubarray(A);
}
