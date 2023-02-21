// Time:  O(nlogn)
// Space: O(1)

// sort, greedy
class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(begin(nums), end(nums));
        return min({nums[size(nums) - 3] - nums[0],
                    nums[size(nums) - 2] - nums[1],
                    nums[size(nums) - 1] - nums[2]});
    }
};
