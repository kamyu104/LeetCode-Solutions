// Time:  O(m * n)
// Space: O(m * n)

class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        vector<int> rows = vector<int>(picture.size());
        vector<int> cols = vector<int>(picture[0].size());

        unordered_map<string,int> lookup;
        vector<string> srows;
        for (int i = 0; i < picture.size(); ++i) {
            string s;
            for (int j = 0; j < picture[0].size(); ++j) {
                if (picture[i][j] == 'B') {
                    ++rows[i];
                    ++cols[j];
                }
                s.push_back(picture[i][j]);
            }
            ++lookup[s];
            srows.emplace_back(move(s));
        }

        int result = 0;
        for (int i = 0; i < picture.size(); ++i) {
            if (rows[i] == N && lookup[srows[i]] == N) {
                for (int j = 0; j < picture[0].size(); ++j) {
                     result += picture[i][j] == 'B' && cols[j] == N;
                }
            }
        }
        return result;
    }
};
