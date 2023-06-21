// Time:  O(nlogn)
// Space: O(1)

// sort
class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int result = numeric_limits<int>::max();
        for (int i = 0; i + 1 < size(nums); ++i) {
            result = min(result, nums[i + 1] - nums[i]);
        }
        return result;
    }
};
