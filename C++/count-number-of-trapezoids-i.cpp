// Time:  O(n)
// Space: O(n)

// freq table, combinatorics
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        static const int MOD = 1e9 + 7;

        unordered_map<int, int> cnt;
        for (const auto& p : points) {
            ++cnt[p[1]];
        }
        int result = 0, total = 0;
        for (const auto& [_, c] : cnt) {
            const int curr = (static_cast<int64_t>(c) * (c - 1) / 2) % MOD;
            result = (result + (static_cast<int64_t>(total) * curr) % MOD) % MOD;
            total = (total + curr) % MOD;
        }
        return result;
    }
};
