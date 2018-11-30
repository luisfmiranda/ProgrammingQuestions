#include <iostream>

using namespace std;

/*
 * - Problem:
 * Intersecting Chords in a Circle
 *
 * - Problem description:
 * Given a number N, return number of ways you can draw N chords in a circle with 2*N points such that no 2 chords
 * intersect. Two ways are different if there exists a chord which is present in one way and not in other.
 */

#define MOD 1000000007ll

long long dp[1009];

long long intersectingChordsInACircleHelper(int n) {
    if (n == 0) return 1; //stopping criteria

    long long& ret = dp[n];

    if (ret != -1) return ret;

    ret = 0;

    for (int i = 0; i < n; ++i) {
        ret += ((intersectingChordsInACircleHelper(i) * intersectingChordsInACircleHelper(n - i - 1)) % MOD);

        if (ret >= MOD) ret -= MOD;
    }

    return ret;
}

int intersectingChordsInACircle(int n) {
    memset(dp, -1, sizeof(dp));
    return (int)intersectingChordsInACircleHelper(n);
}

void intersectingChordsInACircleTester() {
    int n = 4;
    cout << n << ": " << intersectingChordsInACircle(n);
}
