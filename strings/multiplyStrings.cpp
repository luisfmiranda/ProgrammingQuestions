#include <iostream>
#include <vector>

using namespace std;

/*
 * - Problem:
 * List cycle
 *
 * - Problem description:
 * Given two numbers represented as strings, return multiplication of the numbers as a string.
 * Notes:
 * 1- The numbers can be arbitrarily large and are non-negative.
 * 2- The answer should not have leading zeroes. For example, 00 is not a valid answer.
 */

string multiplyStrings(string& num1, string& num2) {
    int N1 = (int) num1.size();
    int N2 = (int) num2.size();

    if (N1 == 0 || N2 == 0) return "";

    vector<int> result(N1 + N2, 0); // keep the result in reversed order

    int indexNum1 = 0;

    // go from right to left along the first number
    for (int i = N1 - 1; i >= 0; i--) {
        int currDigitNum1 = num1[i] - '0';
        int carrier = 0;

        int indexNum2 = 0;

        // go from right to left along the second number
        for (int j = N2 - 1; j >= 0; j--) {
            int currDigitNum2 = num2[j] - '0';

            int sum = currDigitNum1 * currDigitNum2 + result[indexNum1 + indexNum2] + carrier;
            carrier = sum / 10;
            result[indexNum1 + indexNum2] = sum % 10;

            indexNum2++;
        }

        // store carrier in the next cell
        if (carrier > 0) result[indexNum1 + indexNum2] += carrier;

        indexNum1++;
    }

    // ignore trailing 0's
    int indexAns = (int) result.size() - 1;
    while (indexAns > 0 && result[indexAns] == 0) {
        indexAns--;
    }

    // if all digits were 0, it means at least on the numbers was 0
    if (indexAns == -1) return "0";

    // generate the result
    string ans = "";
    while (indexAns >= 0) {
        ans += to_string(result[indexAns]);
        indexAns--;
    }

    return ans;
}

void multiplyStringsTester() {
    string sA = "12";
    string sB = "10";
    cout << multiplyStrings(sA, sB);
}