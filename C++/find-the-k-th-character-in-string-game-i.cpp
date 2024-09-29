// Time:  O(1)
// Space: O(1)

// math
class Solution {
public:
    char kthCharacter(int k) {
        return 'a' + __builtin_popcount(k - 1);
    }
};
