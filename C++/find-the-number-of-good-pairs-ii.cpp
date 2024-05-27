// Time:  O(rlogr + n + m)
// Space: O(r)

// number theory, freq table
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int, int64_t> cnt2;
        for (const auto& x : nums2) {
            ++cnt2[k * x];
        }
        vector<int64_t> cnt(ranges::max(nums1) + 1);
        for (const auto& [x, c] : cnt2) {
            for (int i = 1; i * x < size(cnt); ++i) {
                cnt[i * x] += c;
            }
        }
        int64_t result = 0;
        for (const auto& x : nums1) {
            result += cnt[x];
        }
        return result;
    }
};
