// Time:  O(n)
// Space: O(1)

// two pointers, combinatorics
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int64_t result = 0;
        for (int i = 0, prev = -1; i < size(nums); ++i) {
            if (nums[i]) {
                prev = i;
                continue;
            }
            result += i - prev;
        }
        return result;
    }
};
