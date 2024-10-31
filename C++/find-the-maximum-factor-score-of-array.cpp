// Time:  O(nlogr)
// Space: O(n)

// prefix sum
class Solution {
public:
    long long maxScore(vector<int>& nums) {
        vector<int64_t> right1(size(nums) + 1);
        vector<int64_t> right2(size(nums) + 1);
        right2.back() = 1;
        for (int i = size(nums) - 1; i >= 0; --i) {
            right1[i] = gcd(right1[i + 1], nums[i]);
            right2[i] = lcm(right2[i + 1], nums[i]);
        }
        int64_t result = right1[0] * right2[0];
        for (int64_t i = 0, curr1 = 0, curr2 = 1; i < size(nums); ++i) {
            result = max(result, gcd(curr1, right1[i + 1]) * lcm(curr2, right2[i + 1]));
            curr1 = gcd(curr1, nums[i]);
            curr2 = lcm(curr2, nums[i]);
        }
        return result;
    }
};
