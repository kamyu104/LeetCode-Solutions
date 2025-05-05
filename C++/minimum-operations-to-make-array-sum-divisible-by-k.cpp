// Time:  O(n)
// Space: O(1)

// math
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        return accumulate(cbegin(nums), cend(nums), 0) % k;
    }
};
