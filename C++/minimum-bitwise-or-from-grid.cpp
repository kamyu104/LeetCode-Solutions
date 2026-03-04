// Time:  O(nlogr), r = max(nums)
// Space: O(1)

// bitmasks, greedy
class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int mx = 0;
        for (const auto& row : grid) {
            for (const auto& x : row) {
                mx = max(mx, x);
            }
        }
        int result = 0;
        for (int i = bit_width(static_cast<uint32_t>(mx)) - 1; i >= 0; --i) {
            if (any_of(cbegin(grid), cend(grid), [&](const auto& row) {
                return all_of(cbegin(row), cend(row), [&](const auto& x) {
                    return (x & (result | ((1 << i) - 1))) != x;
                });
            })) {
                result |= 1 << i;
            }
        }
        return result;
    }
};
