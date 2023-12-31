// Time:  O(n)
// Space: O(1)

// bit manipulation
class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int cnt = 0;
        for (const auto& x : nums) {
            if (x % 2) {
                continue;
            }
            if (++cnt == 2) {
                return true;
            }
        }
        return false;
    }
};
