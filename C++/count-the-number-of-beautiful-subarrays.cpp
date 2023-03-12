// Time:  O(n)
// Space: O(n)

// freq table, combinatorics
class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int64_t, int> cnt = {{0, 1}};
        int64_t result = 0, curr = 0;
        for (const auto& x : nums) {
            curr ^= x;
            result += cnt[curr]++;
        }
        return result;
    }
};
