// Time:  O(n * rlogr), r = max(nums)
// Space: O(r)

// dp
class Solution {
public:
    int minOperations(vector<int>& nums) {
        static const int INF = numeric_limits<int>::max();

        const auto& ceil_divide = [](int a, int b) {
            return (a + b - 1) / b;
        };

        const auto& mx = ranges::max(nums);
        if (mx == 1) {
            return 0;
        }
        vector<int> dp((2 * mx - 2) + 1, INF);
        dp[nums[0]] = 0;
        for (int i = 1; i < size(nums); ++i) {
            vector<int> new_dp((2 * mx - 2) + 1, INF);
            for (int x = 1; x < size(dp); ++x) {
                if (dp[x] == INF) {
                    continue;
                }
                for (int j = ceil_divide(nums[i], x); j * x < size(dp); ++j) {
                    new_dp[j * x] = min(new_dp[j * x], dp[x] + (j * x - nums[i]));
                }
            }
            dp = move(new_dp);
        }
        
        return ranges::min(dp);
    }
};
