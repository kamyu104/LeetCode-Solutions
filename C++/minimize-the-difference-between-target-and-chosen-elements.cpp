// Time:  O(max_t * m * n), max_t is max_target
// Space: O(max_t)

// optimized from solution2 (using bitset), runtime: 32 ms
class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        static const int MAX_TARGET = 800;

        int chosen_min = 0;
        for (const auto& row : mat) {
            chosen_min += *min_element(cbegin(row), cend(row));
        }
        if (chosen_min >= target) {
            return chosen_min - target;
        }
        bitset<(2 * MAX_TARGET - 2) + 1> bs(1); // total < 2*target - 1
        for (const auto& row : mat) {
            bitset<(2 * MAX_TARGET - 2) + 1> new_bs;
            for (const auto& x : row) {
                new_bs |= bs << x;
            }
            bs = move(new_bs);
        }
        int result = size(bs);
        for (int total = chosen_min; total < size(bs); ++total) {
            if (!bs[total]) {
                continue;
            }
            result = min(result, abs(target - total));
            if (total > target) {
                break;
            }
        }
        return result;
    }
};

// Time:  O(t * m * n), t is target
// Space: O(t)
// optimized from solution_tle (not using unordered_set), runtime: 192 ms
class Solution2 {
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
        for (int total = chosen_min; total < size(dp); ++total) {
            if (!dp[total]) {
                continue;
            }
            result = min(result, abs(target - total));
            if (total > target) {
                break;
            }
        }
        return result;
    }
};

// Time:  O(t * m * n), t is target
// Space: O(t)
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
                    if ((total + x) - target < target - chosen_min) {
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
