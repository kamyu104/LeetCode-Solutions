// Time:  O(n)
// Space: O(1)

// bit manipulation
class Solution {
public:
    long long subsequenceSumOr(vector<int>& nums) {
        uint64_t result = 0, prefix = 0;
        for (const auto& x : nums) {
            prefix += x;
            result |= x | prefix;
        }
        return result;
    }
};
