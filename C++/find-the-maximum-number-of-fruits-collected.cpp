// Time:  O(n^2)
// Space: O(1)

// dp
class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        const int n = size(fruits);

        int result = 0;
        for (int i = 0; i < n; ++i) {
            result += fruits[i][i];
        }
    
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n - (i + 1); ++j) {
                fruits[i][j] = 0;
            }
        }
        for (int i = 1; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                fruits[i][j] += max({fruits[i - 1][j - 1], fruits[i - 1][j], j + 1 < n ? fruits[i - 1][j + 1] : 0});
            }
        }
        result += fruits[n - 2][n - 1];

        for (int j = 0; j < n; ++j) {
            for (int i = j + 1; i < n - (j + 1); ++i) {
                fruits[i][j] = 0;
            }
        }
        for (int j = 1; j < n - 1; ++j) {
            for (int i = j + 1; i < n; ++i) {
                fruits[i][j] += max({fruits[i - 1][j - 1], fruits[i][j - 1], i + 1 < n ? fruits[i + 1][j - 1] : 0});
            }
        }
        result += fruits[n - 1][n - 2]; 

        return result;
    }
};
