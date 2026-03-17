// Time:  O(nlogr)
// Space: O(n)

// prefix sum, sort, two pointers
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> prefix;
        prefix.reserve(size(nums));
        int mx = 0;
        for (const auto& x : nums) {
            mx = max(mx, x);
            prefix.emplace_back(gcd(mx, x));
        }
        ranges::sort(prefix);
        int64_t result = 0;
        for (int left = 0, right = size(nums) - 1; left < right; ++left, --right) {
            result += gcd(prefix[left], prefix[right]);
        }
        return result;
    }
};
