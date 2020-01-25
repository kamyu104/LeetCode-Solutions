// Time:  O(m * n * log(min(m, n))
// Space: O(m * n)

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        unordered_map<int, vector<int>> lookup;
        for (int i = 0; i < mat.size(); ++i) {
            for (int j = 0; j < mat[0].size(); ++j) {
                lookup[i - j].emplace_back(mat[i][j]);
            }
        }
        for (auto& [_, v] : lookup) {
            sort(v.begin(), v.end());
        }
        for (int i = mat.size() - 1; i >= 0; --i) {
            for (int j = mat[0].size() - 1; j >= 0; --j) {
                mat[i][j] = lookup[i - j].back();
                lookup[i - j].pop_back();
            }
        }
        return mat;
    }
};
