// Time:  O(n)
// Space: O(1)

// string
class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        for (int i = 0; i + 1 < size(s); ++i) {
            if (!(abs(s[i] - s[i + 1]) <= 2)) {
                return false;
            }
        }
        return true;
    }
};
