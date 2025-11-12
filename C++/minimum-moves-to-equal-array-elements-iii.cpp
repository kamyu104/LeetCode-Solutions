// Time:  O(n)
// Space: O(1)

// array
class Solution {
public:
    int minMoves(vector<int>& nums) {
        return ranges::max(nums) * size(nums) - accumulate(cbegin(nums), cend(nums), 0);
    }
};
