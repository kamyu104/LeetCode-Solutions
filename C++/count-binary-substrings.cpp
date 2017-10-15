// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int countBinarySubstrings(string s) {
        auto result = 0, prev = 0, curr = 1;
        for (int i = 1; i < s.length(); ++i) {
            if (s[i - 1] != s[i]) {
                result += min(prev, curr);
                prev = curr, curr = 1;
            } else {
                ++curr;
            }
        }
        result += min(prev, curr);
        return result;
    }
};
