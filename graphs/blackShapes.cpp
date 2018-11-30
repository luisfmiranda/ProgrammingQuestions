#include <iostream>
#include <queue>

using namespace std;

/*
 * - Problem:
 * Black Shapes
 *
 * - Problem description:
 * Given N * M field of O's and X's, where O = white, X = black. Return the number of black shapes. A black shape
 * consists of one or more adjacent X's (diagonals not included).
 */

//offsets for the directions down, up, left and right
int rowOffsets[] = {1, -1, 0, 0};
int colOffsets[] = {0, 0, -1, 1};

// check if a specific element is inside the field
bool isWithinField(int neighborRow, int neighborCol, int numRows, int numCols) {
    return (neighborCol >= 0) && (neighborRow >= 0) && (neighborRow < numRows) && (neighborCol < numCols);
}

// convert to 'O' all the elements linked with a specific element
void visitShape(vector<string>& field, int currRow, int currCol, int numRows, int numCols) {
    field[currRow][currCol] = 'O';

    // for each direction (down, up, left and right)
    for (int k = 0; k < 4; k++) {
        int neighborRow = currRow + rowOffsets[k];
        int neighborCol = currCol + colOffsets[k];

        if ((isWithinField(neighborRow, neighborCol, numRows, numCols)) && (field[neighborRow][neighborCol] == 'X'))
            visitShape(field, neighborRow, neighborCol, numRows, numCols);
    }
}

int getNumShapes(vector<string>& field) {
    if (field.empty()) return 0;

    int numShapes = 0;
    int numRows = (int)field.size();
    int numCols = (int)field[0].length();

    // for each element in the field
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; ++j) {
            if (field[i][j] == 'X') {
                numShapes++;
                // convert to 'O' all the elements that belong to the current shape
                visitShape(field, i, j, numRows, numCols);
            }
        }
    }

    return numShapes;
}

void getNumShapesTester() {
    vector<string> field1 = {"OOOXOOO", "OOXXOXO", "OXOOOXO"};
    vector<string> field2 = {"XXX", "XXX", "XXX"};
    cout << getNumShapes(field1) << endl;
    cout << getNumShapes(field2) << endl;
}
