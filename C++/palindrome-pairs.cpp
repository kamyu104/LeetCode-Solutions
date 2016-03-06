// Time:  O(n * l), n is the number of the words, l is the max length of the words.
// Space: O(n * l)

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
            for (int i = s.length() - 1; i >= 0; --i) {
                if (p->leaves.find(s[i]) != p->leaves.cend()) {
                    p = p->leaves[s[i]];
                    if (p->word_idx != -1) {
                        if (is_palindrome(s, i - 1) && idx != p->word_idx) {
                            res->push_back({p->word_idx, idx});
                        }
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
                    kv.second->~TrieNode();
                }
            }
        }
    };
};
