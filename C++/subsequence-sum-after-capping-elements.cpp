// Time:  O(nlogn + n * k + klogn) = O(nlogn + n * k)
// Space: O(k)

// sort, dp, bitmasks
class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
        static const int MAX_K = 4000;
        sort(begin(nums), end(nums));
        vector<bool> result(size(nums));
        bitset<MAX_K + 1> dp;
        dp[0] = 1;
        for (int x = 1, i = 0; x <= size(nums); ++x){
            while (i < size(nums) && nums[i] < x) {
                dp |= (dp << nums[i]);
                ++i;
            }
            for (int j = max(k % x, k - (static_cast<int>(size(nums)) - i) * x); j <= k; j += x)
                if (dp[j]) {
                    result[x - 1] = true;
                }
        }
        return result;
    }
};

// Time:  O(nlogn + n * k + klogn) = O(nlogn + n * k)
// Space: O(k)
// sort, dp
class Solution2 {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
        static const int MAX_K = 4000;
        sort(begin(nums), end(nums));
        vector<bool> result(size(nums));
        vector<bool> dp(k + 1);
        dp[0] = true;
        for (int x = 1, i = 0; x <= size(nums); ++x){
            while (i < size(nums) && nums[i] < x) {
                for (int j = k; j - nums[i] >= 0; --j) {
                    dp[j] = dp[j] || dp[j - nums[i]];
                }
                ++i;
            }
            for (int j = max(k % x, k - (static_cast<int>(size(nums)) - i) * x); j <= k; j += x)
                if (dp[j]) {
                    result[x - 1] = true;
                }
        }
        return result;
    }
};
