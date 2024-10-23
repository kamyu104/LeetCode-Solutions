// Time:  O(n + 26)
// Space: O(26)

// freq table, two pointers, sliding window
class Solution {
public:
    long long numberOfSubstrings(string s, int k) {
        int64_t result = 0;
        vector<int> cnt(26);
        for (int right = 0, left = 0; right < size(s); ++right) {
            ++cnt[s[right] - 'a'];
            for (; cnt[s[right] - 'a'] == k; ++left) {
                result += (size(s) - 1) - right + 1;
                --cnt[s[left] - 'a'];
            }
        }
        return result;
    }
};
