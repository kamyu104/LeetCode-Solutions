// Time Complexity: O(n!)
// Space Complexity: O(1)

class Solution {
    public:
        void dfs(int row) {
            const int N = chess.size();
            if(row == N) {
                ans++;
                return;
            }

            for(int i = 0; i < N; i++) {
                if(cols[i] == 0 && main_diag[row + i] == 0 && anti_diag[row - i + N] == 0) {
                    cols[i] = main_diag[row + i] = anti_diag[row - i + N] = 1;
                    chess[row] = i;
                    dfs(row + 1);
                    cols[i] = main_diag[row + i] = anti_diag[row - i + N] = 0;
                }
            }
        }

        int totalNQueens(int n) {
            ans = 0;
            cols = vector<int>(n, 0);
            main_diag = vector<int>(2 * n, 0);
            anti_diag = vector<int>(2 * n, 0);
            chess = vector<int>(n, 0);

            dfs(0);

            return ans;
        }

    private:
        int ans;
        vector<int> cols;
        vector<int> main_diag;
        vector<int> anti_diag;
        vector<int> chess;
};
