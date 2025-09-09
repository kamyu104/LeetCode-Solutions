// Time:  O(n)
// Space: O(1)

// array
class Solution {
public:
    int minOperations(vector<int>& nums) {
        return all_of(cbegin(nums), cend(nums), [&](const auto& x) {
            return x == nums[0];
        }) ? 0 : 1;
    }
};
