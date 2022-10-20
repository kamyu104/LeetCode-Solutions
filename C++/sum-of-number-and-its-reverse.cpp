// Time:  O(2^(log10(n)/2)) = O(n^(1/(2*log2(10))))
// Space: O(log10(n)/2)

// backtracking
class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        const function<int(int, int)> backtracking = [&](int num, int total) {
            if (num == 0) {
                return true;
            }
            if (total == 1) {
                return false;
            }
            if (num <= 18) {
                return (num % 2 == 0) || (num == 11 && total == 0);
            }
            if (total == 2) {
                return false;
            }
            for (const auto& x : {num % 10, 10 + num % 10}) {
                if (!(1 <= x && x <= 18)) {
                    continue;
                }
                int base = 11;
                if (total) {
                    base = total;
                } else {
                    for (; x * ((base - 1) * 10 + 1) <= num; base = (base - 1) * 10 + 1);
                }
                if (num - x * base >= 0 && backtracking((num - x * base) / 10, base / 100 + 1)) {
                    return true;
                }
            }
            return false;
        };

        return backtracking(num, 0);
    }
};

// Time:  O(nlogn)
// Space: O(1)
// brute force
class Solution2 {
public:
    bool sumOfNumberAndReverse(int num) {
        const auto& reverse = [](int n) {
            int result = 0;
            for (; n; n /= 10) {
                result = result * 10 + n % 10;
            }
            return result;
        };

        for (int x = num / 2; x <= num; ++x) {
            if (x + reverse(x) == num) {
                return true;
            }
        }
        return false;
    }
};
