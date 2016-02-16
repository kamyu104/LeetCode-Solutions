// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min = numeric_limits<int>::max(), a = numeric_limits<int>::max(), b = numeric_limits<int>::max();
        for (const auto& i : nums) {
            if (min >= i) {
                min = i;
            } else if (b >= i) {
                a = min, b = i;
            } else {
                return true;
            }
        }
        return false;
    }
};
