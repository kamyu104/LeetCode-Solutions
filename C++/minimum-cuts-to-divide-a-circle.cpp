// Time:  O(1)
// Space: O(1)

// math
class Solution {
public:
    int numberOfCuts(int n) {
        return n == 1 ? 0 : (n % 2 ? n : n / 2);
    }
};
