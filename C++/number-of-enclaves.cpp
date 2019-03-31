// Time:  O(m * n)
// Space: O(m * n)

class Solution {
public:
    int numEnclaves(vector<vector<int>>& A) {
        for (int i = 0; i < A.size(); ++i) {
            dfs(&A, i, 0);
            dfs(&A, i, A[0].size() - 1);
        }
        for (int j = 1; j < A[0].size() - 1; ++j) {
            dfs(&A, 0, j);
            dfs(&A, A.size() - 1, j);
        }
        return accumulate(A.cbegin(), A.cend(), 0,
                          [](int sum, const vector<int>& row) {
                              return sum + accumulate(row.cbegin(), row.cend(), 0);
                          });
    }

private:
    void dfs(vector<vector<int>> *A, int i, int j) {
        static const vector<pair<int, int>> directions{{0, 1}, {1, 0},
                                                       {0, -1}, {-1, 0}};
        if (!(0 <= i && i < A->size() &&
              0 <= j && j < (*A)[0].size() &&
              (*A)[i][j])) {
            return;
        }
        (*A)[i][j] = 0;
        for (const auto& d : directions) {
            dfs(A, i + d.first, j + d.second);
        }
    }
};
