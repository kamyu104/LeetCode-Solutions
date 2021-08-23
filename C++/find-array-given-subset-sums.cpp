// Time:  O(n * 2^n), len(sums) = 2^n
// Space: O(2^n)

// optimized from solution2
class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& sums) {
        unordered_map<int, int> dp;
        for (const auto& sum : sums) {
            ++dp[sum];
        }
        vector<int> sorted_nums;
        for (const auto& [k, _] : dp) {
            sorted_nums.emplace_back(k);
        }
        sort(begin(sorted_nums), end(sorted_nums));  // Time: O(2^n * log(2^n)) = O(n * 2^n)
        int shift = 0;
        uint32_t total = 0;
        for (const auto& [k, v] : dp) {
            total |= v;
        }
        const uint32_t basis = total & -total;  // find rightmost bit 1
        if (basis > 1) {
            for (auto& [_, v] : dp) {
                v /= basis;
            }
        }
        vector<int> result(bit_length(basis) - 1);
        while (size(result) != n) { // log(2^n) times, each time costs O(2^n), Total Time: O(2^n)
            unordered_map<int, int> new_dp;
            vector<int> new_sorted_nums;
            const int new_shift = (dp[sorted_nums[0]] == 1) ? sorted_nums[0] - sorted_nums[1] : 0;
            assert(new_shift <= 0);
            for (const auto& x : sorted_nums) {
                if (!dp[x]) {
                    continue;
                }
                dp[x - new_shift] -= new_shift ? dp[x] : dp[x] / 2;
                new_dp[x - new_shift] = dp[x];
                new_sorted_nums.emplace_back(x - new_shift);
            }
            dp = move(new_dp);
            sorted_nums = move(new_sorted_nums);
            if (dp.count(shift)) {
                result.emplace_back(new_shift);
            } else {
                result.emplace_back(-new_shift);
                shift -= new_shift;
            }
        }
        return result;
    }

private:
    int bit_length(int x) {
        return x != 0 ? 32 - __builtin_clz(x) : 1;
    }
};

// Time:  O(n * 2^n), len(sums) = 2^n
// Space: O(2^n)
class Solution2 {
public:
    vector<int> recoverArray(int n, vector<int>& sums) {
        unordered_map<int, int> dp;
        for (const auto& sum : sums) {
            ++dp[sum];
        }
        vector<int> sorted_nums;
        for (const auto& [k, _] : dp) {
            sorted_nums.emplace_back(k);
        }
        sort(begin(sorted_nums), end(sorted_nums));  // Time: O(2^n * log(2^n)) = O(n * 2^n)
        int shift = 0;
        vector<int> result;
        while (size(result) != n) { // log(2^n) times, each time costs O(2^n), Total Time: O(2^n)
            unordered_map<int, int> new_dp;
            vector<int> new_sorted_nums;
            const int new_shift = (dp[sorted_nums[0]] == 1) ? sorted_nums[0] - sorted_nums[1] : 0;
            assert(new_shift <= 0);
            for (const auto& x : sorted_nums) {
                if (!dp[x]) {
                    continue;
                }
                dp[x - new_shift] -= new_shift ? dp[x] : dp[x] / 2;
                new_dp[x - new_shift] = dp[x];
                new_sorted_nums.emplace_back(x - new_shift);
            }
            dp = move(new_dp);
            sorted_nums = move(new_sorted_nums);
            if (dp.count(shift)) {
                result.emplace_back(new_shift);
            } else {
                result.emplace_back(-new_shift);
                shift -= new_shift;
            }
        }
        return result;
    }
};
