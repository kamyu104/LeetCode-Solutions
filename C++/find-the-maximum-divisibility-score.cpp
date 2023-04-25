// Time:  O(n * d)
// Space: O(1)

// brute force
class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        vector<int> result = {-1, -1};
        for (const auto& d: divisors) {
            const int curr = accumulate(cbegin(nums), cend(nums), 0, [&](const auto& total, const auto& x) {
                return total + static_cast<int>(x % d == 0);
            });
            if (curr > result[0] || curr == result[0] && d < result[1]) {
                result = {curr, d};
            }
        }
        return result[1];
    }
};
