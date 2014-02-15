// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int> > &matrix) {
            const int m = matrix.size();
            vector<int> ans;
            if(m == 0) return ans;

            const int n = matrix.front().size();
            enum Action {RIGHT, DOWN, LEFT, UP};
            Action action = RIGHT;
            for(int i = 0, j = 0, begini = 0, beginj = 0, endi = m, endj = n, cnt = 0, total = m * n; cnt < total; ++cnt) {
                ans.push_back(matrix[i][j]);

                switch(action) {
                    case RIGHT:
                        if(j + 1 < endj) ++j;
                        else action = DOWN, ++begini, ++i;
                        break;
                    case DOWN:
                        if(i + 1 < endi) ++i;
                        else action = LEFT, --endj, --j;
                        break;
                    case LEFT:
                        if(j - 1 >= beginj) --j;
                        else action = UP, --endi, --i;
                        break;
                    case UP:
                        if(i - 1 >= begini) --i;
                        else action = RIGHT, ++beginj, ++j;
                        break;
                    default:
                        break;
                }
            }
            return ans;
        }
};
