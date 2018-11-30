#include <iostream>
#include <vector>
#include <deque>

using namespace std;

/*
 * - Problem:
 * Capture regions on the board
 *
 * - Problem description:
 * Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
 * A region is captured by flipping all 'O's into 'X's in that surrounded region.
 */

void bfsBoundary(vector<vector<char>>& board, long i, long j) {
    long M = board.size();
    long N = board[0].size();

    deque<pair<long, long>> q;

    board[i][j] = '-'; // meaning that the element is "safe"
    q.push_back(make_pair(i, j));

    while (!q.empty()) {
        pair<long, long> curr = q.front();
        q.pop_front();

        // neighbors of the current element
        pair<long, long> adjs[4] = {
                {curr.first - 1, curr.second},
                {curr.first, curr.second + 1},
                {curr.first + 1, curr.second},
                {curr.first, curr.second - 1}
        };

        // for each neighbor
        for (pair<long, long> neighbor : adjs) {
            long iNeighbor = neighbor.first;
            long jNeighbor = neighbor.second;

            // check if the neighbor is in a valid position
            if (!((iNeighbor >= 0) && (iNeighbor < M) && (jNeighbor >= 0) && (jNeighbor < N))) continue;

            // if it is, check if it is a circle and, in positive case, mark it as "safe"
            if (board[iNeighbor][jNeighbor] == 'O') {
                q.push_back(neighbor);
                board[iNeighbor][jNeighbor] = '-';
            }
        }
    }
}

void captureRegions(vector<vector<char>>& board) {
    long M = board.size();
    if (M == 0) return;
    long N = board[0].size();
    if (N == 0) return;

    // check which circles are "connected" with the side borders of the board
    for (long i = 0; i < M; i++) {
        if (board[i][0] == 'O') bfsBoundary(board, i, 0);
        if (board[i][N - 1] == 'O') bfsBoundary(board, i, N - 1);
    }

    // the same as above, but not with the top and bottom of the board
    for (long i = 1; i < N - 1; i++) {
        if (board[0][i] == 'O') bfsBoundary(board, 0, i);
        if (board[M - 1][i] == 'O') bfsBoundary(board, M - 1, i);
    }

    // capture "elements that were not saved"
    for (long i = 0; i < M; i++) {
        for (long j = 0; j < N; j++) {
            if (board[i][j] == 'O') board[i][j] = 'X';
            if (board[i][j] == '-') board[i][j] = 'O';
        }
    }
}

void captureRegionsTester() {
    vector<vector<char>> board = {
            {'X', 'O', 'X', 'X', 'X', 'X', 'O', 'O', 'X', 'X'},
            {'X', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'X', 'X'},
            {'O', 'X', 'X', 'O', 'O', 'X', 'X', 'X', ')', 'O'},
    };

    captureRegions(board);
}
