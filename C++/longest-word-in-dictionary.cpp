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
        for (const auto& kvp : trie.leaves) {
            stk.emplace(kvp.second);
        }
        
        string result;
        while (!stk.empty()) {
            const auto curr = stk.top(); stk.pop();
            if (curr->isString) {
                const auto& word = words[curr->val];
                if (word.size() > result.size() || (word.size() == result.size() && word < result)) {
                    result = word;
                }
                for (const auto& kvp : curr->leaves) {
                    stk.emplace(kvp.second);
                }
            }
        }
        return result;
    }

private:
    struct TrieNode {
        bool isString = false;
        int  val = 0;
        unordered_map<char, TrieNode *> leaves;
        
        void Insert(const string& s, const int i) {
            auto* p = this;
            for (const auto& c : s) {
                if (p->leaves.find(c) == p->leaves.cend()) {
                    p->leaves[c] = new TrieNode;
                }
                p = p->leaves[c];
            }
            p->isString = true;
            p->val = i;
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
