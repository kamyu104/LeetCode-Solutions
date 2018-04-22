// Time:  O(n), n is the total sum of the lengths of words
// Space: O(t), t is the number of nodes in trie

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> unique_words(words.cbegin(), words.cend());
        vector<TrieNode *> leaves;
        TrieNode trie;
        for (auto word : unique_words) {
            reverse(word.begin(), word.end());
            leaves.emplace_back(trie.Insert(word));
        }
        int result = 0;
        int i = 0;
        for (const auto& word: unique_words) {
            if (leaves[i++]->leaves.empty()) {
                result += word.length() + 1;
            }
        }
        return result;
    }

private:
    struct TrieNode {
        unordered_map<int, TrieNode *> leaves;
                
        TrieNode *Insert(const string& s) {
            auto* p = this;
            for (const auto& c : s) {
                if (!p->leaves[c - 'a']) {
                    p->leaves[c - 'a'] = new TrieNode;
                }
                p = p->leaves[c - 'a'];
            }
            return p;
        }
        
        ~TrieNode() {
            for (auto& node : leaves) {
                delete node.second;
            }
        }
    };
};
