// Time:  O(n)
// Space: O(1)

// math
class Solution {
public:
    int minOperations(string s, int k) {
        const auto& ceil_divide = [](int a, int b) {
            return (a + b - 1) / b;
        };

        const int zero = ranges::count(s, '0');
        if (size(s) == k) {
            return zero == 0 ? 0 : (zero == size(s) ? 1 : -1);
        }
        int result = size(s) + 1;
        if ((k & 1) == (zero & 1)) {
            int i = max(ceil_divide(zero, k), ceil_divide(size(s) - zero, size(s) - k));
            if ((i & 1) == 0) {
                ++i;
            }
            result = min(result, i);
        }
        if ((zero & 1) == 0) {
            int i = max(ceil_divide(zero, k), ceil_divide(zero, size(s) - k));
            if ((i & 1) == 1) {
                ++i;
            }
            result = min(result, i);
        }
        return result <= size(s) ? result : -1;
    }
};

// Time:  O(1)
// Space: O(1)
// math
class Solution2 {
public:
    int minOperations(string s, int k) {
        const auto& ceil_divide = [](int a, int b) {
            return (a + b - 1) / b;
        };

        const int zero = ranges::count(s, '0');
        if (size(s) == k) {
            return zero == 0 ? 0 : (zero == size(s) ? 1 : -1);
        }
        int result = size(s) + 1;
        int i;
        i = max(ceil_divide(zero, k), ceil_divide(size(s) - zero, size(s) - k));
        if ((i & 1) == 0) {
            ++i;
        }
        if (((i * k - zero) & 1) == 0) {  // (k & 1) == (zero & 1)
            result = min(result, i);
        }
        i = max(ceil_divide(zero, k), ceil_divide(zero, size(s) - k));
        if ((i & 1) == 1) {
            ++i;
        }
        if (((i * k - zero) & 1) == 0) {  // (zero & 1) == 0
            result = min(result, i);
        }
        return result <= size(s) ? result : -1;
    }
};

// Time:  O(n)
// Space: O(1)
// math
class Solution3 {
public:
    int minOperations(string s, int k) {
        const int zero = ranges::count(s, '0');
        for (int64_t i = 0; i <= size(s); ++i) {
            if ((i * k - zero) & 1) {
                continue;
            }
            if (i & 1) {
                if (zero <= i * k && i * k <= zero * i + (size(s) - zero) * (i - 1)) {
                    return i;
                }
            } else {
                if (zero <= i * k && i * k <= zero * (i - 1) + (size(s) - zero) * i) {
                    return i;
                }
            }
        }
        return -1;
    }
};
