// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int minOperations(string s) {
        int cnt = 0;
        for (int i = 0; i < size(s); ++i) {
            if (s[i] - '0' == i % 2) {
                ++cnt;
            }
        }
        return min(cnt, int(size(s)) - cnt);
    }
};
