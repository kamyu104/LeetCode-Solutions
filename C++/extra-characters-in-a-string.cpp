// Time:  O((n + m) * l), l is max(len(w) for w in dictionary)
// Space: O(n + t)

// trie, dp
class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        Trie trie;
        for (const auto& w : dictionary) {
            trie.insert(w);
        }
        vector<int> dp(size(s) + 1, numeric_limits<int>::max());
        dp[0] = 0;
        for (int i = 0; i < size(s); ++i) {
            dp[i + 1] = min(dp[i + 1], dp[i] + 1);
            for (int j = i, curr = 0; j < size(s); ++j) {
                curr = trie.child(curr, s[j]);
                if (!curr) {
                    break;
                }
                if (trie.is_string(curr)) {
                    dp[j + 1] = min(dp[j + 1], dp[i]);
                }
            }
        }
        return dp.back();
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
