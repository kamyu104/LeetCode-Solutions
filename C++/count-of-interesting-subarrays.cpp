// Time:  O(n)
// Space: O(m)

// freq table, prefix sum
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        long long result = 0;
        int prefix = 0;
        for (const auto& x : nums) {
            if (x % modulo == k) {
                prefix = (prefix + 1) % modulo;
            }
            result += cnt[((prefix - k) % modulo + modulo) % modulo];
            ++cnt[prefix];
        }
        return result;
    }
};
