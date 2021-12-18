// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        const int max_pos = max(startPos, fruits.back()[0]);
        vector<int> cnt(max_pos + 1);
        for (const auto& x : fruits) {
            cnt[x[0]] += x[1];
        }
        vector<int> prefix(1);
        for (int i = 0; i < size(cnt); ++i) {
            prefix.emplace_back(prefix.back() + cnt[i]);
        }
        int result = 0;
        for (int left_dist = 0; left_dist <= min(startPos, k); ++left_dist) {
            const int right_dist = max(k - 2 * left_dist, 0);
            const int left = startPos - left_dist;
            const int right = min(startPos + right_dist, max_pos);
            result = max(result, prefix[right + 1] - prefix[left]);
        }
        for (int right_dist = 0; right_dist <= min(max_pos - startPos, k); ++right_dist) {
            const int left_dist = max(k - 2 * right_dist, 0);
            const int left = max(startPos - left_dist, 0);
            const int right = startPos + right_dist;
            result = max(result, prefix[right + 1] - prefix[left]);
        }
        return result;
    }
};
