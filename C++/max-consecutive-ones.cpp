// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int result = 0, local_max = 0;
        for (const auto& n : nums) {
            local_max = n ? local_max + 1 : 0;
            result = max(result, local_max);
        }
        return result;
    }
};
