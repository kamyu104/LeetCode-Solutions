// Time:  O(10 * logr)
// Space: O(10)

// dp, prefix sum
class Solution {
public:
    long long goodIntegers(long long l, long long r, int k) {
        const auto& count = [&](int64_t n) -> int64_t {
            const auto& to_digits = [](int64_t x) {
                vector<int> digits;
                for (; x; x /= 10) {
                    digits.emplace_back(x % 10);
                }
                reverse(begin(digits), end(digits));
                if (empty(digits)) {
                    digits.emplace_back(0);
                }
                return digits;
            };

            if (n < 0) {
                return 0;
            }
            const auto& digits = to_digits(n);
            int64_t result = 1;
            int bound = size(digits);
            for (int i = 1; i < size(digits); ++i) {
                if (abs(digits[i] - digits[i - 1]) > k) {
                    bound = i;
                    break;
                }
            }
            if (bound == size(digits)) {
                ++result;
            }
            vector<int64_t> prefix(10 + 1);
            for (int i = size(digits) - 1; i >= 0; --i) {
                vector<int64_t> dp(10, 1);
                if (i != size(digits) - 1) {
                    for (int d = 0; d < size(dp); ++d) {
                        dp[d] = prefix[min(d + k, 9) + 1] - prefix[max(d - k, 0)];
                    }
                }
                for (int j = 0; j < size(dp); ++j) {
                    prefix[j + 1] = prefix[j] + dp[j];
                }
                result += prefix[(i == 0 ? digits[0] - 1 : 9) + 1] - prefix[1];
                if (1 <= i && i <= bound) {
                    result += max(prefix[min(digits[i - 1] + k, digits[i] - 1) + 1] - prefix[max(digits[i - 1] - k, 0)], static_cast<int64_t>(0));
                }
            }
            return result;
        };

        return count(r) - count(l - 1);
    }
};
