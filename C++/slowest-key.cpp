// Time:  O(n)
// Space: O(1)

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char result = 'a';
        vector<int> lookup(26);
        for (int i = 0; i < size(keysPressed); ++i) {
            auto c = keysPressed[i];
            lookup[c - 'a'] = max(lookup[keysPressed[i] - 'a'],
                                  releaseTimes[i] - (i > 0 ? releaseTimes[i - 1] : 0));
            if (lookup[c - 'a'] > lookup[result - 'a'] ||
                (lookup[c - 'a'] == lookup[result - 'a'] && c > result)) {
                result = c;
            }
        }
        return result;
    }
};
