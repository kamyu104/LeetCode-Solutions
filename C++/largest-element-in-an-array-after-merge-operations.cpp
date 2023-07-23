// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int64_t result = 0;
        for (int64_t i = size(nums) - 1, curr = 0; i >= 0; --i) {
            if (nums[i] > curr) {
                curr = 0;
            }
            curr += nums[i];
            result = max(result, curr);
        }
        return result;
    }
};
