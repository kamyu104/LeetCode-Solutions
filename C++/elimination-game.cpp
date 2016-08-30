// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int lastRemaining(int n) {
        int start = 1;

        for (int i = n, step = 2, direction = 1; i > 1;
             i /= 2, step *= 2, direction *= -1) {

            start += direction * (step * (i / 2) - step / 2);
        }

        return start;
    }
};
