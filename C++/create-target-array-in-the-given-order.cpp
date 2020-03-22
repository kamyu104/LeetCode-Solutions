// Time:  O(n^2)
// Space: O(1)

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            result.insert(begin(result) + index[i], nums[i]);
        }
        return result;
    }
};
