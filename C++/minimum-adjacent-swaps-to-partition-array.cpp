// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        static const int MOD = 1e9 + 7;
        int result = 0, cnt1 = 0, cnt2 = 0;
        for (const auto& x : nums) {
            if (x < a) {
                result = (result + (cnt1 + cnt2)) % MOD;
            } else if (x <= b) {
                ++cnt1;
                result = (result + cnt2) % MOD;
            } else {
                ++cnt2;
            }
        }
        return result;
    }
};
