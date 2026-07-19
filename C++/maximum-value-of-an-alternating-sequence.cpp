// Time:  O(1)
// Space: O(1)

// math
class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        return s + (n / 2LL) * m - ((n - 1) / 2LL) * 1 + (n != 1 ? n % 2 : 0);
    }
};
