// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> result(n + 1);
        for (const auto& booking : bookings) {
            result[booking[0] - 1] += booking[2];
            result[booking[1]] -= booking[2];
        }
        for (int i = 1; i < result.size(); ++i) {
            result[i] += result[i - 1];
        }
        result.pop_back();
        return result;
    }
};
