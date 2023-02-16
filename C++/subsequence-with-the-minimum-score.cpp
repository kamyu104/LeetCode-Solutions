// Time:  O(n)
// Space: O(n)

// two pointers, dp
class Solution {
public:
    int minimumScore(string s, string t) {
        vector<int> right(size(s), -1);  // right[i]: min removed rightmost index in s[i:]
        int j = size(t) - 1;
        for (int i = size(s) - 1; i >= 0; --i) {
            if (j >= 0 && t[j] == s[i]) {
                --j;
            }
            right[i] = j;
        }
        int result = j + 1;
        int left = 0;  // left at i: max removed leftmost index in s[:i]
        for (int i = 0; i < size(s); ++i) {
            result = max(min(result, right[i] - left + 1), 0);
            if (left < size(t) && t[left] == s[i]) {
                ++left;
            }
        }
        result = min(result, static_cast<int>(size(t)) - left);
        return result;
    }
};
