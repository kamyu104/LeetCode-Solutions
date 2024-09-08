// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int64_t result = 0;
        int mx = 0;
        for (const auto& x : nums) {
            result += mx;
            mx = max(mx, x);
        }
        return result;
    }
};
