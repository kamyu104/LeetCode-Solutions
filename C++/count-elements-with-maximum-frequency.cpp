// Time:  O(n)
// Space: O(n)

// freq table
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int mx = 0;
        for (const auto& x : nums) {
            mx = max(mx, ++cnt[x]);
        }
        int result = 0;
        for (const auto& [_, v] : cnt) {
            if (v == mx) {
                result += v;
            }
        }
        return result;
    }
};
