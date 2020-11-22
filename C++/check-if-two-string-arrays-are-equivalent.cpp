// Time:  O(n), n is the total length of word1 and word2
// Space: O(1)

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int idx1 = 0, idx2 = 0, arrIdx1 = 0, arrIdx2 = 0;
        while (arrIdx1 < size(word1) && arrIdx2 < size(word2)) {
            if (word1[arrIdx1][idx1] != word2[arrIdx2][idx2]) {
                break;
            }
            ++idx1;
            if (idx1 == size(word1[arrIdx1])) {
                idx1 = 0;
                ++arrIdx1;
            }
            ++idx2;
            if (idx2 == size(word2[arrIdx2])) {
                idx2 = 0;
                ++arrIdx2;
            }
        }
        return arrIdx1 == size(word1) && arrIdx2 == size(word2);
    }
};
