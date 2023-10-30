// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    int minChanges(string s) {
        int result = 0;
        for (int i = 0; i < size(s); i += 2) {
            result += s[i] != s[i + 1] ? 1 : 0;
        }
        return result;
    }
};
