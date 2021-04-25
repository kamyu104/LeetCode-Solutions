// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    int sumBase(int n, int k) {
        int result = 0;
        for (; n; n /= k) {
            result += n % k;
        }
        return result;
    }
};
