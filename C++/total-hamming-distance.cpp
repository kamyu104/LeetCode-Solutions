// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < 8 * sizeof(int); ++i) {
            vector<int> counts(2);
            for (const auto& num : nums) {
                ++counts[(num >> i) & 1];
            }
            result += counts[0] * counts[1];
        }
        return result;
    }
};
