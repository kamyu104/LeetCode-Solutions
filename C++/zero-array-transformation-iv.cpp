// Time:  O(n^2 * r * logq), r = max(nums)
// Space: O(r)

// binary search, dp
class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        const auto& binary_search = [&](int left, int right, const auto& check) {
            while (left <= right) {
                const auto& mid = left + (right - left) / 2;
                if (check(mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return left;
        };

        const auto& check = [&](int l) {
            const auto& valid = [&](const vector<int>& arr, int target) {
                vector<uint8_t> dp(target + 1);
                dp[0] = true;
                for (int i = 0; i < size(arr); ++i) {
                    vector<uint8_t> new_dp(target + 1);
                    for (int j = 0; j <= target; ++j) {
                        new_dp[j] = dp[j] || (j - arr[i] >= 0 && dp[j - arr[i]]);
                    }
                    dp = move(new_dp);
                }
                return dp[target];
            };

            for (int i = 0; i < size(nums); ++i) {
                vector<int> arr;
                for (int j = 0; j < l; ++j) {
                    if (queries[j][0] <= i && i <= queries[j][1]) {
                        arr.emplace_back(queries[j][2]);
                    }
                }
                if (!valid(arr, nums[i])) {
                    return false;
                }
            }
            return true;
        };

        const int result = binary_search(0, size(queries), check);
        return result <= size(queries) ? result : -1;
    }
};

// Time:  O(q * n * 2^n)
// Space: O(n * 2^n)
// dp
class Solution2 {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<unordered_set<int>> dp(size(nums), unordered_set<int>{{0}});
        const auto& check = [&]() {
            int i = 0;
            for (; i < size(dp); ++i) {
                if (!dp[i].count(nums[i])) {
                    break;
                }
            }
            return i == size(dp);
        };

        for (int i = 0; i < size(queries); ++i) {
            if (check()) {
                return i;
            }
            for (int j = queries[i][0]; j <= queries[i][1]; ++j) {
                vector<int> new_dp;
                for (const auto& x : dp[j]) {
                    new_dp.emplace_back(x + queries[i][2]);
                }
                for (const auto& x : new_dp) {
                    dp[j].emplace(x);
                }
            }
        }
        return check() ? size(queries) : -1;
    }
};
