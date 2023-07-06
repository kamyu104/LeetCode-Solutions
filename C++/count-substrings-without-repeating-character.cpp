// Time:  O(n)
// Space: O(1)

// two pointers, sliding window
class Solution {
public:
    int numberOfSpecialSubstrings(string s) {
        int result = 0, left = 0;
        vector<bool> lookup(26);
        for (int right = 0; right < size(s); ++right) {
            while (lookup[s[right] - 'a']) {
                lookup[s[left++] - 'a'] = false;
            }
            lookup[s[right] - 'a'] = true;
            result += (right - left + 1);
        }
        return result;
    }
};
