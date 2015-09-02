// Time:  O(1)
// Space: O(1)

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};

class Solution2 {
public:
    bool isPowerOfTwo(int n) {
         return n > 0 && (n & ~-n) == 0;
    }
};
