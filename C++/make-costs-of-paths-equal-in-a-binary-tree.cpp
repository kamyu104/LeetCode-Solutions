// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int result = 0;
        for (; n != 1; n -= 2) {
            result += abs(cost[n - 2] - cost[n - 1]);
            cost[(n - 2) / 2] += max(cost[n - 2], cost[n - 1]);
        }
        return result;
    }
};
