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
        for (int i = 0; i < size(words); ++i) {
            TrieNode* t = root;
            for (int j = 0; j < size(words[i]); ++j) {
                if (!t->children[words[i][j] - 'a']) {
                    t->children[words[i][j] - 'a'] = new TrieNode();
                }
                t = t->children[words[i][j] - 'a'];
                t->indices.emplace_back(i);
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
        if (size(*curr) == size(words[0])) {
            result->emplace_back(*curr);
            return;
        }
        
        TrieNode *node = trie;     
        for (int i = 0; i < size(*curr); ++i) {
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
