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
