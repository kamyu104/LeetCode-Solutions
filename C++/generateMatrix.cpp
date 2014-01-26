// Time Complexity: O(n^2)
// Space Complexity: O(n^2)

class Solution {
    public:
        vector<vector<int> > generateMatrix(int n) {
            vector<vector<int> > v(n, vector<int>(n, 0));
            enum Action {RIGHT, DOWN, LEFT, UP};
            Action action = RIGHT;
            for(int i = 0, j = 0, cnt = 0, total = n * n; cnt < total;) {
                v[i][j] = ++cnt;

                switch(action) {
                    case RIGHT:
                        if(j + 1 < n && v[i][j + 1] == 0) ++j;
                        else action = DOWN, ++i;
                        break;
                    case DOWN:
                        if(i + 1 < n && v[i + 1][j] == 0) ++i;
                        else action = LEFT, --j;
                        break;
                    case LEFT:
                        if(j - 1 >= 0 && v[i][j - 1] == 0) --j;
                        else action = UP, --i;
                        break;
                    case UP:
                        if(i - 1 >= 0 && v[i - 1][j] == 0) --i;
                        else action = RIGHT, ++j;
                        break;
                    default:
                        break;
                }
            }
            return v;
        }
};
