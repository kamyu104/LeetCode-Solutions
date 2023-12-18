// Time:  O(nlogn)
// Space: O(1)

// sort
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        vector<vector<int>> result;
        result.reserve(size(nums) / 3);
        for (int i = 0; i < size(nums); i += 3) {
            if (nums[i + 2] - nums[i] > k) {
                return {};
            }
            result.emplace_back(cbegin(nums) + i, cbegin(nums) + i + 3);
        }
        return result;
    }
};
