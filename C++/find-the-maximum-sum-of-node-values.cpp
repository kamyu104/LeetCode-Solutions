// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int64_t result = 0;
        int diff = numeric_limits<int>::max();
        int parity = 0;
        for (const auto& x : nums) {
            const auto y = x ^ k;
            result += max(x, y);
            parity ^= x < y ? 1 : 0;
            diff = min(diff, abs(x - y));
        }
        return result - parity * diff;
    }
};
