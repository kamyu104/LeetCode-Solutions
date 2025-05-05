// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int result = 0, prev = 0;
        for (const auto& x : nums) {
            if (prev <= x) {
                prev = x;
                ++result;
            }
        }
        return result;
    }
};
