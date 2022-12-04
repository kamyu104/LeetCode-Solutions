// Time:  O(1)
// Space: O(1)

// math
class Solution {
public:
    int pivotInteger(int n) {
        int x = sqrt((n + 1) * n / 2) + 0.5;
        return x * x == (n + 1) * n / 2 ? x : -1;
    }
};
