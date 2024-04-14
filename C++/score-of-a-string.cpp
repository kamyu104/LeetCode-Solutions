// Time:  O(n)
// Space: O(1)

// string
class Solution {
public:
    int scoreOfString(string s) {
        int result = 0;
        for (int i = 0; i + 1 < size(s); ++i) {
            result += abs(s[i + 1] - s[i]);
        }
        return result;
    }
};
