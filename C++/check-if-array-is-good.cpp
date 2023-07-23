// Time:  O(n)
// Space: O(n)

// freq table
class Solution {
public:
    bool isGood(vector<int>& nums) {
        vector<int> cnt(size(nums));
        for (const auto& x : nums) {
            if (x < size(cnt)) {
                ++cnt[x];
            } else {
                return false;
            }
        }
        return all_of(cbegin(cnt) + 1, cbegin(cnt) + (size(nums) - 1), [](const auto& x) {
            return x == 1;
        });
    }
};
