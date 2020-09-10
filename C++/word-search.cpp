// Time:  O(m * n * 4 * 3^(l - 1)) ~= O(m * n * 3^l), l is the length of the word
// Space: O(l)

class Solution {
    public:
        bool exist(vector<vector<char> > &board, string word) {
            const int m = board.size();
            const int n = board.front().size();
            vector<vector<bool> > visited(m, vector<bool> (n, false) );
            for(int i = 0; i < m; ++i) {
                for(int j = 0; j < n; ++j) {
                    if(dfs(board, word, 0,  i, j, visited))
                        return true;
                }
            }

            return false;
        }
    private:
        bool dfs(vector<vector<char> > &board, string word, int index, int i, int j,  vector<vector<bool> > &visited) {
            if(index == word.size()) return true; // terminated condition

            if(i < 0 || j < 0 || i >= board.size() || j >= board.front().size()  // pruning
                    || visited[i][j] || board[i][j] != word[index])
                return false;

            visited[i][j] = true;  // set value
            bool ret = dfs(board, word, index + 1,  i + 1, j, visited) 
                || dfs(board, word, index + 1,  i, j + 1, visited) 
                || dfs(board, word, index + 1,  i - 1, j, visited) 
                || dfs(board, word, index + 1,  i, j - 1, visited);
            visited[i][j] = false; // recover value

            return ret;
        }
};
