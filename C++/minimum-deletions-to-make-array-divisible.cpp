// Time:  O(n + m + logr), r is max(numsDivide)
// Space: O(1)

// math, gcd
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        const int g = accumulate(cbegin(numsDivide), cend(numsDivide), numsDivide[0],
                                 [](const auto& total, const auto& x) {
                                     return gcd(total, x);
                                 });
        int mn = numeric_limits<int>::max();
        for (const auto& x : nums) {
            if (g % x == 0) {
                mn = min(mn, x);
            }
        }
        return mn != numeric_limits<int>::max() ? accumulate(cbegin(nums), cend(nums), 0,
                                                             [&](const auto& total, const auto& x) {
                                                                 return total + static_cast<int>(x < mn);
                                                             }): -1;
    }
};
