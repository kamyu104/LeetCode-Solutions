// Time:  O(n)
// Space: O(n)

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lookup;
        for (int i = 0; i < nums.size(); ++i) {
            if (lookup.find(nums[i]) == lookup.end()) {
                lookup[nums[i]] = i;
            } else {
                // It the value occurs before, check the difference.
                if (i - lookup[nums[i]] <= k) {
                    return true;
                }
                // Update the index of the value.
                lookup[nums[i]] = i;
            }
        }
        return false;
    }
};
