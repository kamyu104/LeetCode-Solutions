// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int uniqueLetterString(string S) {
        static const int M = 1e9 + 7;
        int result = 0;
        vector<vector<int>> index(26, vector<int>(2, -1));
        for (int i = 0; i < S.length(); ++i) {
            int c = S[i] - 'A';
            result = (result + (i - index[c][1]) *
                               (index[c][1] - index[c][0])) % M;
            index[c][0] = index[c][1];
            index[c][1] = i;
        }
        for (int c = 0; c < 26; ++c) {
            result = (result + (S.length() - index[c][1]) *
                               (index[c][1] - index[c][0])) % M;
        }
        return result;
    }
};
