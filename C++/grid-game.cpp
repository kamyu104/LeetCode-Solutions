// Time:  O(m * n)
// Space: O(1)

class Solution {
public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        for (int d = 0; d < 2; ++d) {
            reverse(begin(word), end(word));
            for (int transposed = 0; transposed < 2; ++transposed) {
                for (int i = 0; i < get_r(board, transposed); ++i) {
                    auto it = begin(word);
                    bool matched = true;
                    for (int j = 0; j < get_c(board, transposed); ++j) {
                        const char c = get_val(board, i, j, transposed);
                        if (c == '#') {
                            if (it == end(word) && matched) {
                                return true;
                            }
                            it = begin(word);
                            matched = true;
                            continue;
                        }
                        if (!matched) {
                            continue;
                        }
                        matched = it != end(word) && (c == (*it++) || c == ' ');
                    }
                    if (it == end(word) && matched) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

private:
    int get_r(const vector<vector<char>>& mat, bool transposed) {
        return !transposed ? size(mat) : size(mat[0]);
    }
                                            
    int get_c(const vector<vector<char>>& mat, bool transposed) {
        return !transposed ? size(mat[0]) : size(mat);
    }
                                 
    int get_val(const vector<vector<char>>& mat, int i, int j, bool transposed) {
        return !transposed ? mat[i][j] : mat[j][i];
    }
};
