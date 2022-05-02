// Time:  O(n^2)
// Space: O(t), t is the size of trie

// trie
class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        Trie trie;
        for (int i = 0; i < size(nums); ++i) {
            trie.insert(nums, i, k, p);
        }
        return trie.count();
    }

private:
    class Trie {
    public:
        Trie() : nodes_(1) {
            
        }

        void insert(const vector<int>& nums, int i, int k, int p) {
            int curr = 0, result = 0, cnt = 0;
            for (int j = i; j < size(nums); ++j) {
                cnt += (nums[j] % p == 0);
                if (cnt > k) {
                    break;
                }
                if (!nodes_[curr].count(nums[j])) {
                    nodes_[curr][nums[j]] = create_node();
                }
                curr = nodes_[curr][nums[j]];
            }
        }
    
        int count() const {
            return size(nodes_) - 1;
        }

    private:
        int create_node() {
            nodes_.emplace_back();
            return size(nodes_) - 1;
        }

        using TrieNode = unordered_map<int, int>;
        vector<TrieNode> nodes_;
    };
};

// Time:  O(n^2) on average, worst is O(n^3)
// Space: O(n)
// rolling hash
class Solution2 {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        static const int MOD = 1e9 + 7;
        static const int64_t P = 113;
        const auto& check = [&nums](const auto& lookup, int l, int i) {
            for (const auto& j : lookup) {
                int k = 0;
                for (; k < l; ++k) {
                    if (nums[i + k] != nums[j + k]) {
                        break;
                    }
                }
                if (k == l) {
                    return false;
                }
            }
            return true;
        };
        int result = 0;
        auto base = P;
        for (int l = 1; l <= size(nums); ++l, base = (base * P) % MOD) {
            unordered_map<int, vector<int>> lookup;
            int cnt = 0, h = 0;
            for (int i = 0; i < size(nums); ++i) {
                cnt += (nums[i] % p == 0);
                h = (h * P + nums[i]) % MOD;
                if (i - l >= 0) {
                    cnt -= (nums[i - l] % p == 0);
                    h = ((h - nums[i - l] * base) % MOD + MOD) % MOD;
                }
                if (i < l - 1 || cnt > k || !check(lookup[h], l, i - l + 1)) {
                    continue;
                }
                lookup[h].emplace_back(i - l + 1);
                ++result;
            }
        }
        return result;
    }
};

// Time:  O(n^2)
// Space: O(n)
// rolling hash
class Solution3 {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        static const int MOD = 1e9 + 7;
        static const int64_t P = 200;
        int result = 0;
        auto base = P;
        for (int l = 1; l <= size(nums); ++l, base = (base * P) % MOD) {
            unordered_set<int> lookup;
            int cnt = 0, h = 0;
            for (int i = 0; i < size(nums); ++i) {
                cnt += (nums[i] % p == 0);
                h = (h * P + nums[i]) % MOD;
                if (i - l >= 0) {
                    cnt -= (nums[i - l] % p == 0);
                    h = ((h - nums[i - l] * base) % MOD + MOD) % MOD;
                }
                if (i < l - 1 || cnt > k) {
                    continue;
                }
                lookup.emplace(h);  // assumed no collision
            }
            result += size(lookup);
        }
        return result;
    }
};
