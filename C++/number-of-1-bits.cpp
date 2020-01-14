// Time:  O(logn(logn)) = O(5)
// Space: O(1)

class Solution {
public:
    int hammingWeight(uint32_t n) {
        n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
        n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
        n = (n & 0x0F0F0F0F) + ((n >> 4) & 0x0F0F0F0F);
        n = (n & 0x00FF00FF) + ((n >> 8) & 0x00FF00FF);
        n = (n & 0x0000FFFF) + ((n >> 16) & 0x0000FFFF);
        return n;
    }
};

// Time:  O(logn/4) = O(32/4) = O(8)
// Space: O(1)
// https://github.com/gcc-mirror/gcc/blob/master/libgcc/libgcc2.c#L856
class Solution2 {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        for (; n; n >>= 8) {
            result += popcount_tab_[n & 0xff];
        }
        return result;
    }

private:
    static constexpr int popcount_tab_[256] = {
        0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4,1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,
        1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
        1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
        2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,
        1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
        2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,
        2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,
        3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,4,5,5,6,5,6,6,7,5,6,6,7,6,7,7,8
    };
};

// Time:  O(logn/4) = O(32/4) = O(8)
// Space: O(1)
class Solution3 {
public:
    int hammingWeight(uint32_t n) {
        return __builtin_popcount(n);
    }
};

// Time:  O(logn) = O(32)
// Space: O(1)
class Solution4 {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for (; n; n &= n - 1) {
            ++count;
        }
        return count;
    }
};
