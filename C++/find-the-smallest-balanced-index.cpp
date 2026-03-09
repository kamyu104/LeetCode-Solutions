// Time:  O(n)
// Space: O(1)

// prefix sum
class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int64_t left = accumulate(cbegin(nums), cend(nums), 0LL);
        for (int64_t i = size(nums) - 1, right = 1; i >= 0; --i) {
            left -= nums[i];
            if (left < right) {
                break;
            }
            if (left == right) {
                return i;
            }
            right *= nums[i];
        }
        return -1;
    }
};
