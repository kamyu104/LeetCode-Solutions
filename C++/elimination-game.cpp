// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    int lastRemaining(int n) {
        int start = 1;

        for (int step = 2, direction = 1; n > 1;
             n /= 2, step *= 2, direction *= -1) {

            start += direction * (step * (n / 2) - step / 2);
        }

        return start;
    }
};
