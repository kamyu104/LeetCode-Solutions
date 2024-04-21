// Time:  O(n + 26)
// Space: O(26)

// hash table
class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lookup1(26, size(word));
        vector<int> lookup2(26, -1);
        for (int i = 0; i < size(word); ++i) {
            if (islower(word[i])) {
                lookup1[word[i] - 'a'] = i;
            } else if (lookup2[word[i] - 'A'] == -1) {
                lookup2[word[i] - 'A'] = i;
            }
        }
        int result = 0;
        for (int i = 0; i < 26; ++i) {
            if (lookup1[i] < lookup2[i]) {
                ++result;
            }
        }
        return result;
    }
};
