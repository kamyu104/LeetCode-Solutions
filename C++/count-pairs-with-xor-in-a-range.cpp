// Time:  O(n)
// Space: O(n)

// dp solution
class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        return count(nums, high + 1) - count(nums, low);
    }

private:
    int count(const vector<int>& nums, int x) {
        unordered_map<int, int> dp;
        for (const auto& x : nums) {
            ++dp[x];
        }
        int result = 0;
        for (; x; x >>= 1) {
            unordered_map<int, int> new_dp;
            for (auto const& [k, v] : dp) {
                new_dp[k >> 1] += v;
                if ((x & 1) == 0) {
                    continue;
                }
                if (dp.count((x ^ 1) ^ k)) {
                    result += v * dp[(x ^ 1) ^ k];  // current limit is xxxxx1*****, count xor pair with xxxxx0***** pattern
                }
            }
            dp = move(new_dp);
        }
        return result / 2;
    }
};

// Time:  O(n)
// Space: O(n)
// trie solution
class Solution2 {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        int result = 0;
        Trie trie;
        for (const auto& x : nums) {
            result += trie.query(x, high + 1) - trie.query(x, low);
            trie.insert(x);
        }
        return result;
    }

private:
    class Trie {
    public:
        Trie() : nodes(1) {}

        void insert(int num) {
            int idx = 0;
            for (int i = 31; i >= 0; --i) {
                int curr = (num >> i) & 1;
                if (!nodes[idx][curr]) {
                    nodes.emplace_back();
                    nodes[idx][curr] = size(nodes) - 1;
                }
                idx = nodes[idx][curr];
                ++nodes[idx][2];
            }
        }

        int query(int num, int limit) {
            int result = 0, idx = 0;
            for (int i = 31; i >= 0; --i) {
                int curr = (num >> i) & 1;
                int bit = (limit >> i) & 1;
                if (bit) {
                    if (nodes[idx][curr]) {
                        result += nodes[nodes[idx][0 ^ curr]][2];  // current limit is xxxxx1*****, count xor pair with xxxxx0***** pattern
                    }
                }
                if (!nodes[idx][bit ^ curr]) {
                    break;
                }
                idx = nodes[idx][bit ^ curr];
            }
            return result;
        }

    private:
        vector<array<int, 3>> nodes;
    };
};
