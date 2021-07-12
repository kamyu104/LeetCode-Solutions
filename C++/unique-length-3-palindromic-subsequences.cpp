// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first(26, size(s));
        vector<int> last(26, -1);
        for (int i = 0; i < size(s); ++i) {
            first[s[i] - 'a'] = min(first[s[i] - 'a'], i);
            last[s[i] - 'a'] = max(last[s[i] - 'a'], i);
        }
        int result = 0;
        for (int i = 0; i < 26; ++i) {
            if (first[i] < last[i]) {
                result += size(unordered_set<char>(cbegin(s) + first[i] + 1, cbegin(s) + last[i]));
            }
        }
        return result;
    }
};
