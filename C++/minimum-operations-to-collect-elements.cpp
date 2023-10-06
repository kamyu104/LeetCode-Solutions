// Time:  O(n)
// Space: O(k)

// hash table
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<bool> lookup(k);
        int i = size(nums) - 1;
        for (; i >= 0; --i) {
            if (nums[i] > size(lookup) || lookup[nums[i] - 1]) {
                continue;
            }
            lookup[nums[i] - 1] = true;
            if (!--k) {
                break;
            }
        }
        return size(nums) - i;
    }
};
