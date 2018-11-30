#include <iostream>
#include <vector>

using namespace std;

/*
 * - Problem:
 * Word Search Board
 *
 * - Problem description:
 * Given a 2D board and a word, find if the word exists in the grid.
 * The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally
 * or vertically neighboring. The cell itself does not count as an adjacent cell. The same letter cell may be used more
 * than once.
 */

bool atLeastOneNeighborIsTrue(vector<vector<bool>>& doesExist, int i, int j) {
    int M = (int) doesExist.size();
    int N = (int) doesExist[0].size();

    if (i > 0 && doesExist[i - 1][j] == true) return true;
    if (j > 0 && doesExist[i][j - 1] == true) return true;
    if (i < (M - 1) && doesExist[i + 1][j] == true) return true;
    if (j < (N - 1) && doesExist[i][j + 1] == true) return true;

    return false;
}

bool wordSearchBoard(vector<string>& board, string word) {
    if (word.size() == 0) return true;

    int M = (int) board.size();
    if (M == 0) return false;
    int N = (int) board[0].size();
    if (N == 0) return false;

    vector<vector<bool>> isAMatch[2]; // see description bellow

    // initial filling of the auxiliary boards
    for (int i = 0; i < M; i++) {
        vector<bool> aux1(N, false);
        vector<bool> aux2(N, false);

        isAMatch[0].push_back(aux1);
        isAMatch[1].push_back(aux2);
    }

    int currAuxBoardId = 0;

    /*
     * About the use of auxiliary boards: for each letter in the word, there will be a loop through all the elements in
     * the board. During each iteration of the outer loop (which loop through the letter of the word) one board will be
     * used to keep information about matches in the current iteration and the other will be used to keep information
     * about matches gathered on the previous iteration.
     */
    for (int indexCurrLetter = 0; indexCurrLetter < word.size(); indexCurrLetter++) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                // the current letter matches the current element of the board
                bool lettersMatch = (word[indexCurrLetter] == board[i][j]);

                // if we are in the first letter of the word, we do not need to search for matches in previos iterations
                if (indexCurrLetter == 0) {
                    isAMatch[currAuxBoardId][i][j] = lettersMatch;
                /*
                 * If a match happend on the second letter onwards, then we also need to check if one of the neighbors
                 * was a match for the substring word[0 : indexCurrLetter - 1].
                 */
                } else {
                    bool atLeastOneNeighborIsAMatch = atLeastOneNeighborIsTrue(isAMatch[1 - currAuxBoardId], i, j);
                    isAMatch[currAuxBoardId][i][j] = (lettersMatch && atLeastOneNeighborIsAMatch);
                }
            }
        }

        // toggle roles for the auxiliary boards
        if (indexCurrLetter < word.size() - 1) currAuxBoardId = 1 - currAuxBoardId;
    }

    // at this point, if there is at least one element holding a value true, then there is a way to match the word
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (isAMatch[currAuxBoardId][i][j]) return true;
        }
    }

    return false;
}

void wordSearchBoardTester() {
    vector<string> board = {"ABCA", "SFCS", "ABCE"};
    wordSearchBoard(board, "ABCE");
}
