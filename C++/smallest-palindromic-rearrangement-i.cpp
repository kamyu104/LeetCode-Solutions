// Time:  O(n + 26)
// Space: O(26)

// freq table, counting sort, greedy
class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> cnt(26);
        for (int i = 0; i < size(s) / 2; ++i) {
            ++cnt[s[i] - 'a'];
        }
        string result(size(s), 0);
        int l = 0;
        for (int i = 0; i < size(cnt); ++i) {
            for (int _ = 0; _ < cnt[i]; ++_) {
                result[l++] = 'a' + i;
            }
        }
        if (size(s) % 2) {
            result[l++] = s[size(s) / 2];
        }
        for (int i = l - 1 - size(s) % 2; i >= 0; --i) {
            result[l++] = result[i];
        }
        return result;
    }
};
