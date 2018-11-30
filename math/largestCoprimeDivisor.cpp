#include <iostream>

using namespace std;

/*
 * - Problem:
 * Largest Coprime Divisor
 *
 * - Problem description:
 * You are given two positive numbers A and B. You need to find the maximum valued integer X such that:
 *   X divides A, i.e. A % X = 0
 *   X and B are co-prime, i.e. gcd(X, B) = 1
 */


/*
 * We need to remove the common factors of A and B from A by finding gdc(A, B) and dividing A with that gdc.
 * Thus, we need to divide A by gdc(A, B) until we get gdc(A, B) = 1.
 */
int largestCoprimeDivisor(int A, int B) {
    while(__gcd(A, B) != 1) {
        A = A / __gcd(A, B);
    }

    return A;
}

void largestCoprimeDivisorTester() {
    largestCoprimeDivisor(30, 12);
}
