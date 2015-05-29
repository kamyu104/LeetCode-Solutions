// Time:  O(n)
// Space: O(n)

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i) {
            if (hash.find(nums[i]) == hash.end()) {
                hash[nums[i]] = i;
            } else {
                // It the value occurs before, check the difference.
                if (i - hash[nums[i]] <= k) {
                    return true;
                }
                // Update the index of the value.
                hash[nums[i]] = i;
            }
        }
        return false;
    }
};
