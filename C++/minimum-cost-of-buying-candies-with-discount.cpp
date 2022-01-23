// Time:  O(nlogn)
// Space: O(1)

// greedy
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(rbegin(cost), rend(cost));
        int result = 0;
        for (int i = 0; i < size(cost); ++i) {
            if (i % 3 == 2) {
                continue;
            }
            result += cost[i];
        }
        return result;
    }
};
