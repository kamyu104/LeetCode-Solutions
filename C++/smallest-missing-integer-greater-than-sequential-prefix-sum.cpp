// Time:  O(n)
// Space: O(n)

// hash table
class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int total = nums[0];
        for (int i = 1; i < size(nums); ++i) {
            if (nums[i] != nums[i - 1] + 1) {
                break;
            }
            total += nums[i];
        }
        unordered_set<int> lookup(cbegin(nums), cend(nums));
        while (lookup.count(total)) {
            ++total;
        }
        return total;
    }
};
