// Time:  O(nlogr)
// Space: O(1)

// math
class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        const auto& count = [&](int x) {
            int result = 0;
            for (; x; x /= 10) {
                if (x % 10 == digit) {
                    ++result;
                }
            }
            return result;
        };

        int result = 0;
        for (const auto& x : nums) {
            result += count(x);
        }
        return result;
    }
};
