// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty()) {
            return 0;
        }
        
        vector<vector<int>> min_cost(2);
        min_cost[0] = costs[0];

        const int n = costs.size();
        for (int i = 1; i < n; ++i) {
            min_cost[i % 2][0] = costs[i][0] +
                                 min(min_cost[(i - 1) % 2][1], min_cost[(i - 1) % 2][2]);
            min_cost[i % 2][1] = costs[i][1] +
                                 min(min_cost[(i - 1) % 2][0], min_cost[(i - 1) % 2][2]);
            min_cost[i % 2][2] = costs[i][2] +
                                 min(min_cost[(i - 1) % 2][0], min_cost[(i - 1) % 2][1]);
        }

        return min(min_cost[(n - 1) % 2][0],
                   min(min_cost[(n - 1) % 2][1], min_cost[(n - 1) % 2][2]));
    }
};

// Time:  O(n)
// Space: O(n)
class Solution2 {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty()) {
            return 0;
        }

        const int n = costs.size();
        for (int i = 1; i < n; ++i) {
            costs[i][0] += min(costs[i - 1][1], costs[i - 1][2]);
            costs[i][1] += min(costs[i - 1][0], costs[i - 1][2]);
            costs[i][2] += min(costs[i - 1][0], costs[i - 1][1]);
        }

        return min(costs[n - 1][0], min(costs[n - 1][1], costs[n - 1][2]));
    }
};
