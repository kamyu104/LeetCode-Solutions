// Time:  O(1)
// Space: O(1)

// math
class Solution {
public:
    int distinctIntegers(int n) {
        return n >= 2 ? n - 1 : 1;
    }
};
