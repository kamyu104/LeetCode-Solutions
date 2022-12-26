// Time:  O(n)
// Space: O(1)

// dp, math
class Solution {
public:
    long long evenProduct(vector<int>& nums) {
        int64_t result = (size(nums) + 1) * size(nums) / 2;
        int cnt = 0;
        for (const auto& x : nums) {
            cnt = (x % 2 == 1) ? cnt + 1 : 0;
            result -= cnt;
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(1)
// dp, math
class Solution2 {
public:
    long long evenProduct(vector<int>& nums) {
        int64_t result = 0;
        int cnt = 0;
        for (int i = 0; i < size(nums); ++i) {
            if (nums[i] % 2 == 0) {
                cnt = i + 1;
            }
            result += cnt;
        }
        return result;
    }
};
