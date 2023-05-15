// Time:  O(m * nlogn)
// Space: O(1)

// sort
class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        for (auto& row : nums) {
            sort(begin(row), end(row));
        }
        int result = 0;
        for (int c = 0; c < size(nums[0]); ++c) {
            int mx = 0;
            for (int r = 0; r < size(nums); ++r) {
                mx = max(mx, nums[r][c]);
            }
            result += mx;
        }
        return result;
    }
};
