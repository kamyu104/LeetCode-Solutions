// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    string getSmallestString(string s) {
        for (int i = 0; i + 1 < size(s); ++i) {
            if (s[i] % 2 != s[i + 1] % 2) {
                continue;
            }
            if (s[i] > s[i + 1]) {
                swap(s[i], s[i + 1]);
                break;
            }
        }
        return s;
    }
};
