// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int result = 0;
        for (const auto& x : nums) {
            if (x ^ (result & 1)) {
                continue;
            }
            ++result;
        }
        return result;
    }
};
