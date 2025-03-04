// Time:  O(n^2)
// Space: O(n)

// dp, greedy
class Solution {
public:
    int minCost(vector<int>& nums) {
        unordered_map<int, int> dp = {{nums[0], 0}};
        for (int i = 1; i + 1 < size(nums); i += 2) {
            unordered_map<int, int> new_dp;
            const int x = nums[i], y = nums[i + 1];
            for (const auto& [z, c] : dp) {
                vector<int> v{x, y, z};
                sort(begin(v), end(v));
                new_dp[v[0]] = new_dp.count(v[0]) ? min(new_dp[v[0]], c + v[2]) : c + v[2];
                new_dp[v[2]] = new_dp.count(v[2]) ? min(new_dp[v[2]], c + v[1]) : c + v[1];
            }
            dp = move(new_dp);
        }
        const int last = size(nums) % 2 == 0 ? nums.back() : 0;
        int result = numeric_limits<int>::max();
        for (const auto& [x, c] : dp) {
            result = min(result, c + max(x, last));
        }
        return result;
    }
};
