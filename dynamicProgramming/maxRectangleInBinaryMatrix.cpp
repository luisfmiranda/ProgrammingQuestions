#include <iostream>
#include <vector>

using namespace std;

/*
 * - Problem:
 * Max Rectangle in Binary Matrix
 *
 * - Problem description:
 * Given a 2D binary matrix filled with 0’s and 1’s, find the largest rectangle containing all ones and return its area.
 */

int maxRectangleInBinaryMatrix(vector<vector<int>>& M) {
    int nRows = (int)M.size();
    if (nRows == 0) return 0;
    int nCols = (int)M[0].size();
    if (nCols == 0) return 0;

    // number of consecutive 1s on the left of M[i][j], including the elementM[i][j]
    vector<vector<int>> rowMax(nRows, vector<int>(nCols, 0));

    int area = 0;

    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            if (M[i][j] == 1) {
                // check how many 1s exist on the left of M[i][j]
                if (j == 0) {
                    rowMax[i][j] = 1;
                } else {
                    rowMax[i][j] = rowMax[i][j - 1] + 1;
                }

                int x = nCols;
                int y = 1;

                // check if a bigger area can be created
                while ((i - y + 1 >= 0) && (M[i - y + 1][j] == 1)) {
                    x = min(x, rowMax[i - y + 1][j]);
                    area = max(area, x * y);
                    y++;
                }
            }
        }
    }

    return area;
}

void maxRectangleInBinaryMatrixTester() {
    vector<vector<int>> M = {{1, 1, 1}, {0, 1, 1}, {1, 0, 0}};
    cout << maxRectangleInBinaryMatrix(M);
}
