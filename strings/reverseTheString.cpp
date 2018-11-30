#include <iostream>

using namespace std;

/*
 * - Problem:
 * Reverse the string
 *
 * - Problem description:
 * Given an input string, reverse the string word by word.
 */

void reverseString(string& s) {
    string ans = "";
    string curr = "";

    for (int i = (int)s.length() - 1; i >= 0; i--) {
        if (s[i] == ' ') {
            // a way to ignore multiple spaces
            if (curr.empty()) continue;

            reverse(curr.begin(), curr.end());

            // add spaces between solution's words
            if (ans.length() > 0) ans.push_back(' ');

            ans += curr; // update the answer
            curr = "";
        } else {
            curr.push_back(s[i]);
        }
    }

    // takes care of the last word
    if (curr.length() > 0) {
        reverse(curr.begin(), curr.end());
        if (ans.length() > 0) ans.push_back(' ');
        ans += curr;
    }

    s = ans;
    return;
}

void reverseStringTester() {
    string s = "the sky is blue";
    reverseString(s);
}
