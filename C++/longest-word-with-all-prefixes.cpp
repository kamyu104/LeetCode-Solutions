// Time:  O(n)
// Space: O(t), t is the number of nodes in trie

class TrieNode { 
public:
    bool isString = false;
    unordered_map<char, unique_ptr<TrieNode>> leaves;
        
    void Insert(const string& s) {
        auto p = this;
        for (const auto& c : s) {
            if (!p->leaves.count(c)) {
                p->leaves[c] = make_unique<TrieNode>();
            }
            p = p->leaves[c].get();
        }
        p->isString = true;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        auto trie = make_unique<TrieNode>();
        for (const auto& word : words) {
            trie->Insert(word);
        }
        string result, curr;
        dfs(trie.get(), &curr, &result);
        return result;
    }

private:
    void dfs(TrieNode *node, string *curr, string *result) {
        if (size(*curr) > size(*result)) {
            *result = *curr;
        }
        for (char c = 'a'; c <= 'z'; ++c) {
            if (!node->leaves.count(c) || !node->leaves[c]->isString) {
                continue;
            }
            curr->push_back(c);
            dfs(node->leaves[c].get(), curr, result);
            curr->pop_back();
        }
    }
};
