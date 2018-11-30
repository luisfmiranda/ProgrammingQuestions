#include <iostream>
#include <vector>

using namespace std;

/*
 * - Problem:
 * Tushar's Birthday Bombs
 *
 * - Problem description:
 * It’s Tushar’s birthday today and he has N friends. Friends are numbered [0, 1, 2, …, N-1] and i-th friend have a
 * positive strength S(i). Today being his birthday, his friends have planned to give him birthday bombs (kicks).
 * Tushar’s friends know Tushar’s pain bearing limit and would hit accordingly. If Tushar’s resistance is denoted by
 * R (>=0) then find the lexicographically smallest order of friends to kick Tushar so that the cumulative kick strength
 * (sum of the strengths of friends who kicks) doesn’t exceed his resistance capacity and total no. of kicks hit are
 * maximum. Also note that each friend can kick unlimited number of times (ff a friend hits x times, his strength will
 * be counted x times).
 * Notes:
 * 1. Answer format = Vector of indexes of friends in the order in which they will hit.
 * 2. Answer should have the maximum no. of kicks that can be possibly hit. If two answer have the same no. of kicks,
 * return one with the lexicographically smaller.
 * 3. Input cases are such that the length of the answer does not exceed 100000.
 */

vector<int> tusharsBirthdayBombs(int A, vector<int>& B){
    // updatedB will keep the set of friends that could be at the final answer and their index at the original vector
    vector<pair<int, int>> candidates;

    /*
     * Go through the list of friends and every time a friend sets a new low level of strength, add it to a vector.
     * The result is a vector in decresing order, representing the friends that can be part of the answer.
     */
    int highestStrength = numeric_limits<int>::max();
    for (int i = 0; i < B.size(); i++) {
        if (B[i] < highestStrength) {
            candidates.push_back({i, B[i]});
            highestStrength = B[i];
        }
    }

    int numCandidates = (int) candidates.size();
    int smaStrength = candidates[numCandidates - 1].second;
    int remainingRes = A;
    vector<int> ans;

    int i = 0;
    while (i < numCandidates) {
        bool canHit = remainingRes >= candidates[i].second; // check if the current friend can hit

        // check if adding the current friend would keep the answer's size
        bool keepAnswerSize = ((remainingRes - candidates[i].second) / smaStrength + 1) == (remainingRes/smaStrength);

        if (canHit && keepAnswerSize) {
            ans.push_back(candidates[i].first);
            remainingRes -= candidates[i].second;
        } else {
            i++;
        }
    }

    return ans;
}

void tusharsBirthdayBombsTester() {
    vector<int> B = {6, 8, 5, 4, 7};
    tusharsBirthdayBombs(11, B);
}
