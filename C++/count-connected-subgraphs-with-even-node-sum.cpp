// Time:  O(n + e + e * 2^n)
// Space: O(n + e)

// bitmask, dfs
class Solution {
public:
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        int odd_mask = 0;
        const auto& even = [&](int mask) {
            return !(__builtin_popcount(mask & odd_mask) % 2);
        };

        vector<vector<int>> adj(size(nums));
        const auto& connected = [&](int mask) {
            int i = 0;
            for (; i < size(nums); ++i) {
                if (mask & (1 << i)) {
                    break;
                }
            }
            mask ^= 1 << i;
            vector<int> stk = {i};
            while (!empty(stk)) {
                const int u = stk.back(); stk.pop_back();
                for (const auto& v : adj[u]) {
                    if (!(mask & (1 << v))) {
                        continue;
                    }
                    mask ^= 1 << v;
                    stk.emplace_back(v);
                }
            }
            return !mask;
        };

        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        for (int i = 0; i < size(nums); ++i) {
            if (nums[i]) {
                odd_mask |= 1 << i;
            }
        }
        int result = 0;
        for (int mask = 1; mask < (1 << size(nums)); ++mask) {
            if (even(mask) && connected(mask)) {
                ++result;
            }
        }
        return result;
    }
};

// Time:  O(n + e + (n + e) * 2^n)
// Space: O(n + e)
// bitmask, dfs
class Solution2 {
public:
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        const auto& even = [&](int mask) {
            int parity = 0;
            for (int i = 0; i < size(nums); ++i) {
                if (mask & (1 << i)) {
                    parity ^= nums[i];
                }
            }
            return !parity;
        };

        vector<vector<int>> adj(size(nums));
        const auto& connected = [&](int mask) {
            int i = 0;
            for (; i < size(nums); ++i) {
                if (mask & (1 << i)) {
                    break;
                }
            }
            mask ^= 1 << i;
            vector<int> stk = {i};
            while (!empty(stk)) {
                const int u = stk.back(); stk.pop_back();
                for (const auto& v : adj[u]) {
                    if (!(mask & (1 << v))) {
                        continue;
                    }
                    mask ^= 1 << v;
                    stk.emplace_back(v);
                }
            }
            return !mask;
        };

        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        int result = 0;
        for (int mask = 1; mask < (1 << size(nums)); ++mask) {
            if (even(mask) && connected(mask)) {
                ++result;
            }
        }
        return result;
    }
};
