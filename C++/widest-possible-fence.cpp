// Time:  O(n + c^2), c = len(cnt)
// Space: O(c^2)

// freq table
class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        unordered_map<int, int> cnt1;
        for (const auto& x : planks) {
            ++cnt1[x];
        }
        unordered_map<int, int> cnt2(cnt1);
        vector<pair<int, int>> cnt(cbegin(cnt1), cend(cnt1));
        for (int i = 0; i < size(cnt); ++i) {
            const auto& [x, c1] = cnt[i];
            cnt2[x + x] += c1 / 2;
            for (int j = 0; j < i; ++j) {
                const auto& [y, c2] = cnt[j];
                cnt2[x + y] += min(c1, c2);
            }
        }
        int result = 0;
        for (const auto& [_, c] : cnt2) {
            result = max(result, c);
        }
        return result;
    }
};
