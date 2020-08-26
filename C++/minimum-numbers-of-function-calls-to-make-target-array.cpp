// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int result = 0, max_len = 1;
        for (const auto& num : nums) {
            if (!num) {
                continue;
            }
            result += __builtin_popcount(num);
            max_len = max(max_len, 32 - __builtin_clz(num));
        }
        return result + max_len - 1;
    }
};
