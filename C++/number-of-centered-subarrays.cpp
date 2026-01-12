// Time:  O(n^2)
// Space: O(n)

// hash table
class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < size(nums); ++i) {
            unordered_set<int> lookup;
            for (int j = i, total = 0; j < size(nums); ++j) {
                lookup.emplace(nums[j]);
                total += nums[j];
                if (lookup.count(total)) {
                    ++result;
                }
            }
        }
        return result;
    }
};
