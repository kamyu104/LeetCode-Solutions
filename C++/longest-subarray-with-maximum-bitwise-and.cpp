// Time:  O(n)
// Space: O(1)

// bit manipulation
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        const int mx = *max_element(cbegin(nums), cend(nums));
        int result = 1, l = 0;
        for (const auto& x : nums) {
            if (x == mx) {
                result = max(result, ++l);
            } else {
                l = 0;
            }
        }
        return result;
    }
};
