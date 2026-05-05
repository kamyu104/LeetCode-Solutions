// Time:  O(n)
// Space: O(1)

// freq table
class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        vector<int> result(size(nums));
        vector<int> cnt(2);
        for (int i = size(nums) - 1; i >= 0; --i) {
            result[i] = cnt[1 ^ (nums[i] % 2)];
            ++cnt[nums[i] % 2];
        }
        return result;
    }
};
