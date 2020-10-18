// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int result = -1;
        vector<int> lookup(26, -1);
        for (int i = 0; i < size(s); ++i) {
            if (lookup[s[i] - 'a'] >= 0) {
                result = max(result, i - lookup[s[i] - 'a'] - 1);
            } else {
                lookup[s[i] - 'a'] = i;
            }
        }
        return result;
    }
};
