// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }
        int result = 1;
        for (int i = 0, cnt = 1; i < n - 1; ++i) {
            cnt *= 9 - i;
            result += cnt;
        }
        return 1 + 9 * result;
    }
};

// Time:  O(n)
// Space: O(n)
class Solution2 {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> fact(2, 1);
        const auto& nPr = [&](int n, int k) {
            while (size(fact) <= n) {  // lazy initialization
                fact.emplace_back(fact.back() * size(fact));
            }
            return fact[n] / fact[n - k];
        };

        int result = 0;
        for (int i = 0; i < n; ++i) {
            result += nPr(9, i);
        }
        result *= 9;
        return ++result;
    }
};
