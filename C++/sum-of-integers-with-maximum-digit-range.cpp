// Time:  O(nlogr)
// Space: O(1)

// array
class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        const auto& count = [](int n) {
            int mx = -1, mn = 10;
            for (; n; n /= 10) {
                const auto& r = n % 10;
                mx = max(mx, r);
                mn = min(mn, r);
            }
            return mx - mn;
        };

        int result = 0, mx = 0;
        for (const auto& x : nums) {
            const auto& v = count(x);
            if (v > mx) {
                mx = v;
                result = x;
            } else if (v == mx) {
                result += x;
            }
        }
        return result;
    }
};
