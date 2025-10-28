// Time:  O(logn)
// Space: O(1)

// math
class Solution {
public:
    long long removeZeros(long long n) {
        const auto& reverse = [](int64_t n) {
            int64_t result = 0;
            for (; n; n /= 10) {
                result = result * 10 + n % 10;
            }
            return result;
        };

        int64_t result = 0;
        for (; n; n /= 10) {
            if (n % 10) {
                result = result * 10 + n % 10;
            }
        }
        return reverse(result);
    }
};

// Time:  O(logn)
// Space: O(logn)
// string
class Solution2 {
public:
    long long removeZeros(long long n) {
        string result;
        for (const auto& x : to_string(n)) {
            if (x != '0') {
                result.push_back(x);
            }
        }
        return stoll(result);
    }
};
