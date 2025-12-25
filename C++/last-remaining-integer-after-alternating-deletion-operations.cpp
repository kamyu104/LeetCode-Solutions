// Time:  O(1)
// Space: O(1)

// bitmasks
class Solution {
public:
    long long lastInteger(long long n) {
        static const int64_t MASK = 0xAAAAAAAAAAAAAL;
        return ((n - 1) & MASK) + 1;
    }
};

// Time:  O(logn)
// Space: O(1)
// simulation
class Solution2 {
public:
    long long lastInteger(long long n) {
        int64_t result = 1, l = 1;
        for (int p = 0; n != 1; n = (n + 1) / 2, l <<= 1, p ^= 1) {
            if (p && n % 2 == 0) {
                result += l;
            }
        }
        return result;
    }
};
