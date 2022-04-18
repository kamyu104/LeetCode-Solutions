// Time:  O(n)
// Space: O(1)

// array
class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int result = numeric_limits<int>::max();
        for (const auto& x : nums) {
            if (abs(x) < abs(result) || (abs(x) == abs(result) && x > result)) {
                result = x;
            }
        }
        return result;
    }
};
