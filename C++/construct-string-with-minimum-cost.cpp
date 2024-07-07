// Time:  O(n^2 + w * l)
// Space: O(t)

static const int INF = numeric_limits<int>::max();

// trie, dp
class Solution {
private:
    class Trie {
    public:
        Trie() {
             new_node();
         }

        void add(const string& w, int c) {
            int curr = 0;
            for (auto x : w) {
                x -= 'a';
                if (nodes[curr][x] == -1) {
                    nodes[curr][x] = new_node();
                }
                curr = nodes[curr][x];
            }
            mns[curr] = min(mns[curr], c);
        }

        vector<vector<int>> nodes;
        vector<int> mns;
    private:
        int new_node() {
            nodes.emplace_back(26, -1);
            mns.emplace_back(INF);
            return size(nodes) - 1;
        }
    };

public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        Trie trie;
        for (int i = 0; i < size(words); ++i) {
            trie.add(words[i], costs[i]);
        }
        vector<int> dp(size(target) + 1, INF);
        dp[0] = 0;
        for (int i = 0; i < size(target); ++i) {
            if (dp[i] == INF) {
                continue;
            }
            int curr = 0;
            for (int j = i; j < size(target); ++j) {
                const int x = target[j] - 'a';
                if (trie.nodes[curr][x] == -1) {
                    break;
                }
                curr = trie.nodes[curr][x];
                if (trie.mns[curr] != INF) {
                    dp[j + 1] = min(dp[j + 1], dp[i] + trie.mns[curr]);
                }
            }
        }
        return dp.back() != INF ? dp.back() : -1;
    }
};

// Time:  O(n^2 + w * l)
// Space: O(t)
// trie, dp
class Solution2 {
private:
    struct TrieNode {
        int cost = INF;
        unordered_map<char, TrieNode *> children;
        
        TrieNode() {}
        
        void add(const string& w, int c) {
            auto* curr = this;
            for (const auto& x : w) {
                if (!curr->children[x]) {
                    curr->children[x] = new TrieNode;
                }
                curr = curr->children[x];
            }
            curr->cost = min(curr->cost, c);
        }
        
        ~TrieNode() {
            for (auto& kv : children) {
                if (kv.second) {
                    delete kv.second;
                }
            }
        }
    };

public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        TrieNode trie;
        for (int i = 0; i < size(words); ++i) {
            trie.add(words[i], costs[i]);
        }
        vector<int> dp(size(target) + 1, INF);
        dp[0] = 0;
        for (int i = 0; i < size(target); ++i) {
            if (dp[i] == INF) {
                continue;
            }
            auto curr = &trie;
            for (int j = i; j < size(target); ++j) {
                const int x = target[j];
                if (!curr->children.count(x)) {
                    break;
                }
                curr = curr->children[x];
                if (curr->cost != INF) {
                    dp[j + 1] = min(dp[j + 1], dp[i] + curr->cost);
                }
            }
        }
        return dp.back() != INF ? dp.back() : -1;
    }
};
