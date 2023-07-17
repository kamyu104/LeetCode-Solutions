// Time:  O((m + n) * l), n = len(word), m = len(forbidden), l = max(len(w) for w in forbidden)
// Space: O(t), t is the size of trie

// two pointers, sliding window, trie
class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        Trie trie;
        for (const auto& w : forbidden) {
            trie.insert(w);
        }
        int result = 0;
        for (int left = size(word) - 1, right = size(word) - 1; left >= 0; --left) {
            for (int i = left, curr = 0; i <= right; ++i) {
                curr = trie.child(curr, word[i]);
                if (!curr) {  // O(l) times
                    break;
                }
                if (trie.is_string(curr)) {
                    right = i - 1;
                    break;
                }
            }
            result = max(result, right - left + 1);
        }
        return result;
    }

private:
class Trie {
    public:
        Trie() {
            create_node(); 
        }

        void insert(const string& s) {
            int curr = 0;
            for (const auto& c : s) {
                if (!nodes_[curr][c - 'a']) {
                    nodes_[curr][c - 'a'] = create_node();
                }
                curr = nodes_[curr][c - 'a'];
            }
            ++nodes_[curr].back();
        }

        int child(int curr, char c) const {
            return nodes_[curr][c - 'a'];
        }

        bool is_string(int curr) const {
            return nodes_[curr].back();
        }

    private:
        int create_node() {
            nodes_.emplace_back(26 + 1);
            return size(nodes_) - 1;
        }

        using TrieNode = vector<int>;
        vector<TrieNode> nodes_;
    };
};
