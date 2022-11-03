// Time:  O(n)
// Space: O(s), s is the value of space

// freq table
class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int, int> cnt;
        int mx = 0;
        for (const auto& x : nums) {
            mx = max(mx, ++cnt[x % space]);
        }
        int result = numeric_limits<int>::max();
        for (const auto& x : nums) {
            if (cnt[x % space] == mx) {
                result = min(result, x);
            }
        }
        return result;
    }
};
