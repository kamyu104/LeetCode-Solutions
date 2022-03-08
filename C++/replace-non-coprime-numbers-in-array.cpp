// Time:  O(nlogm), m is the max of nums
// Space: O(1)

// math, stack
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> result;
        for (auto x : nums) {
            for (;;) {
                const int g = gcd(!empty(result) ? result.back() : 1, x);
                if (g == 1) {
                    break;
                }
                x *= result.back() / g;
                result.pop_back();
            }
            result.emplace_back(x);
        }
        return result;
    }
};
