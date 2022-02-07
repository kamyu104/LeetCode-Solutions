// Time:  O(b^(d/2)), b is the branch factor of bfs, d is the result depth
// Space: O(w * l), w is the number of words, l is the max length of words

// two-end bfs
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(cbegin(wordList), cend(wordList));
        if (!words.count(endWord)) {
            return 0;
        }
        int ladder = 2;
        unordered_set<string> left = {beginWord}, right = {endWord};
        while (!empty(left)) {
            for (const auto& word : left) {
                words.erase(word);
            }
            unordered_set<string> new_left;
            for (const auto& word : left) {
                auto new_word = word;
                for (int i = 0; i < size(new_word); ++i) {
                    char prev = new_word[i];
                    for (int j = 0; j < 26; ++j) {
                        new_word[i] = 'a' + j;
                        if (!words.count(new_word)) {
                            continue;
                        }
                        if (right.count(new_word)) {
                            return ladder;
                        }
                        new_left.emplace(new_word);
                    }
                    new_word[i] = prev;
                }
            }
            left = move(new_left);
            ++ladder;
            if (size(left) > size(right)) {
                swap(left, right);
            }
        }
        return 0;
    }
};

// Time:  O(b^d), b is the branch factor of bfs, d is the result depth
// Space: O(w * l), w is the number of words, l is the max length of words
class Solution2 {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> lookup(cbegin(wordList), cend(wordList));
        if (!lookup.count(endWord)) {
            return 0;
        }
        int ladder = 2;
        for (vector<string> q = {beginWord}; !q.empty(); ++ladder) {
            vector<string> new_q;
            for (const auto& word : q) {
                auto new_word = word;
                for (int i = 0; i < new_word.length(); ++i) {
                    char prev = new_word[i];
                    for (int j = 0; j < 26; ++j) {
                        new_word[i] = 'a' + j;
                        if (new_word == endWord) {
                            return ladder;
                        }
                        if (lookup.count(new_word)) {
                            lookup.erase(new_word);
                            new_q.emplace_back(new_word);
                        }
                    }
                    new_word[i] = prev;
                }
            }
            q = move(new_q);
        }
        return 0;
    }
};
