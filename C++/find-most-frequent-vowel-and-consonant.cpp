// Time:  O(n + 26)
// Space: O(26)

// freq table
class Solution {
public:
    int maxFreqSum(string s) {
        unordered_set<char> VOWELS = {'a', 'e', 'i', 'o', 'u'};
        vector<int> cnt(26);
        for (const auto& x : s) {
            ++cnt[x - 'a'];
        }
        int mx1 = 0, mx2 = 0;
        for (int i = 0; i < size(cnt); ++i) {
            if (VOWELS.count(i + 'a')) {
                mx1 = max(mx1, cnt[i]);
            } else {
                mx2 = max(mx2, cnt[i]);
            }
        }
        return mx1 + mx2;
    }
};
