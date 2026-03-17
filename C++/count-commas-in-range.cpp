// Time:  O(logn)
// Space: O(1)

// math
class Solution {
public:
    int countCommas(int n) {
        int cnt = 0;
        for (int base = 1; base * 1000 <= n; base *= 1000) {
            ++cnt;
        }
        int result = 0;
        for (int i = 0, base = 1; i < cnt; ++i) {
            base *= 1000;
            result += n - base + 1;
        }
        return result;
    }
};
