// Time:  O(n)
// Space: O(1)

// array
class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int result = 0, l = 0;
        for (const auto& x : nums) {
            if (x > threshold) {
                l = 0;
                continue;
            }
            if (l % 2 == x % 2) {
                ++l;
            } else {
                l = (x + 1) % 2;
            }
            result = max(result, l);
        }
        return result;
    }
};
