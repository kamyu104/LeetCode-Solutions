// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int result = 0, mx = 0;
        for (const auto& x : weight) {
            if (x < mx) {
                mx = 0;
                ++result;
            } else {
                mx = x;
            }
        }
        return result;
    }
};
