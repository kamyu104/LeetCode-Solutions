// Time:  O(nlogr)
// Space: O(1)

// array
class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        const auto& length = [](int x) {
            int result = 0;
            for (; x; x /= 10) {
                ++result;
            }
            return result;
        };

        const auto& f = [&](int x, int y) {
            return x * static_cast<int>(pow(10, length(y))) + y;
        };

        int mn = numeric_limits<int>::max();
        for (int i = 0; 2 * i < size(nums); ++i) {
            mn = min(mn, f(nums[2 * i], nums[2 * i + 1]));
        }
        return mn;
    }
};
