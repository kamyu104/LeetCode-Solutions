// Time:  O(n)
// Space: O(t), t is the number of nodes in trie

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        TrieNode trie;
        string result;
        for (const auto& s : dict) {
            trie.Insert(s);
        }
        auto curr = &trie;
        for (int i = 0; i < sentence.length(); ++i) {
            if (sentence[i] == ' ' || !curr || !curr->isString) {
                result += sentence[i];
            }
            if (sentence[i] == ' ') {
                curr = &trie;
            } else if (curr && !curr->isString) {
                curr = curr->leaves[sentence[i]];
            }
        }
        return result;
    }

private:
    struct TrieNode {
        bool isString = false;
        unordered_map<char, TrieNode *> leaves;
        
        void Insert(const string& s) {
            auto* p = this;
            for (const auto& c : s) {
                if (p->leaves.find(c) == p->leaves.cend()) {
                    p->leaves[c] = new TrieNode;
                }
                p = p->leaves[c];
            }
            p->isString = true;
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
