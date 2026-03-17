// Time:  O(n)
// Space: O(n)

// freq table, greedy
class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> cnt;
        for (const auto& x : nums1) {
            ++cnt[x];
        }
        for (const auto& x : nums2) {
            --cnt[x];
        }
        int result = 0;
        for (const auto& [_, c] : cnt) {
            if (c % 2) {
                return -1;
            }
            if (c / 2 > 0) {
                result += c / 2;
            }
        }
        return result;
    }
};
