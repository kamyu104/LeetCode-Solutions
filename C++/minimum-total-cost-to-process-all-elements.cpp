// Time:  O(n)
// Space: O(1)

// math
class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        static const int MOD = 1e9 + 7;

        const auto& ceil_divide = [](const auto& a, const auto& b) {
            return (a + b - 1) / b;
        };

        const auto& cnt = (ceil_divide(accumulate(cbegin(nums), cend(nums), 0LL), k) - 1 + MOD) % MOD;
        return ((1LL + cnt) * cnt / 2) % MOD;
    }
};
