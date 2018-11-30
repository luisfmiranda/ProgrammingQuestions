#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

/*
 * - Problem:
 * Hotel reviews
 *
 * - Problem description:
 * Given a set of reviews provided by the customers for different hotels and a string containing “Good Words”, you need
 * to sort the reviews in descending order according to their “Goodness Value” (Higher goodness value first). We define
 * the “Goodness Value” of a string as the number of “Good Words” in that string.
 * Note: Sorting should be stable. If review i and review j have the same “Goodness Value” then their original order
 * would be preserved.
 */

// tree node definition
struct TrieNode {
    bool isLeaf;
    TrieNode* children[26];

    TrieNode() {
        isLeaf = true;

        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

// convert '_' to white spaces
void convert(string& str){
    for(int i = 0; i < str.size(); i++)	{
        if(str[i] == '_') str[i] = ' ';
    }
}

// add a node to the trie
void add(TrieNode* trie, string& s) {
    int N = (int)s.size();

    for (int i = 0; i < N; i++) {
        trie->isLeaf = false;

        if (trie->children[s[i] - 'a'] == NULL) {
            trie->children[s[i] - 'a'] = new TrieNode();
            trie = trie->children[s[i] - 'a'];
        }
    }

    return;
}

// search for a node in the trie
bool search(TrieNode* trie, string& s) {
    for (int i = 0; i < s.size(); i++) {
        if (trie->children[s[i] - 'a'] == NULL) return false;
        trie = trie->children[s[i] - 'a'];
    }

    return true;
}

bool compareRatings(const pair<int,int>& r1, const pair<int,int>& r2) {
    if (r1.first == r2.first) return r1.second < r2.second;
    return r1.first > r2.first;
}

vector<int> hotelReviews(string goodWords, vector<string>& reviews) {
    convert(goodWords);

    TrieNode* trie = new TrieNode();

    stringstream ss;
    ss << goodWords;

    string currGoodWord;

    // add the good words to the try
    while (ss >> currGoodWord) {
        add(trie, currGoodWord);
    }

    int numReviews = (int)reviews.size();

    vector<pair<int, int>> ratings(numReviews);

    for (int i = 0; i < numReviews; i++) {
        convert(reviews[i]);

        ss.clear();
        ss << reviews[i];

        int rating = 0;
        string currReviewWord;

        while (ss >> currReviewWord) {
            // search for the current word of the current review in the trie
            if (search(trie, currReviewWord)) rating++;
        }

        ratings[i].first = rating;
        ratings[i].second = i;
    }

    sort(ratings.begin(), ratings.end(), compareRatings);

    vector<int> ans(numReviews);

    for (int i = 0; i < numReviews; i++) {
        ans[i] = ratings[i].second;
    }

    return ans;
}

void hotelReviewsTester() {
    string goodWords = "cool_ice_wifi";
    vector<string> reviews = {"water_is_cool", "cold_ice_drink", "cool_wifi_speed"};

    vector<int> ans = hotelReviews(goodWords, reviews);
}
