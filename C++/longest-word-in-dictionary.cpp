// Time:  O(n), n is the total sum of the lengths of words
// Space: O(t), t is the number of nodes in trie

class Solution {
public:
    string longestWord(vector<string>& words) {
        TrieNode trie;
        for (int i = 0; i < words.size(); ++i) {
            trie.Insert(words[i], i);
        }

        // DFS
        stack<TrieNode *> stk;
        for (const auto& node : trie.leaves) {
            if (node) {
                stk.emplace(node);
            }
        }
        
        string result;
        while (!stk.empty()) {
            const auto curr = stk.top(); stk.pop();
            if (curr->isString) {
                const auto& word = words[curr->val];
                if (word.size() > result.size() || (word.size() == result.size() && word < result)) {
                    result = word;
                }
                for (const auto& node : curr->leaves) {
                    if (node) {
                        stk.emplace(node);
                    }
                }
            }
        }
        return result;
    }

private:
    struct TrieNode {
        bool isString;
        int  val;
        vector<TrieNode *> leaves;
        
        TrieNode() : isString{false}, val{0}, leaves(26) {}
        
        void Insert(const string& s, const int i) {
            auto* p = this;
            for (const auto& c : s) {
                if (!p->leaves[c - 'a']) {
                    p->leaves[c - 'a'] = new TrieNode;
                }
                p = p->leaves[c - 'a'];
            }
            p->isString = true;
            p->val = i;
        }
        
        ~TrieNode() {
            for (auto& node : leaves) {
                if (node) {
                    delete node;
                }
            }
        }
    };
};
