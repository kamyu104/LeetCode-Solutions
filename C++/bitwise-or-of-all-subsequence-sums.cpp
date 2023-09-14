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

// Time:  O(nlogn)
// Space: O(1)
// bit manipulation
class Solution2 {
public:
    long long subsequenceSumOr(vector<int>& nums) {
        uint64_t result = 0, cnt = 0;
        for (int i = 0; i < 64; ++i) {
            cnt >>= 1;
            for (const auto& x : nums) {
                cnt += (static_cast<int64_t>(x) >> i) & 1;
            }
            if (cnt) {
                result |= 1ull << i;
            }
        }
        return result;
    }
};
