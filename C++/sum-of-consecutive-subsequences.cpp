// Time:  O(n)
// Space: O(n)

// combinatorics, prefix sum, freq table, dp
class Solution {
public:
    int getSum(vector<int>& nums) {
        static const int MOD = 1e9 + 7;

        const auto& count = [&](int d) {
            int result = 0;
            unordered_map<int, int> cnt, prefix;
            for (const auto& x : nums) {
                const int64_t c = (cnt[x - d] + 1) % MOD;
                cnt[x] = (cnt[x] + c) % MOD;
                const int total = (prefix[x - d] + (x * c) % MOD) % MOD;
                prefix[x] = (prefix[x] + total) % MOD;
                result = (result + total) % MOD;
            }
            return result;
        };
    
        return ((count(+1) + count(-1)) % MOD - accumulate(cbegin(nums), cend(nums), 0, [](const auto& accu, const auto& x) {
            return (accu + x) % MOD;
        }) % MOD + MOD) % MOD;
    }
};
