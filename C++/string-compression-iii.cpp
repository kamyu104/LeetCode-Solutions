// Time:  O(n)
// Space: O(1)

// string
class Solution {
public:
    string compressedString(string word) {
        string result;
        for (int i = 0, cnt = 0; i < size(word); ++i) {
            ++cnt;
            if (cnt == 9 || (i + 1 == size(word) || word[i + 1] != word[i])) {
                result.push_back('0' + cnt);
                result.push_back(word[i]);
                cnt = 0;
            }
        }
        return result;
    }
};
