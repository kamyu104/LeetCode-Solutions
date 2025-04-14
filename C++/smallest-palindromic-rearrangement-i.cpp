// Time:  O(n)
// Space: O(1)

// counting sort, greedy
class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> cnt(26);
        for (const auto& c : s) {
            ++cnt[c - 'a'];
        }
        string result(size(s), 0);
        int l = 0;
        for (int i = 0; i < size(cnt); ++i) {
            for (int c = 0; c < cnt[i] / 2; ++c) {
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
