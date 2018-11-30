#include <iostream>
#include <vector>

using namespace std;

/*
 * - Problem:
 * Pascal Triangle Rows
 *
 * - Problem description:
 * Given numRows, generate the first numRows of Pascal’s triangle.
 * Pascal’s triangle: To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.
 */

vector<vector<int>> pascalTriangleRows(int n) {
    vector<vector<int>> ans;

    if (n <= 0) return ans;

    vector<int> tmp;
    tmp.push_back(1);
    ans.push_back(tmp);

    for (int i = 0; i < n - 1; i++) {
        vector<int> newRow;
        newRow.push_back(1);

        // go through the row i to form the row i + 1
        for (int j = 0; j < (ans[i].size() - 1); j++) {
            newRow.push_back(ans[i][j] + ans[i][j + 1]);
        }

        newRow.push_back(1);
        ans.push_back(newRow);
    }

    return ans;
}

void pascalTriangleRowsTester() {
    vector<vector<int>> ans = pascalTriangleRows(5);
}
