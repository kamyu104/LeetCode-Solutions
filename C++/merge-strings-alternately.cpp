// Time:  O(m + n)
// Space: O(1)

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;
        for (int i = 0; i < size(word1) || i < size(word2); ++i) {
            if (i < size(word1)) {
                result.push_back(word1[i]);
            }
            if (i < size(word2)) {
                result.push_back(word2[i]);
            }
        }
        return result;
    }
};
