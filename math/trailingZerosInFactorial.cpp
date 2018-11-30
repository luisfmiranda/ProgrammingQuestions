#include <iostream>

using namespace std;

/*
 * - Problem:
 * Trailing Zeros in Factorial
 *
 * - Problem description:
 * Given an integer n, return the number of trailing zeroes in n!.
 */

int trailingZerosInFactorial(int n) {
    int sum = 0;

    while ((n / 5) > 0) {
        sum += (n / 5);
        n /= 5;
    }

    return sum;
}
