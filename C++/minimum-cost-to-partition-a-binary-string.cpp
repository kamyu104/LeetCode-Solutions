// Time:  O(n)
// Space: O(n)

// prefix sum, divide and conquer
class Solution {
public:
    long long minCost(string s, int encCost, int flatCost) {
        vector<int64_t> prefix(size(s) + 1);
        const auto divide_and_conquer = [&](this auto&& divide_and_conquer, int left, int right) -> int64_t {
            const auto& l = right - left + 1;
            const auto& x = prefix[right + 1] - prefix[left];
            int64_t result = x ? l * x * encCost : flatCost;
            if (x && l % 2 == 0) {
                result = min(result, divide_and_conquer(left, (left + l / 2) - 1) + divide_and_conquer(left + l / 2, right));
            }
            return result;
        };

        for (int i = 0; i < size(s); ++i) {
            prefix[i + 1] = prefix[i] + (s[i] == '1' ? 1 : 0);
        }
        return divide_and_conquer(0, size(s) - 1);
    }
};

// Time:  O(n)
// Space: O(n)
// dp
class Solution2 {
public:
    long long minCost(string s, int encCost, int flatCost) {
        int l = size(s);
        for (; l % 2 == 0; l >>= 1);
        vector<pair<int64_t, int64_t>> dp;
        for (int left = 0; left < size(s); left += l) {
            int64_t x = 0;
            for (int i = left; i < left + l; ++i) {
                x += (s[i] == '1') ? 1 : 0;
            }
            dp.emplace_back(x ? l * x * encCost : flatCost, x);
        }
        while (size(dp) != 1) {
            vector<pair<int64_t, int64_t>> new_dp;
            l <<= 1;
            for (int i = 0; i < size(dp); i += 2) {
                const auto& v = dp[i].first + dp[i + 1].first;
                const auto& x = dp[i].second + dp[i + 1].second;
                new_dp.emplace_back(x ? min(l * x * encCost, v) : flatCost, x);
            }
            dp = move(new_dp);
        }
        return dp[0].first;
    }
};
