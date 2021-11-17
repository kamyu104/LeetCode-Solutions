// Time:  O(26 * n) = O(n)
// Space: O(26) = O(1)

class Solution {
public:
    int equalCountSubstrings(string s, int count) {
        int result = 0;
        const int max_l = min(size(unordered_set<char>(cbegin(s), cend(s))), size(s) / count);
        for (int l = 1; l <= max_l; ++l) {
            unordered_map<char, int> cnt;
            for (int i = 0, equal_cnt = 0; i < size(s); ++i) {
                equal_cnt += static_cast<int>(++cnt[s[i]] == count);
                if (i >= count * l) {
                    equal_cnt -= static_cast<int>(cnt[s[i - count * l]]-- == count);
                }
                result += static_cast<int>(equal_cnt == l);
            }
        }
        return result;
    }
};
