// Time:  O(nlogr)
// Space: O(10 * logr)

// prefix sum
class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int l = 0;
        for (int64_t base = 1; base <= nums[0]; base *= 10, ++l);
        vector<vector<int>> cnts(l, vector<int>(10));
        for (auto x : nums) {
            for (int i = 0; i < l; ++i, x /= 10) {
                ++cnts[i][x % 10];
            }
        }
        int64_t result = 0;
        for (const auto& cnt : cnts) {
            for (const auto& c : cnt) {
                result += c * (size(nums) - c);
            }
        }
        return result / 2;
    }
};
