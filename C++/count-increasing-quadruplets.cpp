// Time:  O(n^2)
// Space: O(n)

// dp
class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        vector<int64_t> dp(size(nums));  // dp[j] at l: # of tuple (i, j, k) s.t. i < j < k < l and nums[i] < nums[k] < nums[j]
        int64_t result = 0;
        for (int l = 0; l < size(nums); ++l) {
            int cnt = 0;
            for (int j = 0; j < l; ++j) {
                if (nums[j] < nums[l]) {
                    ++cnt;
                    result += dp[j];
                } else if (nums[j] > nums[l]) {
                    dp[j] += cnt;
                }
            }
        }
        return result;
    }
};

// Time:  O(n^2)
// Space: O(n^2)
// prefix sum
class Solution2 {
public:
    long long countQuadruplets(vector<int>& nums) {
        vector<vector<int64_t>> right(size(nums), vector<int64_t>(size(nums) + 1));
        for (int j = 0; j < size(nums); ++j) {
            for (int i = size(nums) - 1; i > j; --i) {
                right[j][i] = right[j][i + 1] + static_cast<int64_t>(nums[i] > nums[j]);
            }
        }
        int64_t result = 0;
        for (int k = 0; k < size(nums); ++k) {
            int64_t left = 0;
            for (int j = 0; j < k; ++j) {
                if (nums[k] < nums[j]) {
                    result += left * right[j][k + 1];
                }
                left += static_cast<int64_t>(nums[k] > nums[j]);
            }
        }
        return result;
    }
};

// Time:  O(n^2)
// Space: O(n^2)
// prefix sum
class Solution3 {
public:
    long long countQuadruplets(vector<int>& nums) {
        vector<vector<int64_t>> left(size(nums), vector<int64_t>(size(nums) + 1));
        for (int j = 0; j < size(nums); ++j) {
            for (int i = 0; i < j; ++i) {
                left[j][i + 1] = left[j][i] + static_cast<int64_t>(nums[i] < nums[j]);
            }
        }
        vector<vector<int64_t>> right(size(nums), vector<int64_t>(size(nums) + 1));
        for (int j = 0; j < size(nums); ++j) {
            for (int i = size(nums) - 1; i > j; --i) {
                right[j][i] = right[j][i + 1] + static_cast<int64_t>(nums[i] > nums[j]);
            }
        }
        int64_t result = 0;
        for (int k = 0; k < size(nums); ++k) {
            for (int j = 0; j < k; ++j) {
                if (nums[k] < nums[j]) {
                    result += left[k][j] * right[j][k + 1];
                }
            }
        }
        return result;
    }
};
