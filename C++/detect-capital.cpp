// Time:  O(l)
// Space: O(1)

class Solution {
public:
    bool detectCapitalUse(string word) {
        int count = count_if(word.begin(), word.end(), [](char c){ return isupper(c); });
        return count == word.length() || count == 0 || (count == 1 && isupper(word[0]));
    }
};
