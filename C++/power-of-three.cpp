// Time:  O(1)
// Space: O(1)

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) {
            return 0;
        }
        return max_pow3_ % n == 0;
    }

private:
    const int max_log3_ = log(numeric_limits<int>::max()) / log(3);
    const int max_pow3_ = pow(3, max_log3_);
};
