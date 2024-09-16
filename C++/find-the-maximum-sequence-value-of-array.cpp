// Time:  O(n * r + r^2)
// Space: O(r)

// bitmasks, prefix sum, dp
class Solution {
public:
    int maxValue(vector<int>& nums, int k) {
        static const int INF = numeric_limits<int>::max();
        static const int MAX_MASK = 127;
        
        const auto& is_submask = [](int a, int b) {
            return (a | b) == b;
        };
    
        const auto& dp = [&](int d, int npos) {
            vector<int> result(MAX_MASK + 1, npos);
            vector<int> dp(MAX_MASK + 1, INF), cnt(MAX_MASK + 1, 0);
            const int begin = d == 1 ? 0 : size(nums) - 1;
            const int end = d == 1 ? size(nums) : -1;
            for (int i = begin ; i != end; i += d) {
                dp[nums[i]] = 1;
                for (int mask = 0; mask <= MAX_MASK; ++mask) {
                    if (is_submask(nums[i], mask)) {
                        ++cnt[mask];
                    }
                    if (dp[mask] != INF) {
                        dp[mask | nums[i]] = min(dp[mask | nums[i]], dp[mask] + 1);
                    }
                }
                for (int mask = 0; mask < MAX_MASK + 1; ++mask) {
                    if (cnt[mask] >= k && dp[mask] <= k && result[mask] == npos) {
                        result[mask] = i;
                    }
                }
            }
            return result;
        };

        const auto& left = dp(1, size(nums));
        const auto& right = dp(-1, -1);
        for (int result = MAX_MASK; result >= 0; --result) {
            for (int l = 1; l <= MAX_MASK; ++l) {
                if (left[l] < right[result ^ l]) {
                    return result;
                }
            }
        }
        return 0;
    }
};

// Time:  O(n * k * r + n * r^2)
// Space: O(n * k * r)
// prefix sum, dp
class Solution_TLE {
public:
    int maxValue(vector<int>& nums, int k) {
        vector<vector<unordered_set<int>>> left(size(nums) + 1, vector<unordered_set<int>>(k + 1));
        for (int i = 0; i < size(left); ++i) {
            left[i][0].emplace(0);
        }
        for (int i = 0; i < size(nums); ++i) {
            for (int j = 1; j < size(left[i + 1]); ++j) {
                left[i + 1][j] = left[i][j];
                for (const auto& x : left[i][j - 1]) {
                    left[i + 1][j].emplace(x | nums[i]);
                }
            }
        }
        vector<vector<unordered_set<int>>> right(size(nums) + 1, vector<unordered_set<int>>(k + 1));
        for (int i = 0; i < size(right); ++i) {
            right[i][0].emplace(0);
        }
        for (int i = size(nums) - 1; i >= 0; --i) {
            for (int j = 1; j < size(right[i]); ++j) {
                right[i][j] = right[i + 1][j];
                for (const auto& x : right[i + 1][j - 1]) {
                    right[i][j].emplace(x | nums[i]);
                }
            }
        }
        int result = 0;
        for (int i = k; i <= size(nums) - k; ++i) {
            for (const auto& l : left[i][k]) {
                for (const auto& r : right[i][k]) {
                    result = max(result, l ^ r);
                }
            }
        }
        return result;
    }
};
