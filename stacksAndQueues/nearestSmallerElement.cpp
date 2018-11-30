#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
 * - Problem:
 * Nearest Smaller Element
 *
 * - Problem description:
 * Given an array, find the nearest smaller element G[i] for every element A[i] in the array such that the element has
 * an index smaller than i.
 */

vector<int> nearestSmallerElement(vector<int> A) {
    vector<int> ans;
    stack<int> s;

    for (int i = 0; i < A.size(); i++) {
        /*
         * Every element in the stack which is equal or bigger than the current element is useless now, so we will
         * remove them.
         */
        while (!s.empty() && s.top() >= A[i]) {
            s.pop();
        }

        // if the stack is not empty, then the top elmenet is the value we are looking for
        if (!s.empty()) {
            ans.push_back(s.top());
        // if no element is smaller than the current element, then there is no previous smallest element
        } else {
            ans.push_back(-1);
        }

        s.push(A[i]);
    }

    return ans;
}

void nearestSmallerElementTester() {
    vector<int> A = {4, 5, 2, 10};
    nearestSmallerElement(A);
}
