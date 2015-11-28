// Time:  O(n^2)
// Space: O(1)

class Solution {
public:
    /**
     * @param n an integer
     * @return a square matrix
     */
    vector<vector<int>> generateMatrix(int n) {
       vector<vector<int>> matrix(n, vector<int>(n));

       for (int num = 0, left = 0, right = n - 1, top = 0, bottom = n - 1;
            left <= right && top <= bottom;
            ++left, --right, ++top, --bottom) {

            for (int j = left; j <= right; ++j) {
                matrix[top][j] = ++num;
            }
            for (int i = top + 1; i < bottom; ++i) {
                matrix[i][right] = ++num;
            }
            for (int j = right; top < bottom && j >= left; --j) {
                matrix[bottom][j] = ++num;
            }
            for (int i = bottom - 1; left < right && i >= top + 1; --i) {
                matrix[i][left] = ++num;
            }
        }

        return matrix;
    }
};

// Time:  O(n^2)
// Space: O(1)
class Solution2 {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix(n, vector<int>(n));
        enum Action {RIGHT, DOWN, LEFT, UP};
        Action action = RIGHT;
        for (int i = 0, j = 0, cnt = 0, total = n * n; cnt < total;) {
            matrix[i][j] = ++cnt;

            switch (action) {
                case RIGHT:
                    if (j + 1 < n && matrix[i][j + 1] == 0) {
                        ++j;
                    } else {
                        action = DOWN, ++i;
                    }
                    break;
                case DOWN:
                    if (i + 1 < n && matrix[i + 1][j] == 0) {
                        ++i;
                    } else {
                        action = LEFT, --j;
                    }
                    break;
                case LEFT:
                    if (j - 1 >= 0 && matrix[i][j - 1] == 0) {
                        --j;
                    } else {
                        action = UP, --i;
                    }
                    break;
                case UP:
                    if (i - 1 >= 0 && matrix[i - 1][j] == 0) {
                        --i;
                    } else {
                        action = RIGHT, ++j;
                    }
                    break;
                default:
                    break;
            }
        }
        return matrix;
    }
};
