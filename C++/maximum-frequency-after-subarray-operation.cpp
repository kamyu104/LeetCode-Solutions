// Time:  O(n)
// Space: O(n)

// freq table
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int result = 0, cnt_k = 0;
        unordered_map<int, int> cnt;
        for (const auto& x : nums) {
            cnt[x] = max(cnt[x] + 1, cnt_k + 1);
            if (x == k) {
                ++cnt_k;
                ++result;
            }
            result = max(result, cnt[x]);
        }
        return result;
    }
};
