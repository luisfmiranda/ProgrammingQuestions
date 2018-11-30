#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
 * - Problem:
 * Equal
 *
 * - Problem description:
 * Given an array A of integers, find the index of values that satisfy A + B = C + D, where A,B,C & D are integers
 * values in the array.
 */

vector<int> equal(vector<int> A) {
    int N = (int)A.size();

    // for every sum, we store the lexicographically first ocurring pair of integers
    unordered_map<int, pair<int, int>> map;

    vector<int> globalAns;

    // for each pair in N
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int sum = A[i] + A[j];

            if (map.find(sum) == map.end()) {
                map[sum] = make_pair(i, j);
                continue;
            }

            pair<int, int> pair1 = map[sum];

            // to be sure that we are not using an element twice
            if (pair1.first != i && pair1.first != j && pair1.second != i && pair1.second != j) {
                /*
                 * At this point we know that we have a solution. Now it is necessary to check if that solution is the
                 * lexicographically smaller one.
                 */
                vector<int> localAns;
                localAns.push_back(pair1.first);
                localAns.push_back(pair1.second);
                localAns.push_back(i);
                localAns.push_back(j);

                if (globalAns.size() == 0) {
                    globalAns = localAns;
                } else {
                    bool shouldReplace = false;

                    for (int k = 0; k < globalAns.size(); k++) {
                        if (globalAns[k] < localAns[k]) break;
                        if (globalAns[k] > localAns[k]) {
                            shouldReplace = true;
                            break;
                        }
                    }

                    if (shouldReplace) globalAns = localAns;
                }
            }
        }
    }

    return globalAns;
}

void equalTester() {
    vector<int> A = {3, 4, 7, 1, 2, 9, 8};
    vector<int> localAns = equal(A);
}
