#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/*
 * - Problem:
 * Word Break
 *
 * - Problem description:
 * Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of
 * one or more dictionary words.
 */

short memoize[100001];

bool wordBreakHelper(int index, string& s, unordered_set<string>& dict) {
    // stop criteria
    if (index >= s.length()) return true;
    if (memoize[index] != -1) return memoize[index];

    bool result = false;

    string substring = "";

    // construct the substrings
    for (int i = index; (i < s.length()) && (result == false); i++) {
        substring.push_back(s[i]);
        if (dict.find(substring) != dict.end()) {
            result |= wordBreakHelper(i + 1, s, dict);
        }
    }

    return memoize[index] = result;
}

int wordBreak(string s, vector<string>& dict) {
    memset(memoize, -1, sizeof(int) * s.length());
    unordered_set<string> dictSet(dict.begin(), dict.end());
    return wordBreakHelper(0, s, dictSet);
}

void wordBreakTester() {
    string s = "myinterviewtrainer";
    vector<string> dict = {"trainer", "my", "interview"};

    cout << wordBreak(s, dict);
}