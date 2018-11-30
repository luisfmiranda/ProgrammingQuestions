#include <string>
#include <vector>

using namespace std;

/*
 * - Problem:
 * Binary String with Question Marks
 *
 * - Problem description:
 * Given a string pattern of 0s, 1s, and ?s, generate all 0-1 strings that match this pattern.
 */

void permuteStringHelper(vector<string>& ans, const string& s, const string& prefix, int index) {
    // true when a new string permutation was completed
    if (index == s.length()) {
        ans.push_back(prefix);
        return;
    }

    if (s[index] == '?') {
        permuteStringHelper(ans, s, prefix + "0", index + 1);
        permuteStringHelper(ans, s, prefix + "1", index + 1);
    } else {
        permuteStringHelper(ans, s, prefix + s[index], index + 1);
    }
}

vector<string> permuteString(const string& s) {
    vector<string> ans;

    if (s.empty()) return ans;

    // check if the string is invalid
    for (char ch : s) {
        if (ch != '0' && ch != '1' && ch != '?') return ans;
    }

    permuteStringHelper(ans, s, "", 0);
    return ans;
}

void permuteStringTester() {
    vector<string> ans = permuteString("011?01?00");
}
