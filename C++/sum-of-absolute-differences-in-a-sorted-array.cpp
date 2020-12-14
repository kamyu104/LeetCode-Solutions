// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int prefix = 0, suffix = accumulate(cbegin(nums), cend(nums), 0);
        vector<int> result;
        for (int i = 0; i < size(nums); ++i) {
            suffix -= nums[i];
            result.emplace_back((i * nums[i] - prefix) + (suffix - ((size(nums) - 1) - i) * nums[i]));
            prefix += nums[i];
        }
        return result;
    }
};
