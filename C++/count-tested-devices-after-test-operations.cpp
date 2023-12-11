// Time:  O(n)
// Space: O(1)

// simulation
class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int result = 0;
        for (const auto& x : batteryPercentages) {
            if (x > result) {
                ++result;
            }
        }
        return result;
    }
};
