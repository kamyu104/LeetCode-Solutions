// Time:  O(n * 2^n), len(sums) = 2^n
// Space: O(1)

// optimized from solution4 (not using unordered_map), runtime: 188 ms
class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& sums) {
        sort(begin(sums), end(sums));  // Time: O(2^n * log(2^n)) = O(n * 2^n)
        int shift = 0, l = size(sums);
        vector<int> result;
        for (; n; --n, l /= 2) {  // log(2^n) times, each time costs O(2^(n-len(result))), Total Time: O(2^n)
            const int new_shift = sums[0] - sums[1];
            assert(new_shift <= 0);
            bool has_zero = false;
            for (int i = 0, j = 0, k = 0; i < l; ++i) {
                if (k < j && sums[k] == sums[i]) {
                    ++k;
                } else {
                    if (shift == sums[i] - new_shift) {
                        has_zero = true;
                    }
                    sums[j++] = sums[i] - new_shift;
                }
            }
            if (has_zero) {  // contain 0, choose this side
                result.emplace_back(new_shift);
            } else {  // contain no 0, choose another side and shift 0 offset
                result.emplace_back(-new_shift);
                shift -= new_shift;
            }
        }
        return result;
    }
};

// Time:  O(2^n + n * r), len(sums) = 2^n
//                      , r = max(sums)-min(sums)
// Space: O(2^n + r)
// optimized from solution4 (not using unordered_map), runtime: 148 ms
class Solution2 {
public:
    vector<int> recoverArray(int n, vector<int>& sums) {
        const int min_sum = *min_element(cbegin(sums), cend(sums));
        const int max_sum = *max_element(cbegin(sums), cend(sums));
        vector<int> dp(max_sum - min_sum + 1);
        for (const auto& sum : sums) {
            ++dp[sum - min_sum];
        }
        vector<int> sorted_nums;
        for (int x = min_sum; x <= max_sum; ++x) {
            if (dp[x - min_sum]) {
                sorted_nums.emplace_back(x);
            }
        }
        int shift = 0;
        vector<int> result;
        while (n--) { // log(2^n) times, each time costs O(2^(n-len(result)))+O(r), Total Time: O(2^n + n * r)
            vector<int> new_dp(max_sum - min_sum + 1);
            vector<int> new_sorted_nums;
            const int new_shift = (dp[sorted_nums[0] - min_sum] == 1) ? sorted_nums[0] - sorted_nums[1] : 0;
            assert(new_shift <= 0);
            for (const auto& x : sorted_nums) {
                if (!dp[x - min_sum]) {
                    continue;
                }
                dp[(x - new_shift) - min_sum] -= new_shift ? dp[x - min_sum] : dp[x - min_sum] / 2;
                new_dp[(x - new_shift) - min_sum] = dp[x - min_sum];
                new_sorted_nums.emplace_back(x - new_shift);
            }
            dp = move(new_dp);
            sorted_nums = move(new_sorted_nums);
            if (dp[shift - min_sum]) {  // contain 0, choose this side
                result.emplace_back(new_shift);
            } else {  // contain no 0, choose another side and shift 0 offset
                result.emplace_back(-new_shift);
                shift -= new_shift;
            }
        }
        return result;
    }
};

// Time:  O(n * 2^n), len(sums) = 2^n
// Space: O(2^n)
// optimized from solution4, runtime: 344 ms
class Solution3 {
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
        n -= bit_length(basis) - 1;
        while (n--) {  // log(2^n) times, each time costs O(2^(n-len(result))), Total Time: O(2^n)
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
            if (dp.count(shift)) {  // contain 0, choose this side
                result.emplace_back(new_shift);
            } else {  // contain no 0, choose another side and shift 0 offset
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
// runtime: 344 ms
class Solution4 {
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
        while (n--) {  // log(2^n) times, each time costs O(2^(n-len(result))), Total Time: O(2^n)
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
            if (dp.count(shift)) {  // contain 0, choose this side
                result.emplace_back(new_shift);
            } else {  // contain no 0, choose another side and shift 0 offset
                result.emplace_back(-new_shift);
                shift -= new_shift;
            }
        }
        return result;
    }
};
