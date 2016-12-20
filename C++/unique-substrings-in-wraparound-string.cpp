// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> letters(26, 0);
        int result = 0, len = 0;
        for (int i = 0; i < p.length(); ++i) {
            int curr = p[i] - 'a';
            if (i > 0 && p[i - 1] != (curr + 26 - 1) % 26 + 'a') {
                len = 0;
            }
            if (++len > letters[curr]) {
                result += len - letters[curr];
                letters[curr] = len;
            }
        }
        return result;
    }
};
