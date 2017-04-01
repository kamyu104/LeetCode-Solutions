// Time:  O(m * n)
// Space: O(m + n)

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        vector<int> rows = vector<int>(picture.size());
        vector<int> cols = vector<int>(picture[0].size());

        for (int i = 0; i < picture.size(); ++i) {
            for (int j = 0; j < picture[0].size(); ++j) {
                rows[i] += picture[i][j] == 'B';
                cols[j] += picture[i][j] == 'B';
            }
        }

        int result = 0;
        for (int i = 0; i < picture.size(); ++i) {
            if (rows[i] == 1) {
                for (int j = 0; j < picture[0].size() && rows[i] > 0; ++j) {
                    result += picture[i][j] == 'B' && cols[j] == 1;
                }
            }
        }
        return result;
    }
};
