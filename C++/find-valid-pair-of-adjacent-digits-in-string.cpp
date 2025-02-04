// Time:  O(n)
// Space: O(1)

// freq table
class Solution {
public:
    string findValidPair(string s) {
        vector<int> cnt(9);
        for (const auto& x : s) {
            ++cnt[x - '1'];
        }
        for (int i = 0; i + 1 < size(s); ++i) {
            if (s[i] != s[i + 1] && cnt[s[i] - '1'] == s[i] - '0' && cnt[s[i + 1] - '1'] == s[i + 1] - '0') {
                return s.substr(i, 2);
            }
        }
        return "";
    }
};
