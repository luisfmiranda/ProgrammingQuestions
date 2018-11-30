#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*
 * - Problem:
 * All Factors.
 *
 * - Problem description:
 * Given a number N, find all factors of N.
 */

vector<int> allFactors(int n) {
    vector<int> factors;

    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            factors.push_back(i);

            // the conditional is necessary in order to avoid duplicate the value sqrt(n)
            if ((n / i) != i) factors.push_back(n / i);
        }
    }

    sort(factors.begin(), factors.end());

    return factors;
}

void allFactorsTester() {
    vector<int> factors = allFactors(6);

    for (int n : factors) {
        cout << n << " ";
    }
}
