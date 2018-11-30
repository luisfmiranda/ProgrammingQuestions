#include <iostream>

using namespace std;

/*
 * - Problem:
 * Add Binary Strings
 *
 * - Problem description:
 * Given two binary strings, return their sum (also a binary string).
 */

string addBinaryStrings(string A, string B) {
    string ans = "";

    int carry = 0;

    // "pointers" to the end of the numbers
    int p = (int) A.size() - 1;
    int q = (int) B.size() - 1;

    // go from right to left, summing the digits and the carry
    while (p >= 0 || q >= 0 || carry) {
        int sum = carry;

        if (p >= 0) sum += (A[p] - '0');
        if (q >= 0) sum += (B[q] - '0');

        ans.push_back((char)('0' + (sum % 2)));
        carry = (sum / 2);

        p--;
        q--;
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

void addBinaryStringsTester() {
    string A = "100";
    string B = "11";
    addBinaryStrings(A, B);
}
