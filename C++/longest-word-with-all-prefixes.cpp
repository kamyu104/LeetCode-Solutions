// Time:  O(n)
// Space: O(t), t is the number of nodes in trie

class Solution {
private:
    class TrieNode { 
    public:
        int idx = -1;
        unordered_map<char, unique_ptr<TrieNode>> leaves;

        void Insert(int i, const string& s) {
            auto p = this;
            for (const auto& c : s) {
                if (!p->leaves.count(c)) {
                    p->leaves[c] = make_unique<TrieNode>();
                }
                p = p->leaves[c].get();
            }
            p->idx = i;
        }
    };

public:
    string longestWord(vector<string>& words) {
        auto trie = make_unique<TrieNode>();
        for (int i = 0; i < size(words); ++i) {
            trie->Insert(i, words[i]);
        }
        return iter_dfs(words, trie.get());
    }

private:
    string iter_dfs(const vector<string>& words, TrieNode *node) {
        int result = -1;
        vector<TrieNode *> stk = {node};
        while (!empty(stk)) {
            const auto node = stk.back(); stk.pop_back();
            if (result == -1 || size(words[node->idx]) > size(words[result])) {
                result = node->idx;
            }
            for (char c = 'z'; c >= 'a'; --c) {
                if (!node->leaves.count(c) || node->leaves[c]->idx == -1) {
                    continue;
                }
                stk.emplace_back(node->leaves[c].get());
            }
        }
        return result != -1 ? words[result] : "";
    }
};


// Time:  O(n)
// Space: O(t), t is the number of nodes in trie
class Solution2 {
private:
    class TrieNode { 
    public:
        int idx = -1;
        unordered_map<char, unique_ptr<TrieNode>> leaves;

        void Insert(int i, const string& s) {
            auto p = this;
            for (const auto& c : s) {
                if (!p->leaves.count(c)) {
                    p->leaves[c] = make_unique<TrieNode>();
                }
                p = p->leaves[c].get();
            }
            p->idx = i;
        }
    };

public:
    string longestWord(vector<string>& words) {
        auto trie = make_unique<TrieNode>();
        for (int i = 0; i < size(words); ++i) {
            trie->Insert(i, words[i]);
        }
        int result = -1;
        dfs(words, trie.get(), &result);
        return result != -1 ? words[result] : "";
    }

private:
    void dfs(const vector<string>& words, TrieNode *node, int *result) {
        if (*result == -1 || size(words[node->idx]) > size(words[*result])) {
            *result = node->idx;
        }
        for (char c = 'a'; c <= 'z'; ++c) {
            if (!node->leaves.count(c) || node->leaves[c]->idx == -1) {
                continue;
            }
            dfs(words, node->leaves[c].get(), result);
        }
    }
};
