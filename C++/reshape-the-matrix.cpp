// Time:  O(m * n)
// Space: O(m * n)

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (nums.empty() ||
            r * c != nums.size() * nums[0].size()) {
            return nums;
        }

        vector<vector<int>> result(r, vector<int>(c));
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums[0].size(); ++j) {
                result[count / c][count % c] = nums[i][j];
                ++count;
            }
        }
        return result;
    }
};
