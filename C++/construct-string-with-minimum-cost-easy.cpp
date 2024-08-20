// Time:  O(n * w * l)
// Space: O(l)

static const int INF = numeric_limits<int>::max();

// dp
class Solution {
public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        int l = 0;
        for (const auto& w : words) {
            l = max(l, static_cast<int>(size(w)));
        }
        vector<int> dp(l + 1, INF);
        dp[0] = 0;
        for (int i = 0; i < size(target); ++i) {
            if (dp[i % size(dp)] == INF) {
                continue;
            }
            for (int j = 0; j < size(words); ++j) {
                if (target.substr(i, size(words[j])) == words[j]) {
                    dp[(i + size(words[j])) % size(dp)] = min(dp[(i + size(words[j])) % size(dp)], dp[i % size(dp)] + costs[j]);
                }
            }
            dp[i % size(dp)] = INF;
        }
        return dp[size(target) % size(dp)] != INF ? dp[size(target) % size(dp)] : -1;
    }
};

// Time:  O(n^2 + w * l)
// Space: O(t)
// trie, dp
class Solution2 {
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
                if (nodes_[curr][x] == -1) {
                    nodes_[curr][x] = new_node();
                }
                curr = nodes_[curr][x];
            }
            mns_[curr] = min(mns_[curr], c);
        }

        vector<pair<int, int>> query(int i, const string& t, vector<int>& dp) {
            vector<pair<int, int>> result;
            int curr = 0;
            for (int j = i; j < size(t); ++j) {
                const int x = t[j] - 'a';
                if (nodes_[curr][x] == -1) {
                    break;
                }
                curr = nodes_[curr][x];
                if (mns_[curr] != INF) {
                    dp[j + 1] = min(dp[j + 1], dp[i] + mns_[curr]);
                }
            }
            return result;
        }

    private:
        int new_node() {
            nodes_.emplace_back(26, -1);
            mns_.emplace_back(INF);
            return size(nodes_) - 1;
        }

        vector<vector<int>> nodes_;
        vector<int> mns_;
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
            trie.query(i, target, dp);
        }
        return dp.back() != INF ? dp.back() : -1;
    }
};


// Time:  O(n^2 + w * l)
// Space: O(t)
// trie, dp
class Solution3 {
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

        void query(int i, const string& t, vector<int>& dp) {
            auto* curr = this;
            for (int j = i; j < size(t); ++j) {
                const int x = t[j];
                if (!curr->children.count(x)) {
                    break;
                }
                curr = curr->children[x];
                if (curr->cost != INF) {
                    dp[j + 1] = min(dp[j + 1], dp[i] + curr->cost);
                }
            }
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
            trie.query(i, target, dp);
        }
        return dp.back() != INF ? dp.back() : -1;
    }
};
