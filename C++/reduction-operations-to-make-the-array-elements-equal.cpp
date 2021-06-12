// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int result = 0, curr = 0;
        for (int i = 1; i < size(nums); ++i) {
            if (nums[i - 1] < nums[i]) {
                ++curr;
            }
            result += curr;
        }
        return result;
    }
};
