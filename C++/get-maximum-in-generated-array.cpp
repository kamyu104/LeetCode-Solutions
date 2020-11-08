// Time:  O(n)
// Space: O(n)

vector<int> nums = {0, 1};
vector<int> dp = {0, 1};
class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n + 1 > size(dp)) {
            for (int i = size(nums); i <= n; ++i) {
                if (i % 2 == 0) {
                    nums.emplace_back(nums[i / 2]);
                } else {
                    nums.emplace_back(nums[i / 2] + nums[i / 2 + 1]);
                }
                dp.emplace_back(max(dp.back(), nums.back()));
            }
        }
        return dp[n];
    }
};


// Time:  O(n)
// Space: O(n)
class Solution2 {
public:
    int getMaximumGenerated(int n) {
        if (n == 0) {
            return 0;
        }
        vector<int> nums(n + 1);
        nums[1] = 1;
        int result = 1;
        for (int i = 2; i <= n; ++i) {
            if (i % 2 == 0) {
                nums[i] = nums[i / 2];
            } else {
                nums[i] = nums[i / 2] + nums[i / 2 + 1];
            }
            result = max(result, nums[i]);
        }
        return result;
    }
};
