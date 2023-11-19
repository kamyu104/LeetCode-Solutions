// Time:  O(n)
// Space: O(1)

// string
class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int i = 0;
        for (; i < min({size(s1), size(s2), size(s3)}); ++i) {
            if (s1[i] != s2[i] || s2[i] != s3[i]) {
                break;
            }
        }
        return i ? size(s1) + size(s2) + size(s3) - 3 * i : -1;
    }
};
