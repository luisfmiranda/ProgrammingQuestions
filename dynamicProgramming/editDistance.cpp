#include <iostream>
#include <vector>

using namespace std;

/*
 * - Problem:
 * Edit distance
 *
 * - Problem description:
 * Given two words A and B, find the minimum number of steps required to convert A to B (each operation is counted as 1
 * step).
 * You have the following 3 operations permitted on a word:
 *  Insert a character
 *  Delete a character
 *  Replace a character
 */

int editDistance(string word1, string word2) {
    // DP table: i is the position in word1 and j is the position in word2
    vector<vector<int>> distances(word1.size() + 1, vector<int>(word2.size() + 1, 0));

    // when i = 0 or j = 0. the edit distance is the length of the other string
    for (int i = 0; i < distances.size(); i++) {
        for (int j = 0; j < distances[0].size(); j++) {
            if (i == 0) {
                distances[i][j] = j;
            } else if (j == 0) {
                distances[i][j] = i;
            }
        }
    }

    /*
     * If word1[i] == word2[j], then the distance of i and j is the previous i and j.
     * If the characters are not equal, we either replace, insert or delete a char.
     * Inserting a char to word1 means that we are trying to match word1[i - 1] to word2[j].
     * Deleting a char from word1 means that we are trying to match word1[i] to word2[j - 1].
     * Replacing a char in word1 means that we need to add one step to previous i and j.
     */
    for (int i = 1; i < distances.size(); i++) {
        for (int j = 1; j < distances[0].size(); j++) {
            if (word1[i - 1] == word2[j - 1]) {
                distances[i][j] = distances[i - 1][j - 1];
            } else {
                distances[i][j] = 1 + min(distances[i - 1][j - 1], min(distances[i][j - 1], distances[i - 1][j]));
            }
        }
    }

    return distances[word1.size()][word2.size()];
}
