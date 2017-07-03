// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        auto min1 = numeric_limits<int>::max();
        auto min2 = numeric_limits<int>::max();
        auto max1 = numeric_limits<int>::min();
        auto max2 = numeric_limits<int>::min();
        auto max3 = numeric_limits<int>::min();
        for (const auto& n: nums) {
            if (n <= min1) {
                min2 = min1;
                min1 = n;
            } else if (n <= min2) {
                min2 = n;
            }
            if (n >= max1) {
                max3 = max2;
                max2 = max1;
                max1 = n;
            } else if (n >= max2) {
                max3 = max2;
                max2 = n;
            } else if (n >= max3) {
                max3 = n;
            }
        }
        return max(min1 * min2 * max1, max1 * max2 * max3);
    }
};

