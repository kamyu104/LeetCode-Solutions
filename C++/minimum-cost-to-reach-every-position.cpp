// Time:  O(n)
// Space: O(1)

// prefix sum
class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        for (int i = 1; i < size(cost); ++i) {
            cost[i] = min(cost[i], cost[i - 1]);
        }
        return cost;
    }
};
