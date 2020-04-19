// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int min_prefix = 0, prefix = 0;
        for (const auto& num : nums) {
            prefix += num;
            min_prefix = min(min_prefix, prefix);
        }
        return 1 - min_prefix;
    }
};
