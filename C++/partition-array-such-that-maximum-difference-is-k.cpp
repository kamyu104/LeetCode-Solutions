// Time:  O(nlogn)
// Space: O(1)

// sort, greedy
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int result = 1;
        for (int i = 0, prev = 0; i < size(nums); ++i) {
            if (nums[i] - nums[prev] <= k) {
                continue;
            }
            prev = i;
            ++result;
        }
        return result;
    }
};
