// Time:  O(1)
// Space: O(1)

class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && max_pow3_ % n == 0;
    }

private:
    const int max_log3_ = log(numeric_limits<int>::max()) / log(3);
    const int max_pow3_ = pow(3, max_log3_);
};
