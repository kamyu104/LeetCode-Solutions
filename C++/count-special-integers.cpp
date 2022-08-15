// Time:  O(logn)
// Space: O(logn)

// combinatorics
class Solution {
public:
    int countSpecialNumbers(int n) {
        const auto& P = [](int m, int n) {
            int result = 1;
            while (n--) {
                result *= m--;
            }
            return result;
        };

        const auto& digits = to_string(n + 1);
        int result = 0;
        for (int i = 1; i < size(digits); ++i) {
            result += P(9, 1) * P(9, i - 1);
        }
        unordered_set<int> lookup;
        for (int i = 0; i < size(digits); ++i) {
            for (int d = int(i == 0); d < digits[i] - '0'; ++d) {
                if (lookup.count(d)) {
                    continue;
                }
                result += P(9 - i, size(digits) - i - 1);
            }
            if (lookup.count(digits[i] - '0')) {
                break;
            }
            lookup.emplace(digits[i] - '0');
        }
        return result;
    }
};
