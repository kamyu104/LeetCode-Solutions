// Time:  O(n)
// Space: O(1)

// array
class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int result = 0, sign = 1;
        for (const auto& x : nums) {
            result += sign * x;
            sign *= -1;
        }
        return result;
    }
};
