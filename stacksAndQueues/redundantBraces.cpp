#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/*
 * - Problem:
 * Redundant Braces
 *
 * - Problem description:
 * Write a program to validate if the input string has redundant braces.
 */

int redundantBraces(string exp) {
    int count = 0; // acts as a stack
    vector<char> ops = {'+', '-', '*', '/'};

    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == '(') {
            count++; // push
        } else if (find(ops.begin(), ops.end(), exp[i]) != ops.end()) {
            if (count != 0) count--; // pop
        }
    }

    // if our "stack" is empty all opening braces were matched by an operator, thus there is no redudant braces
    if (count == 0) return 0;
    return 1;
}

void redundantBracesTester() {
    string s = "(a*b)+(b*c)";
    cout << redundantBraces(s);
}
