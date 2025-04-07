// Time:  O(n * k * l), l = limits
// Space: O(n * k * l)

// dp
class Solution {
public:
    int maxProduct(vector<int>& nums, int k, int limit) {
        const int total = accumulate(cbegin(nums), cend(nums), 0);
        if (k > total || k < -total) {  // optimized to speed up
            return -1;
        }
        unordered_map<int, unordered_map<int, unordered_set<int>>> dp;
        for (const auto& x : nums) {
            unordered_map<int, unordered_map<int, unordered_set<int>>> new_dp;
            for (const auto& [p, total_products] : dp) {
                for (const auto& [total, products] : total_products) {
                    new_dp[p][total] = products;
                }
            }
            new_dp[1][x].emplace(min(x, limit + 1));
            for (const auto& [p, total_products] : dp) {
                const int new_p = p ^ 1;
                const int v = p == 0 ? x : -x;
                for (const auto& [total, products] : total_products) {
                    const int new_total = total + v;
                    for (const auto& v : products) {
                        new_dp[new_p][new_total].emplace(min(v * x, limit + 1));
                    }
                }
            }
            dp = move(new_dp);
        }
        int result = -1;
        for (const auto& [p, total_products] : dp) {
            for (const auto& [total, products] : total_products) {
                if (total != k) {
                    continue;
                }
                for (const auto& v : products) {
                    if (v <= limit) {
                        result = max(result, v);
                    }
                }
            }
        }
        return result;
    }
};
