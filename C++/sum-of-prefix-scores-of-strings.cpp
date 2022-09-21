// Time:  O(n * l), n is the number of words, l is the max length of words
// Space: O(t), t is the size of trie

// trie
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        for (const auto& w : words) {
            trie.insert(w);
        }
        vector<int> result;
        for (const auto& w : words) {
            result.emplace_back(trie.query(w));
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
                ++nodes_[curr].back();
            }
        }

        int query(const string& s) {
            int result = 0, curr = 0;
            for (const auto& c : s) {
                curr = nodes_[curr][c - 'a'];
                result += nodes_[curr].back();
            }
            return result;
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
