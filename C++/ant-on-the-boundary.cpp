// Time:  O(n)
// Space: O(1)

// prefix sum
class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int result = 0, curr = 0;
        for (const auto& x : nums) {
            curr += x;
            if (curr == 0) {
                ++result;
            }
        }
        return result;
    }
};
