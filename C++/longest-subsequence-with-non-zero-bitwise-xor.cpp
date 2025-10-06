// Time:  O(n)
// Space: O(1)

// bitmasks
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        if (all_of(cbegin(nums), cend(nums), [](const auto& x) {
            return x == 0;
        })) {
            return 0;
        }
        return size(nums) - (accumulate(cbegin(nums), cend(nums), 0, [](const auto& accu, const auto& x) {
            return accu ^ x;
        }) == 0 ? 1 : 0);
    }
};
