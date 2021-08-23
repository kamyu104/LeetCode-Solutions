// Time:  O(t * n^2), t is target
// Space: O(t)

class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int chosen_min = 0;
        for (const auto& row : mat) {
            chosen_min += *min_element(cbegin(row), cend(row));
        }
        if (chosen_min >= target) {
            return chosen_min - target;
        }
        vector<uint8_t> dp(2 * target - chosen_min);
        dp[0] = true;
        for (const auto& row : mat) {
            vector<uint8_t> new_dp(2 * target - chosen_min);
            for (int total = 0; total < size(dp); ++total) {
                if (!dp[total]) {
                    continue;
                }
                for (const auto& x : row) {
                    if ((total + x) - target < target - chosen_min) {
                        new_dp[total + x] = 1;
                    }
                }
            }
            dp = move(new_dp);
        }
        int result = numeric_limits<int>::max();
        for (int total = 0; total < size(dp); ++total) {
            if (!dp[total]) {
                continue;
            }
            result = min(result, abs(target - total));
        }
        return result;
    }
};

// Time:  O(target * n^2)
// Space: O(target)
class Solution_TLE {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int chosen_min = 0;
        for (const auto& row : mat) {
            chosen_min += *min_element(cbegin(row), cend(row));
        }
        if (chosen_min >= target) {
            return chosen_min - target;
        }
        unordered_set<int> dp = {0};
        for (const auto& row : mat) {
            unordered_set<int> new_dp;
            for (const auto& total : dp) {
                for (const auto& x : row) {
                    if ((total + x) - target <= target - chosen_min) {
                        new_dp.emplace(total + x);
                    }
                }
            }
            dp = move(new_dp);
        }
        int result = numeric_limits<int>::max();
        for (const auto& total : dp) {
            result = min(result, abs(target - total));
        }
        return result;
    }
};
