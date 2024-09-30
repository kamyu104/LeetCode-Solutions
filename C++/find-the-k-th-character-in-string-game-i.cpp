// Time:  O(1)
// Space: O(1)

// bitmasks
class Solution {
public:
    char kthCharacter(int k) {
        return 'a' + __builtin_popcount(k - 1) % 26;
    }
};
