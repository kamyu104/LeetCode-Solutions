// Time:  O(m * n)
// Space: O(n)

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.empty())
            return 0;

        const int m = matrix.size();
        const int n = matrix.front().size();

        int ans = 0;

        vector<int> H(n, 0);  // height of all ones rectangle include matrix[i][j]
        vector<int> L(n, 0);  // left closed bound of all ones rectangle include matrix[i][j]
        vector<int> R(n, n);  // right open bound of all onces rectangle include matrix[i][j]

        for(int i = 0; i < m; ++i) {
            int left = 0, right = n;
            for(int j = 0; j < n; ++j) {
                if(matrix[i][j] == '1') {
                    ++H[j];  // update height
                    L[j] = max(L[j], left); // update left bound
                }
                else {
                    left = j + 1;
                    H[j] = L[j] = 0;
                    R[j] = n;
                }
            }

            for(int j = n - 1; j >= 0; --j) {
                if(matrix[i][j] == '1') {
                    R[j] = min(R[j], right);  // update right bound
                    ans = max(ans, H[j] * (R[j] - L[j]));
                }
                else {
                    right = j;
                }
            }
        }

        return ans;
    }
};
