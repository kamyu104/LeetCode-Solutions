// Time:  O(b^(d/2)), b is the branch factor of bfs, d is the result depth
// Space: O(w * l), w is the number of words, l is the max length of words

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(cbegin(wordList), cend(wordList));
        if (!words.count(endWord)) {
            return {};
        }
        unordered_map<string, unordered_set<string>> tree;
        unordered_set<string> left = {beginWord}, right = {endWord};
        bool is_found = false, is_reversed = false;
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
                            is_found = true;
                        } else {
                            new_left.emplace(new_word);
                        }
                        if (!is_reversed) {
                            tree[new_word].emplace(word);
                        } else {
                            tree[word].emplace(new_word);
                        }
                    }
                    new_word[i] = prev;
                }
            }
            if (is_found) {
                break;
            }
            left = move(new_left);
            if (size(left) > size(right)) {
                swap(left, right);
                is_reversed = !is_reversed;
            }
        }
        return backtracking(tree, beginWord, endWord);
    }

private:
    vector<vector<string>> backtracking(
        const unordered_map<string, unordered_set<string>>& tree,
        const string& beginWord,
        const string& word) {
        
        vector<vector<string>> result;
        if (word == beginWord) {
            result.emplace_back(vector<string>({beginWord}));
        } else {
            if (tree.count(word)) {
                for (const auto& new_word : tree.at(word)) {
                    if (word == new_word) {
                        continue;
                    }
                    auto paths = backtracking(tree, beginWord, new_word);
                    for (auto& path : paths) {
                        path.emplace_back(word);
                        result.emplace_back(move(path));
                    }
                }
            }
        }
        return result;
    }
};
