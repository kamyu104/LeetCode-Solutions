// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int result = 0, prev = 0, curr = 0;
        for (const auto& n : nums) {
            if (n == 0) {
                result = max(result, prev + curr + 1);
                prev = curr;
                curr = 0;
            } else {
                ++curr;
            }
        }
        return min(max(result, prev + curr + 1), static_cast<int>(nums.size()));
    }
};
