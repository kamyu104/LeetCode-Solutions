// Time:  O(m * n)
// Space: O(m * n)

// hash table
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, pair<int, int>> lookup;
        for (int i = 0; i < size(mat); ++i) {
            for (int j = 0; j < size(mat[0]); ++j) {
                lookup[mat[i][j]] = {i, j};
            }
        }
        vector<int> row(size(mat)), col(size(mat[0]));
        for (int idx = 0; idx < size(arr); ++idx) {
            const auto& [i, j] = lookup[arr[idx]];
            ++row[i];
            ++col[j];
            if (row[i] == size(mat[0]) || col[j] == size(mat)) {
                return idx;
            }
        }
        return -1;
    }
};
