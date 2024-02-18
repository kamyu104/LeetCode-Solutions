// Time:  O(n)
// Space: O(1)

// freq table
class Solution {
public:
    string lastNonEmptyString(string s) {
        vector<int> cnt(26);
        for (const auto& x : s) {
            ++cnt[x - 'a'];
        }
        string result;
        const int mx = ranges::max(cnt);
        for (int i = size(s) - 1; i >= 0; --i) {
            if (cnt[s[i] - 'a'] != mx) {
                continue;
            }
            --cnt[s[i] - 'a'];
            result.push_back(s[i]);
        }
        reverse(begin(result), end(result));
        return result;
    }
};
