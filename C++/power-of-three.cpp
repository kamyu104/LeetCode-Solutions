// Time:  O(1)
// Space: O(1)

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) {
            return 0;
        }

        const int max_pow3 = log(numeric_limits<int>::max()) / log(3);
        return static_cast<int>(pow(3, max_pow3)) % n == 0;
    }
};
