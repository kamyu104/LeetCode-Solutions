// Time:  O(n^2 * n!)
// Space: O(n^2)

class Solution {
private:
    struct TrieNode {
        vector<int> indices;
        vector<TrieNode *> children;
        TrieNode() : children(26, nullptr) {}
    };

    TrieNode *buildTrie(const vector<string>& words) {
        TrieNode *root = new TrieNode();
        for (int j = 0; j < words.size(); ++j) {
            TrieNode* t = root;
            for (int i = 0; i < words[j].size(); ++i) {
                if (!t->children[words[j][i] - 'a']) {
                    t->children[words[j][i] - 'a'] = new TrieNode();
                }
                t = t->children[words[j][i] - 'a'];
                t->indices.push_back(j);
            }
        }
        return root;
    }

public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>> result;

        TrieNode *trie = buildTrie(words);
        vector<string> curr;
        for (const auto& s : words) {
            curr.emplace_back(s);
            wordSquaresHelper(words, trie, &curr, &result);
            curr.pop_back();
        }

        return result;
    }

private:
    void wordSquaresHelper(const vector<string>& words, TrieNode *trie, vector<string> *curr,
                           vector<vector<string>> *result) {
        if (curr->size() >= words[0].length()) {
            return result->emplace_back(*curr);
        }
        
        TrieNode *node = trie;     
        for (int i = 0; i < curr->size(); ++i) {
            if (!(node = node->children[(*curr)[i][curr->size()] - 'a'])) {
                return;
            }
        }

        for (const auto& i : node->indices) {
            curr->emplace_back(words[i]);
            wordSquaresHelper(words, trie, curr, result);
            curr->pop_back();
        }
    }
};
