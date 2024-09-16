// Time:  O(n + w * l)
// Space: O(n + w * l)

// rolling hash, hash table, two pointers, sliding window, dp
class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        static const int MOD = 1e9 + 7, P = 131;
        vector<int64_t> power = {1};
        for (int _ = 0; _ < size(target); ++_) {
            power.emplace_back(power.back() * P % MOD);
        }
        unordered_set<int> lookup;
        for (const auto& w : words) {
            int64_t h = 0;
            for (const auto& x : w) {
                h = (h * P + (x - 'a' + 1)) % MOD;
                lookup.emplace(h);
            }
        }
        vector<int> dp(size(target) + 1);
        for (int64_t right = 0, left = 0, h = 0; right < size(target); ++right) {
            h = (h * P + (target[right] - 'a' + 1)) % MOD;
            for (; right - left + 1 >= 1 && !lookup.count(h); ++left) {
                h = ((h - (target[left] - 'a' + 1) * power[(right - left + 1) - 1]) % MOD + MOD) % MOD;
            }
            if (right - left + 1 == 0) {
                return -1;
            }
            dp[right + 1] = dp[(right - (right - left + 1)) + 1] + 1;
        }
        return dp.back();
    }
};

// Time:  O(n + w * l)
// Space: O(n + t), t is the total size of ac automata trie
struct AhoNode {
    vector<AhoNode *> children;
    AhoNode *suffix;
    int length;
    AhoNode() :
        children(26, nullptr),
        suffix(nullptr),
        length(0) {}
};

class AhoTrie {
public:
    AhoTrie(const vector<string>& patterns) : root_(createACTrie(patterns)) {
        node_ = createACSuffixAndOutputLinks(root_);
    }

    int step(char letter) {
        while (node_ && !node_->children[letter - 'a']) {
            node_ = node_->suffix;
        }
        node_ = node_ ? node_->children[letter - 'a'] : root_;
        return getACNodeOutputs(node_);
    }
    
    void reset() {
        node_ = root_;
    }

private:
    AhoNode *createACTrie(const vector<string>& patterns) {  // Time:  O(n), Space: O(t)
        auto root = new AhoNode();
        for (int i = 0; i < patterns.size(); ++i) {
            auto node = root;
            for (int l = 1; l <= size(patterns[i]); ++l) {
                const auto c = patterns[i][l - 1];
                if (!node->children[c - 'a']) {
                    node->children[c - 'a'] = new AhoNode();
                }
                node = node->children[c - 'a'];
                node->length = l;
            }
        }
        return root;
    }
    
    AhoNode *createACSuffixAndOutputLinks(AhoNode *root) {  // Time:  O(n), Space: O(t)
        queue<AhoNode *> q;
        for (auto node : root->children) {
            if (!node) {
                continue;
            }
            q.emplace(node);
            node->suffix = root;
        }
                
        while (!q.empty()) {
            auto node = q.front(); q.pop();
            for (int c = 0; c < node->children.size(); ++c) {
                if (!node->children[c]) {
                    continue;
                }
                auto child = node->children[c];
                q.emplace(child);
                auto suffix = node->suffix;
                while (suffix && !suffix->children[c]) {
                    suffix = suffix->suffix;
                }
                child->suffix = suffix ? suffix->children[c] : root;
            }
        }
        
        return root;
    }
    
    int getACNodeOutputs(AhoNode *node) {  // modified
        return node->length;
    }
    
    AhoNode * const root_;
    AhoNode *node_;
};

// ac automata trie
class Solution2 {
public:
    int minValidStrings(vector<string>& words, string target) {
        auto trie = AhoTrie(words);
        vector<int> dp(size(target) + 1);
        for (int i = 0; i < size(target); ++i) {
            const int l = trie.step(target[i]);
            if (!l) {
                return -1;
            }
            dp[i + 1] = dp[(i - l) + 1] + 1;
        }
        return dp.back();
    }
};

// Time:  O(w * (l + n))
// Space: O(l + n)
// kmp, dp
class Solution3 {
public:
    int minValidStrings(vector<string>& words, string target) {
        const auto& getPrefix = [](const string& pattern) {
            vector<int> prefix(size(pattern), -1);
            int j = -1;
            for (int i = 1; i < size(pattern); ++i) {
                while (j != -1 && pattern[j + 1] != pattern[i]) {
                    j = prefix[j];
                }
                if (pattern[j + 1] == pattern[i]) {
                    ++j;
                }
                prefix[i] = j;
            }
            return prefix;
        };

        const auto& KMP = [&](const string& text, const string& pattern, const auto& update) {
            const vector<int> prefix = getPrefix(pattern);
            int j = -1;
            for (int i = 0; i < size(text); ++i) {
                while (j > -1 && pattern[j + 1] != text[i]) {
                    j = prefix[j];
                }
                if (pattern[j + 1] == text[i]) {
                    ++j;
                }
                update(i, j);
                if (j == size(pattern) - 1) {
                    j = prefix[j];
                }
            }
        };
    
        vector<int> lookup(size(target));
        const auto& update = [&](int i, int j) {
            lookup[i] = max(lookup[i], j + 1);
        };

        for (const auto& w : words) {
            KMP(target, w, update);
        }
        vector<int> dp(size(target) + 1);
        for (int i = 0; i < size(target); ++i) {
            if (!lookup[i]) {
                return -1;
            }
            dp[i + 1] = dp[(i - lookup[i]) + 1] + 1;
        }
        return dp.back();
    }
};

// Time:  O(w * l + n * l)
// Space: O(n + t), t is the total size of trie
// trie, dp
class Solution4 {
private:
    class Trie {
    public:
        Trie() {
             new_node();
         }

        void add(const string& w) {
            int curr = 0;
            for (const auto& c : w) {
                const int x = c - 'a';
                if (nodes_[curr][x] == -1) {
                    nodes_[curr][x] = new_node();
                }
                curr = nodes_[curr][x];
            }
        }

        int query(const string& target, int i) {
            int curr = 0;
            int l = 0;
            for (; l < size(target) - i; ++l) {
                const int x = target[i + l] - 'a';
                if (nodes_[curr][x] == -1) {
                    break;
                }
                curr = nodes_[curr][x];
            }
            return l;
        }

    private:
        int new_node() {
            nodes_.emplace_back(26, -1);
            return size(nodes_) - 1;
        }

        vector<vector<int>> nodes_;
    };

public:
    int minValidStrings(vector<string>& words, string target) {
        Trie trie;
        for (const auto& w : words) {
            trie.add(w);
        }
        vector<int> lookup(size(target));
        for (int i = 0; i < size(target); ++i) {
            const int l = trie.query(target, i);
            for (int nl = 1; nl <= l; ++nl) {
                lookup[i + nl - 1] = max(lookup[i + nl - 1], nl);
            }
        }
        vector<int> dp(size(target) + 1);
        for (int i = 0; i < size(target); ++i) {
            if (!lookup[i]) {
                return -1;
            }
            dp[i + 1] = dp[(i - lookup[i]) + 1] + 1;
        }
        return dp.back();
    }
};
