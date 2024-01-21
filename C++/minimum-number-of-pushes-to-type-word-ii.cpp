// Time:  O(n)
// Space: O(26)

// freq table, greedy
class Solution {
public:
    int minimumPushes(string word) {
        vector<int> cnt(26);
        for (const auto& x : word) {
            ++cnt[x - 'a'];
        }
        sort(rbegin(cnt), rend(cnt));
        int result = 0;
        for (int i = 0; i < size(cnt); ++i) {
            result += cnt[i] * (i / (9 - 2 + 1) + 1);
        }
        return result;
    }
};
