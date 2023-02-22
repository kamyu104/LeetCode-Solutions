// Time:  O(logn)
// Space: O(1)

// greedy, trick
// reference: https://leetcode.com/problems/minimum-operations-to-reduce-an-integer-to-0/solutions/3203994/java-c-python-1-line-solution/
class Solution {
public:
    int minOperations(int n) {
        return __builtin_popcount(n ^ (n * 0b11));
    }
};

// Time:  O(logn)
// Space: O(1)
// greedy
class Solution2 {
public:
    int minOperations(int n) {
        int result = 0;
        while (n) {
            if (!(n & 1)) {
                n >>= 1;
                continue;
            }
            ++result;
            n += static_cast<int>(n & 0b10 == 0b10);
            n >>= 2;
        }
        return result;
    }
};
