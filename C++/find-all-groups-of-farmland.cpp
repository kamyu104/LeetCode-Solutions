// Time:  O(m * n)
// Space: O(1)

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> result;
        for (int i = 0; i < size(land); ++i) {
            for (int j = 0; j < size(land[0]); ++j) {
                if (land[i][j] != 1) {
                    continue;
                }
                int ni = i, nj = j;
                while (ni + 1 < size(land) && land[ni + 1][j]) {
                    ++ni;
                }
                while (nj + 1 < size(land[0]) && land[i][nj + 1]) {
                    ++nj;
                }
                for (int r = i; r <= ni; ++r) {
                    for (int c = j; c <= nj; ++c) {
                        land[r][c] = -1;
                    }
                }
                result.push_back({i, j, ni, nj});
            }
        }
        return result;
    }
};
