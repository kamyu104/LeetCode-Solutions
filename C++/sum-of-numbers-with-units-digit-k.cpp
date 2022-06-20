// Time:  O(1)
// Space: O(1)

// math
class Solution {
public:
    int minimumNumbers(int num, int k) {
        if (!num) {
            return 0;
        }
        const int d = k != 0 ? min(num / k, 10) : 1;
        for (int i = 1; i <= d; ++i) {
            if ((num - i * k) % 10 == 0) {
                return i;
            }
        }
        return -1;
    }
};
