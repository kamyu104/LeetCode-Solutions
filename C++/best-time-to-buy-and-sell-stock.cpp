// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) {
            return 0;
        }

        int hold1 = numeric_limits<int>::min();
        int release1 = numeric_limits<int>::min();

        for (const auto& p : prices) {
            hold1 = max(hold1, -p);
            release1 = max(release1, hold1 + p);
        }

        return release1;
    }
};
