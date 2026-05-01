// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    long long minOperations(vector<int>& nums) {
        int64_t result = 0;
        for (int i = 0; i + 1 < size(nums); ++i) {
            result += max(nums[i] - nums[i + 1], 0);
        }
        return result;
    }
};
