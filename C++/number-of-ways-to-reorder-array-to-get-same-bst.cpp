// Time:  O(n^2)
// Space: O(n^2)

static vector<vector<int>> dp;

class Solution {
public:
    int numOfWays(vector<int>& nums) {
        static const int MAX_N = 1000;
        if (dp.empty()) {
            dp = vector<vector<int>>(MAX_N, vector<int>(MAX_N));
            for (int i = 0; i < dp.size(); ++i) {
                dp[i][0] = 1;
                for (int j = 1; j <= i; ++j) {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
                }
            }
        }

        return ((iter_dfs(nums) - 1) % MOD + MOD) % MOD;
    }

private:
    int iter_dfs(const vector<int>& nums) {
        using RET = int;
        RET result = 0;
        vector<tuple<int, shared_ptr<vector<int>>, shared_ptr<RET>, shared_ptr<RET>, RET *>> stk;
        stk.emplace_back(1, make_shared<vector<int>>(cbegin(nums), cend(nums)), nullptr, nullptr, &result);
        while (!stk.empty()) {
            auto [step, nums, ret1, ret2, ret] = stk.back(); stk.pop_back();
            if (step == 1) {
                if (nums->size() <= 2) {
                    *ret = 1;
                    continue;
                }
                auto left = make_shared<vector<int>>(), right = make_shared<vector<int>>();
                for (int i = 1; i < nums->size(); ++i) {
                    if ((*nums)[i] < (*nums)[0]) {
                        left->emplace_back((*nums)[i]);
                    } else {
                        right->emplace_back((*nums)[i]);
                    }
                }
                auto ret1 = make_shared<RET>(), ret2 = make_shared<RET>();
                *ret = dp[left->size() + right->size()][left->size()];
                stk.emplace_back(2, nullptr, ret1, ret2, ret);
                stk.emplace_back(1, right, nullptr, nullptr, ret2.get());
                stk.emplace_back(1, left, nullptr, nullptr, ret1.get());
            } else if (step == 2) {
                *ret = int64_t(*ret) * (*ret1) % MOD;
                *ret = int64_t(*ret) * (*ret2) % MOD;
            }
        }
        return result;
    }

    static const int MOD = 1e9 + 7;
};


// Time:  O(n^2)
// Space: O(n^2)
class Solution2 {
public:
    int numOfWays(vector<int>& nums) {
        static const int MAX_N = 1000;
        if (dp.empty()) {
            dp = vector<vector<int>>(MAX_N, vector<int>(MAX_N));
            for (int i = 0; i < dp.size(); ++i) {
                dp[i][0] = 1;
                for (int j = 1; j <= i; ++j) {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
                }
            }
        }

        return ((dfs(nums) - 1) % MOD + MOD) % MOD;
    }

private:
    int dfs(const vector<int>& nums) {
        if (nums.size() <= 2) {
            return 1;
        }

        vector<int> left, right;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[0]) {
                left.emplace_back(nums[i]);
            } else {
                right.emplace_back(nums[i]);
            }
        }
        int64_t result = dp[left.size() + right.size()][left.size()];
        result = result * dfs(left) % MOD;
        result = result * dfs(right) % MOD;
        return result;
    }

    static const int MOD = 1e9 + 7;
};
