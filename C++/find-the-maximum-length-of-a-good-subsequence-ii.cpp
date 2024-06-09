// Time:  O(n * k)
// Space: O(n * k)

// dp
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        unordered_map<int, int> lookup;
        for (const auto& x : unordered_set<int>(cbegin(nums), cend(nums))) {
            lookup[x] = size(lookup);
        }
        vector<vector<int>> dp(k + 1, vector<int>(size(lookup)));
        vector<int> result(k + 1);
        for (auto x : nums) {
            x = lookup[x];
            for (int i = k; i >= 0; --i) {
                dp[i][x] = max(dp[i][x], i - 1 >= 0 ? result[i - 1] : 0) + 1;
                result[i] = max(result[i], dp[i][x]);
            }
        }
        return result[k];
    }
};

// Time:  O(n * k)
// Space: O(n * k)
// dp
class Solution2 {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<unordered_map<int, int>> dp(k + 1);
        vector<int> result(k + 1);
        for (const auto& x : nums) {
            for (int i = k; i >= 0; --i) {
                dp[i][x] = max(dp[i][x], i - 1 >= 0 ? result[i - 1] : 0) + 1;
                result[i] = max(result[i], dp[i][x]);
            }
        }
        return result[k];
    }
};

// Time:  O(n^2 * k)
// Space: O(n * k)
// dp
class Solution3 {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>> dp(size(nums), vector<int>(k + 1));
        int result = 0;
        for (int i = 0; i < size(nums); ++i) {
            dp[i][0] = 1;
            for (int l = 0; l <= k; ++l) {
                for (int j = 0; j < i; ++j) {
                    dp[i][l] = max({dp[i][l], nums[j] == nums[i] ? dp[j][l]+ 1 : 1, l - 1 >= 0 ? dp[j][l - 1] + 1 : 1});
                }
                result = max(result, dp[i][l]);
            }
        }
        return result;
    }
};
