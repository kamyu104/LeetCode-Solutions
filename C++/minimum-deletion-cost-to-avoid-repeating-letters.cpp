// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int result = 0, accu = 0, max_cost = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (i && s[i] != s[i - 1]) {
                result += accu - max_cost;
                accu = max_cost = 0;
            }
            accu += cost[i];
            max_cost = max(max_cost, cost[i]);
        }
        result += accu - max_cost;
        return result;
    }
};
