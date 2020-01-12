// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i += 2) {
            for (int j = 0; j < nums[i]; ++j) {
                result.emplace_back(nums[i + 1]);
            }
        }
        return result;
    }
};
