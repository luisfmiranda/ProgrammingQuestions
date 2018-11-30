#include <iostream>
#include <vector>

using namespace std;

/*
 * - Problem:
 * Bulbs
 *
 * - Problem description:
 * N light bulbs are connected by a wire. Each bulb has a switch associated with it. However, due to faulty wiring, a
 * switch also changes the state of all the bulbs to the right of current bulb. Given an initial state of all bulbs,
 * find the minimum number of switches you have to press to turn on all the bulbs. You can press the same switch
 * multiple times.
 * Note: 0 represents the bulb is off and 1 represents the bulb is on.
 */

int bulbs(vector<int>& A) {
    int ans = 0;
    int state = 0;

    // for each bulb
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == state) {
            ans++;
            state = 1 - state;
        }
    }

    return ans;
}

void bulbsTester() {
    vector<int> A = {0, 1, 0, 1};
    cout << bulbs(A);
}
