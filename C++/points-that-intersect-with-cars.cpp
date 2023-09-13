// Time:  O(nlogn)
// Space: O(1)

// sort, line sweep
class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        sort(begin(nums), end(nums));
        int result = 0;
        vector<int> curr = nums[0];
        for (int i = 1; i < size(nums); ++i) {
            if (nums[i][0] <= curr[1]) {
                curr[1] = max(curr[1], nums[i][1]);
            } else {
                result += curr[1] - curr[0] + 1;
                curr = nums[i]; 
            }
        }
        result += curr[1] - curr[0] + 1;
        return result;
    }
};
