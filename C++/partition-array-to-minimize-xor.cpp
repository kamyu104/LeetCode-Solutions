// Time:  O(n^2 * k)
// Space: O(n)

// dp, prefix sum
class Solution {
public:
    int minXor(vector<int>& nums, int k) {
        static const int INF = numeric_limits<int>::max();

        vector<int> prefix(size(nums) + 1);
        for (int i = 0; i < size(nums); ++i) {
            prefix[i + 1] = prefix[i] ^ nums[i];
        }
        vector<int> dp(prefix);
        dp[0] = INF;
        for (int l = 2; l <= k; ++l){
            for (int i = size(nums); i >= l - 1; --i) {
                int mn = INF;
                for (int j = l - 1; j < i; ++j) {
                    const auto& v = prefix[i] ^ prefix[j];
                    const auto& mx = dp[j] > v ? dp[j] : v;
                    if (mx < mn) {
                        mn = mx;
                    }
                }
                dp[i] = mn;
            }
        }
        return dp[size(nums)];
    }
};

// Time:  O(n^2 * k)
// Space: O(n)
// dp, prefix sum
class Solution2 {
public:
    int minXor(vector<int>& nums, int k) {
        static const int INF = numeric_limits<int>::max();

        vector<int> prefix(size(nums) + 1);
        for (int i = 0; i < size(nums); ++i) {
            prefix[i + 1] = prefix[i] ^ nums[i];
        }
        vector<int> dp(size(nums) + 1, INF);
        dp[0] = 0;
        for (int l = 1; l <= k; ++l){
            for (int i = size(nums); i >= l - 1; --i) {
                dp[i] = INF;
                for (int j = l - 1; j < i; ++j) {
                    dp[i] = min(dp[i], max(dp[j], prefix[i] ^ prefix[j]));
                }
            }
        }
        return dp[size(nums)];
    }
};
