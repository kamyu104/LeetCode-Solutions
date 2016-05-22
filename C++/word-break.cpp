// Time:  O(n * l^2), l is the max length of the words.
// Space: O(n)

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        const int n = s.length();

        size_t max_len = 0;
        for (const auto& str: wordDict) {
            max_len = max(max_len, str.length());
        }

        vector<bool> canBreak(n + 1, false);
        canBreak[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int l = 1; l <= max_len && i - l >= 0; ++l) {
                if (canBreak[i - l] && wordDict.count(s.substr(i - l, l))) {
                    canBreak[i] = true;
                    break;
                }
            }
        }

        return canBreak[n];
    }
};
