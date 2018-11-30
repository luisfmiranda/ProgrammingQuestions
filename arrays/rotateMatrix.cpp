#include <iostream>
#include <vector>

using namespace std;

/*
 * - Problem:
 * Rotate matrix
 *
 * - Problem description:
 * You are given an n x n 2D matrix representing an image.
 * Rotate the image by 90 degrees (clockwise).
 */

void rotateMatrix(vector<vector<int>>& M) {
    int N = (int)M.size();

    // border to center
    for (int i = 0; i < N / 2; i++) {
        // j in this case acts like an offset
        for (int j = i; j < N - i - 1; j++) {
            //rotate the elements
            int tmp = M[i][j];
            M[i][j] = M[N - j - 1][i];
            M[N - j - 1][i] = M[N - i - 1][N - j - 1];
            M[N - i - 1][N - j - 1] = M[j][N - i - 1];
            M[j][N - i - 1] = tmp;
        }
    }
}
