// Time:  O(n)
// Space: O(1)

// math
class Solution {
public:
    int averageValue(vector<int>& nums) {
        int total = 0, cnt = 0;
        for (const auto& x : nums) {
            if (x % 6) {
                continue;
            }
            total += x;
            ++cnt;
        }
        return cnt ? total / cnt : 0;
    }
};
