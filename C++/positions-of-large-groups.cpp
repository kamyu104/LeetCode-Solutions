// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> result;
        for (int i = 0, j = 0; j < S.length(); ++j) {
            if (j == S.length() - 1 || S[j] != S[j + 1]) {
                if (j - i + 1 >= 3) {
                    result.emplace_back(vector<int>{i, j});
                }
                i = j + 1;
            }
        }
        return result;
    }
};
