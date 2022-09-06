// Time:  O(n)
// Space: O(n)

// hash table
class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> lookup;
        for (int i = 0; i + 1 < size(nums); ++i) {
            if (!lookup.emplace(nums[i] + nums[i + 1]).second) {
                return true;
            }
        }
        return false;
    }
};
