// Time:  O(n)
// Space: O(1)

// string
class Solution {
public:
    int countRotations(string s, int k) {
        int total = 0;
        for (int i = 0; i < size(s); ++i) {
            if (s[i] == s[(i + 1) % size(s)]) {
                ++total;
            }
        }
        return total - 1 == k ? total : (total == k ? size(s) - total : 0);
    }
};
