// Time:  O(nlogr)
// Space: O(1)

// array
class Solution {
public:
    int minElement(vector<int>& nums) {
        const auto& f = [](int x) {
            int result = 0;
            for (; x ; x /= 10) {
                result += x % 10;
            }
            return result;
        };

        int result = numeric_limits<int>::max();
        for (const auto& x : nums) {
            result = min(result, f(x));
        }
        return result;
    }
};
