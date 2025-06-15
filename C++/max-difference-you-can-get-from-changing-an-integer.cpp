// Time:  O(logn)
// Space: O(1)

// greedy
class Solution {
public:
    int maxDiff(int num) {
        const auto& find = [](int num, const auto& check) {
            int result = 0;
            for (; num; num /= 10) {
                const auto& d = num % 10;
                if (check(d)) {
                    result = d;
                }
            }
            return result;
        };

        const auto& reverse = [](int num, int l) {
            int result = 0;
            for (; num || l > 0; num /= 10, --l) {
                result = result * 10 + num % 10;
            };
            return result;
        };

        const auto& replace = [&](int num, int x, int y) {
            int result = 0, l = 0;
            for (; num; num /= 10, ++l) {
                auto d = num % 10;
                if (d == x) {
                    d = y;
                }
                result = result * 10 + d;
            };
            return reverse(result, l);
        };

        const auto& b = find(num, [](int x) { return x < 9; });
        const auto& a = find(num, [](int x) { return x > 1; });
        return replace(num, b, 9) - replace(num, a, reverse(num, 0) % 10 != 1 ? 1 : 0);
    }
};

// Time:  O(logn)
// Space: O(logn)
// greedy
class Solution2 {
public:
    int maxDiff(int num) {
        const auto& digits = to_string(num);
        char b = '0';
        for (const auto& c : digits) {
            if (c < '9') {
                b = c;
                break;
            }
        }
        char a = '0';
        for (const auto& c : digits) {
            if (c > '1') {
                a = c;
                break;
            }
        }
        string big(digits), small(digits);
        replace(begin(big), end(big), b, '9');
        replace(begin(small), end(small), a, digits[0] != '1' ? '1' : '0');
        return stoi(big) - stoi(small);
    }
};
