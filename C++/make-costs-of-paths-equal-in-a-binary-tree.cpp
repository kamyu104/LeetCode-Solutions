// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int result = 0;
        for (int i = n / 2 - 1; i >= 0; --i) {
            result += abs(cost[2 * i + 1] - cost[2 * i + 2]);
            cost[i] += max(cost[2 * i + 1], cost[2 * i + 2]);
        }
        return result;
    }
};
