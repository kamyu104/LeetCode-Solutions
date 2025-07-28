// Time:  O(nlogn)
// Space: O(1)

// sort, greedy
class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int64_t result = 0;
        for (int i = size(nums) / 3; i < size(nums); i += 2) {
            result += nums[i];
        }
        return result;
    }
};
