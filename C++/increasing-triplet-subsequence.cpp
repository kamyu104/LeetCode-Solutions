// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first_min = numeric_limits<int>::max(), second_min = numeric_limits<int>::max();
        for (const auto& i : nums) {
            if (first_min >= i) {
                first_min = i;
            } else if (second_min >= i) {
                second_min = i;
            } else {
                return true;
            }
        }
        return false;
    }
};
