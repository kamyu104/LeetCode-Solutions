// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int maxPower(string s) {
        int result = 1, count = 1;
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == s[i - 1]) {
                ++count;
            } else {
                count = 1;
            }
            result = max(result, count);
        }
        return result;
    }
};
