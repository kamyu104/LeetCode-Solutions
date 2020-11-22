// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        vector<int> prefix(2), suffix(2);
        for (int k = 0; k < 2; ++k) {
            for (int i = k; i < size(nums); i += 2) {
                suffix[k] += nums[i];
            }
        }
        int result = 0;
        for (int i = 0; i < size(nums); ++i) {
            suffix[i % 2] -= nums[i];
            result += int(prefix[0] + suffix[1] == prefix[1] + suffix[0]);
            prefix[i % 2] += nums[i];
        }
        return result;
    }
};
