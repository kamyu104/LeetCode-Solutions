// Time:  O(nlogn)
// Space: O(1)

// brute force
class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        const auto& reverse = [](int n) {
            int result = 0;
            for (; n; n /= 10) {
                result = result * 10 + n % 10;
            }
            return result;
        };

        for (int x = num / 2; x <= num; ++x) {
            if (x + reverse(x) == num) {
                return true;
            }
        }
        return false;
    }
};
