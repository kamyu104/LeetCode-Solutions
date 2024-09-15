// Time:  O(n)
// Space: O(1)

// combinatorics
class Solution {
public:
    int getSum(vector<int>& nums) {
        static const int MOD = 1e9 + 7;
        const auto& count = [&](int d) {
            int64_t result = 0, total = 0, cnt = 0;
            for (int i = 0; i < size(nums); ++i) {
                total = (total + ++cnt * nums[i]) % MOD;
                result = (result + total) % MOD;
                if (i + 1 < size(nums) && nums[i + 1] - nums[i] == d) {
                    continue;
                }
                total = cnt = 0;
            }
            return result;
        };

        return (count(1) + count(-1) - accumulate(cbegin(nums), cend(nums), 0ll, [](const auto& a, const auto& b) {
            return (a + b) % MOD;
        })) % MOD;
    }
};
