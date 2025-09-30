// Time:  O(n + 26)
// Space: O(26)

// freq table
class Solution {
public:
    string majorityFrequencyGroup(string s) {
        unordered_map<int, int> cnt;
        for (const auto& x : s) {
            ++cnt[x];
        }
        unordered_map<int, string> cnt2;
        for (const auto& [x, c] : cnt) {
            cnt2[c].push_back(x);
        }
        int k = 0;
        for (const auto& [c, s] : cnt2) {
            if (k == 0 || pair(static_cast<int>(size(cnt2[k])), k) < pair(static_cast<int>(size(s)), c)) {
                k = c;
            }
        }
        return cnt2[k];
    }
};
