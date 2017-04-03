// Time:  O(min(a, b))
// Space: O(1)

class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a == b) {
            return -1;
        }
        return max(a.length(), b.length());
    }
};
