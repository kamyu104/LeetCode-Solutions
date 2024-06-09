// Time:  O(1)
// Space: O(1)

// math
class Solution {
public:
    int numberOfChild(int n, int k) {
        const int q = k / (n - 1), r = k % (n - 1);
        return (q & 1) == 0 ? r : (n - 1) - r;
    }
};
