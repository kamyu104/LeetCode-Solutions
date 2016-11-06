// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int minMoves(vector<int>& nums) {
        return accumulate(nums.cbegin(), nums.cend(), 0) -
               nums.size() * *min_element(nums.cbegin(), nums.cend());
    }
};
