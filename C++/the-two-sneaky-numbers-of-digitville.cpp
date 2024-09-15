// Time:  O(n)
// Space: O(1)

// bit manipulation
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        const int n = size(nums) - 2;
        const auto& f = [&](const auto& check) {
            int result = 0;
            for (const auto& x : nums) {
                if (check(x)) {
                    result ^= x;
                }
            }
            for (int i = 0; i < n; ++i) {
                if (check(i)) {
                    result ^= i;
                }
            }
            return result;
        };

        const int x_xor_y = f([](int x) { return true; });
        const int bit = x_xor_y & -x_xor_y;
        return {f([&](int x) { return (x & bit) == 0; }), f([&](int x) { return (x & bit) != 0; })};
    }
};
