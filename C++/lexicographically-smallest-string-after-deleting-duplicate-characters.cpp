// Time:  O(n + 26)
// Space: O(26)

// freq table, greedy
class Solution {
public:
    string lexSmallestAfterDeletion(string s) {
        vector<int> cnt(26);
        for (const auto& x : s) {
            ++cnt[x - 'a'];
        }
        string result;
        for (int i = 0; i < size(s); ++i) {
            while (!empty(result) && result.back() > s[i] && cnt[result.back() - 'a'] != 1) {
                --cnt[result.back() - 'a'];
                result.pop_back();
            }
            result.push_back(s[i]);
        }
        while (cnt[result.back() - 'a'] != 1) {
            --cnt[result.back() - 'a'];
            result.pop_back();
        }
        return result;
    }
};
