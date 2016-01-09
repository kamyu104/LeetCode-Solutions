// Time:  O(1)
// Space: O(1)

class Solution {
public:
    static const int max_log3 = log(numeric_limits<int>::max()) / log(3);
    static const int max_pow3 = pow(3, max_log3);

    bool isPowerOfThree(int n) {
        return n > 0 && max_pow3 % n == 0;
    }
};
