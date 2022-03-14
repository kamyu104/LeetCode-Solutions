// Time:  O(n)
// Space: O(1)

// two pointers
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> result;
        int prev = -1;
        for (int i = 0; i < size(nums); ++i) {
            if (nums[i] != key) {
                continue;
            }
            for (int j = max(i - k, prev + 1); j <= min(i + k, static_cast<int>(size(nums) - 1)); ++j) {
                result.emplace_back(j);
            }
            prev = min(i + k, static_cast<int>(size(nums) - 1));
        }
        return result;
    }
};
