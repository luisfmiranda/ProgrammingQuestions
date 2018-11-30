#include <iostream>
#include <unordered_set>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

/*
 * - Problem:
 * Word Ladder
 *
 * - Problem description:
 * Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to
 * end, such that:
 *   . You must change exactly one character in every transformation
 *   . Each intermediate word must exist in the dictionary
 */

int wordLadder(string start, string end, vector<string>& dict) {
    unordered_set<string> wordsSet(dict.begin(), dict.end());
    unordered_map<string, int> dist; // distance from the start to the current word
    queue<string> q; // for the BFS algorithm

    dist[start] = 1;
    q.push(start);

    while(!q.empty()) {
        string currWord = q.front();
        q.pop();

        if (currWord == end) break; // solution found

        // generate all possible transformations
        for (int i = 0; i < start.length(); i++) {
            for (int j = 0; j < 26; j++) {
                string newWord = currWord;
                newWord[i] = 'a' + j;

                // check if the tranformated word is present in the words set
                if ((wordsSet.find(newWord) != wordsSet.end()) && (dist.find(newWord) == dist.end())) {
                    dist[newWord] = dist[currWord] + 1;
                    q.push(newWord);
                }
            }
        }
    }

    if (dist.find(end) == dist.end()) return 0; // not found
    return dist[end];
}

void wordLadderTester() {
    string start = "hit";
    string end = "cog";
    vector<string> dict = {"hot", "dot", "dog", "lot", "log", "cog"};
    cout << wordLadder(start, end, dict);
}
