// Time:  O(logn)
// Space: O(1)

// math
class Solution {
public:
    int countDigits(int num) {
        int result = 0;
        for (int curr = num; curr; curr /= 10) {
            result += static_cast<int>(num % (curr % 10) == 0);
        }
        return result;
    }
};
