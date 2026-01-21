// Time:  O(n)
// Space: O(n)

// hash table
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        unordered_set<int> result;
        for (int i = 0; i < size(nums); ++i) {
            if (nums[i] == target[i]) {
                continue;
            }
            result.emplace(nums[i]);
        }
        return size(result);
    }
};
