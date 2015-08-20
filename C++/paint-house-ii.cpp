// Time:  O(n * k)
// Space: O(k)

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty()) {
            return 0;
        }
        
        vector<vector<int>> min_cost(2, costs[0]);

        const int n = costs.size();
        const int k = costs[0].size();
        for (int i = 1; i < n; ++i) {
            int min_1st = numeric_limits<int>::max(), min_2nd = numeric_limits<int>::max();
            for (int j = 0; j < k; ++j) {
                if (min_1st >= min_cost[(i - 1) % 2][j]) {
                    min_2nd = min_1st;
                    min_1st = min_cost[(i - 1) % 2][j];
                } else {
                    min_2nd = min(min_2nd, min_cost[(i - 1) % 2][j]);
                }
            }
            for (int j = 0; j < k; ++j) {
                const int min_j = (min_cost[(i - 1) % 2][j] != min_1st) ? min_1st : min_2nd;
                min_cost[i % 2][j] = costs[i][j] + min_j;
            }
        }

        return *min_element(min_cost[(n - 1) % 2].begin(), min_cost[(n - 1) % 2].end());
    }
};
