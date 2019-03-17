// Time:  O(logn)
// Space: O(logn)

class Solution {
public:
    int numDupDigitsAtMostN(int N) {
        const auto& digits = to_string(N + 1);
        int result = 0;

        // Given 321
        //
        // 1. count numbers without repeated digits:
        // - X
        // - XX
        for (int i = 1; i < digits.length(); ++i) {
            result += P(9, 1) * P(9, i - 1);
        }

        // 2. count numbers without repeated digits:
        // - 1XX ~ 3XX
        // - 30X ~ 32X
        // - 320 ~ 321
        unordered_set<int> prefix_set;
        for (int i = 0; i < digits.length(); ++i) {
            for (int d = (i == 0) ? 1 : 0; d < digits[i] - '0'; ++d) {
                if (prefix_set.count(d)) {
                    continue;
                }
                result += P(9 - i, digits.length() - i - 1);
            }
            if (prefix_set.count(digits[i] - '0')) {
                break;
            }
            prefix_set.emplace(digits[i] - '0');
        }
        return N - result;
    }

private:
    int P(int m, int n) const {
        int result = 1;
        while (n > 0) {
            result *= m - n + 1;
            --n;
        }
        return result;
    }
};
