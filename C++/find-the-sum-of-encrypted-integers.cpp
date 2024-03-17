// Time:  O(nlogr)
// Space: O(1)

// array
class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        const auto& f = [](int x) {
            int mx = 0, base = 0;
            for (; x; x /= 10, base = 10 * base + 1) {
                mx = max(mx, x % 10);
            }
            return mx * base;
        };

        int result = 0;
        for (const auto& x : nums) {
            result += f(x);
        }
        return result;
    }
};
