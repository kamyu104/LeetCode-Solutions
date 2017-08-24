// Time:  O(n^3)
// Space: O(n^2)

class Solution {
public:
    int strangePrinter(string s) {
        vector<vector<int>> lookup(s.length(), vector<int>(s.length()));
        return dp(s, 0, s.length() - 1, &lookup);
    }

private:
    int dp(const string& s, int i, int j, vector<vector<int>> *lookup) {
        if (i > j) {
            return 0;
        }
        if (!(*lookup)[i][j]) {
            (*lookup)[i][j] = dp(s, i, j - 1, lookup) + 1;
            for (int k = i; k < j; ++k) {
                if (s[k] == s[j]) {
                    (*lookup)[i][j] = min((*lookup)[i][j],
                                          dp(s, i, k, lookup) + dp(s, k + 1, j - 1, lookup));
                }
            }
        }
        return (*lookup)[i][j];
    }
};
