// Time:  O(1)
// Space: O(1)

// math
class Solution {
public:
    int passThePillow(int n, int time) {
        return n - abs((n - 1) - (time % (2 * (n - 1))));
    }
};
