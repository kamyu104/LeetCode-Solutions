// Time:  O(n)
// Space: O(1)

// math
class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        return *max_element(cbegin(nums), cend(nums)) * k + k * (k - 1) / 2;
    }
};
