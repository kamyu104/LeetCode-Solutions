// Time:  O(n + 26)
// Space: O(26)

// hash table
class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> lookup1(26);
        vector<bool> lookup2(26);
        for (const auto& x : word) {
            if (islower(x)) {
                lookup1[x - 'a'] = true;
            } else {
                lookup2[x - 'A'] = true;
            }
        }
        int result = 0;
        for (int i = 0; i < 26; ++i) {
            if (lookup1[i] == lookup2[i] && lookup2[i] == true) {
                ++result;
            }
        }
        return result;
    }
};
