// Time:  O(log(logn)) = O(1)
// Space: O(1)

// bit manipulation
class Solution {
public:
    int calculateScore(int a, int b) {
        const auto& popcount = [](int n) {
            n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
            n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
            n = (n & 0x0F0F0F0F) + ((n >> 4) & 0x0F0F0F0F);
            n = (n & 0x00FF00FF) + ((n >> 8) & 0x00FF00FF);
            n = (n & 0x0000FFFF) + ((n >> 16) & 0x0000FFFF);
            return n;
        };

        const auto& s1 = popcount(a);
        const auto& s2 = popcount(b);
        return s1 >= s2 ? s1 * s2 : s2 / s1;
    }
};

// Time:  O(logn) = O(1)
// Space: O(1)
// bit manipulation
class Solution2 {
public:
    int calculateScore(int a, int b) {
        const auto& popcount = [](int x) {
            int result = 0;
            while (x) {
                x &= x - 1;
                ++result;
            }
            return result;
        };

        const auto& s1 = popcount(a);
        const auto& s2 = popcount(b);
        return s1 >= s2 ? s1 * s2 : s2 / s1;
    }
};

// Time:  O(1)
// Space: O(1)
// bit manipulation
class Solution3 {
public:
    int calculateScore(int a, int b) {
        const auto& s1 = __builtin_popcount(a);
        const auto& s2 = __builtin_popcount(b);
        return s1 >= s2 ? s1 * s2 : s2 / s1;
    }
};
