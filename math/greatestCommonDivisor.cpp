#include <iostream>

using namespace std;

/*
 * - Problem:
 * Greatest Common Divisor.
 *
 * - Problem description:
 * Given 2 non-negative integers m and n, find gcd(m, n).
 * Both m and n fit in a 32 bit signed integer.
 */

int greatestCommonDivisor(int m, int n) {
    if (n > m) swap(m,n);
    if (n == 0) return m;

    return greatestCommonDivisor(m % n, n);
}

void greatestCommonDivisorTester() {
    cout << greatestCommonDivisor(18, 45);
}
