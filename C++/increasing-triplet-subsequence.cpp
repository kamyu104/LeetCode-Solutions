// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min = numeric_limits<int>::max(), a = numeric_limits<int>::max(), b = numeric_limits<int>::max();
        for (const auto& c : nums) {
            if (min >= c) {
                min = c;
            } else if (b >= c) {
                a = min, b = c;
            } else {  // a < b < c
                return true;
            }
        }
        return false;
    }
};
