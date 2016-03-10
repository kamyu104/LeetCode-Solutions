// Time:  O(n * k^2), n is the number of the words,
//                    k is the max length of the words.
// Space: O(n * k)

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        unordered_map<string, int> lookup;
        for (int i = 0; i < words.size(); ++i) {
            lookup[words[i]] = i;
        }

        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j <= words[i].length(); ++j) {
                if (is_palindrome(words[i], j, words[i].length() - 1)) {
                    string suffix = words[i].substr(0, j); 
                    reverse(suffix.begin(), suffix.end());
                    if (lookup.find(suffix) != lookup.end() && i != lookup[suffix]) {
                        res.push_back({i, lookup[suffix]});
                    }
                }
                if (j > 0 && is_palindrome(words[i], 0, j - 1)) {
                    string prefix = words[i].substr(j);
                    reverse(prefix.begin(), prefix.end());
                    if (lookup.find(prefix) != lookup.end() && lookup[prefix] != i) {
                        res.push_back({lookup[prefix], i});
                    }
                }
            }
        }
        return res;
    }

private:
    bool is_palindrome(string& s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
};

// Time:  O(n * k^2 + r), n is the number of the words,
//                        k is the max length of the words,
//                        r is the number of the result.
// Space: O(n * k^2)
// Manacher solution.
class Solution2 {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_multimap<string, int> prefix, suffix;
        for (int i = 0; i < words.size(); ++i) {  // O(n)
            vector<int> P;
            manacher(words[i], &P);
            for (int j = 0; j < P.size(); ++j) {  // O(k)
                if (j - P[j] == 1) {
                    prefix.emplace(words[i].substr((j + P[j]) / 2), i);  // O(k)
                }
                if (j + P[j] == P.size() - 2) {
                    suffix.emplace(words[i].substr(0, (j - P[j]) / 2), i);
                }
            }
        }

        vector<vector<int>> res;
        for (int i = 0; i < words.size(); ++i) {  // O(n)
            string reversed_word(words[i].rbegin(), words[i].rend());  // O(k)
            auto its = prefix.equal_range(reversed_word);
            for (auto it = its.first; it != its.second; ++it) {
                if (it->second != i) {
                    res.push_back({i, it->second});
                }
            }
            its = suffix.equal_range(reversed_word);
            for (auto it = its.first; it != its.second; ++it) {
                if (words[i].size() != words[it->second].size()) {
                    res.push_back({it->second, i});
                }
            }
        }
        return res;
    }

    void manacher(const string& s, vector<int> *P) {
        string T = preProcess(s);
        const int n = T.length();
        P->resize(n);
        int C = 0, R = 0;
        for (int i = 1; i < n - 1; ++i) {
            int i_mirror = 2 * C - i;
            (*P)[i] = (R > i) ? min(R - i, (*P)[i_mirror]) : 0;
            while (T[i + 1 + (*P)[i]] == T[i - 1 - (*P)[i]]) {
                ++(*P)[i];
            }
            if (i + (*P)[i] > R) {
                C = i;
                R = i + (*P)[i];
            }
        }
    }

    string preProcess(const string& s) {
        if (s.empty()) {
            return "^$";
        }
        string ret = "^";
        for (int i = 0; i < s.length(); ++i) {
            ret += "#" + s.substr(i, 1);
        }
        ret += "#$";
        return ret;
    }
};

// Time:  O(n * k^2 + r), n is the number of the words, k is the max length of the words.
//                        k is the max length of the words,
//                        r is the number of the result.
// Space: O(n * k)
// Trie solution.
class Solution_MLE {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        TrieNode trie;
        for (int i = 0; i < words.size(); ++i) {
            trie.insert(words[i], i);
        }
        for (int i = 0; i < words.size(); ++i) {
            trie.find(words[i], i, &res);
        }
        return res;
    }

private:
    struct TrieNode {
        int word_idx = -1;
        unordered_map<char, TrieNode *> leaves;
        
        void insert(const string& s, int i) {
            auto* p = this;
            for (const auto& c : s) {
                if (p->leaves.find(c) == p->leaves.cend()) {
                    p->leaves[c] = new TrieNode;
                }
                p = p->leaves[c];
            }
            p->word_idx = i;
        }

        void find(const string& s, int idx, vector<vector<int>> *res) {
            auto* p = this;
            for (int i = s.length() - 1; i >= 0; --i) {  // O(k)
                if (p->leaves.find(s[i]) != p->leaves.cend()) {
                    p = p->leaves[s[i]];
                    if (p->word_idx != -1 && p->word_idx != idx &&
                        is_palindrome(s, i - 1)) {  // O(k)
                        res->push_back({p->word_idx, idx});
                    }
                } else {
                    break;
                }
            }
        }

        bool is_palindrome(const string& s, int j) {
            int i = 0;
            while (i <= j) {
                if (s[i++] != s[j--]) {
                    return false;
                }
            }
            return true;
        }

        ~TrieNode() {
            for (auto& kv : leaves) {
                if (kv.second) {
                    delete kv.second;
                }
            }
        }
    };
};
