// Time:  O(n^2)
// Space: O(1)

// constructive algorithms
class Solution {
public:
    vector<vector<int>> colorRed(int n) {
        vector<vector<int>> result = {{1, 1}};
        for (int i = 2; i <= n; ++i) {
            if (i % 2 == n % 2) {
                for (int j = (i % 4 == n % 4) ? 1 : 3; j <= 2 * i - 1; j += 2) {
                    result.push_back({i, j});
                }
            } else {
                result.push_back({i, (i % 4 == (n - 1) % 4) ? 2 : 1});
            }
        }
        return result;
    }
};
