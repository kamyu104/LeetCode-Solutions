// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
    public:
        int minimumTotal(vector<vector<int> > &triangle) {
            const int N = triangle.size();

            for(int i = N - 2; i >= 0; --i) {
                for(int j = 0; j < i + 1; ++j) {
                    triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
                }
            }

            return triangle[0][0];
        }
};
