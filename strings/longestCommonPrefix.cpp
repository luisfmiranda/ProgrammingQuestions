#include <iostream>
#include <vector>

using namespace std;

/*
 * - Problem:
 * Longest Common Prefix.
 *
 * - Problem description:
 * Write a function to find the longest common prefix string amongst an array of strings.
 * Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1 and S2.
 * Given the array of strings, you need to find the longest S which is the prefix of ALL the strings in the array.
 */

unsigned long getSizeSmallestString(const vector<string>& strings) {
    unsigned long szSmallestString = numeric_limits<unsigned long>::max();

    for (const string& s : strings) {
        if (s.length() < szSmallestString)
            szSmallestString = s.length();
    }

    return szSmallestString;
}

string longestCommonPrefix(const vector<string>& strings) {
    int numStrings = (int)strings.size();
    int sizeSmallestString = (int)getSizeSmallestString(strings);
    string longestCommonPrefix;

    // for each character in the smallest string
    for (int i = 0; i < sizeSmallestString; i++) {
        char reference = strings[0][i]; // take the ith character of the first string as a reference for this iteration

        // compare the reference against the other strings
        for (int j = 1; j < numStrings; j++) {
            if (strings[j][i] != reference)
                return longestCommonPrefix;
        }

        // update the common prefix
        longestCommonPrefix.push_back(reference);
    }

    // the smallest string is a prefix of all the other strings
    return longestCommonPrefix;
}

void longestCommonPrefixTester() {
    vector<string> strings = {"city", "citizenship", "citizen"};
    cout << longestCommonPrefix(strings);
}
