# - Problem:
# Max Non Negative SubArray

# - Problem description:
# Find out the maximum subarray of non negative numbers from an array. The subarray should be continuous. That is, a
# subarray created by choosing the second and fourth element and skipping the third element is invalid. Maximum subarray
# is defined in terms of the sum of the elements in the subarray. Subarray A is greater than subarray B if sum(A) >
# sum(B).
# Note: If there is a tie, then compare with segment's length and return segment which has maximum length.


def max_set(A):
    sum_curr = 0
    curr = []

    sum_biggest = 0
    biggest = []

    for currElem in A:
        if currElem >= 0:
            # expands current subarray
            sum_curr += currElem
            curr.append(currElem)

            # newer non-negative biggest subarray found
            if sum_curr > sum_biggest or (sum_curr == sum_biggest and len(curr) > len(biggest)):
                sum_biggest = sum_curr
                biggest = curr
        else:
            # clears current subarray
            sum_curr = 0
            curr = []

    return biggest

print(max_set([1, 2, 5, -7, 2, 3]))

