// Time:  O(logn) = O(1)
// Space: O(1)

class Solution {
public:
    bool isUgly(int num) {
        if (num == 0) {
            return false;
        }
        for (const auto& i : {2, 3, 5}) {
            while (num % i == 0) {
                num /= i;
            }
        }
        return num == 1;
    }
};
