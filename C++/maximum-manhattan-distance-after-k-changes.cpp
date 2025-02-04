// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    int maxDistance(string s, int k) {
        int result = 0;
        for (int i = 0, x = 0, y = 0; i < size(s); ++i) {
            if (s[i] == 'E') {
                ++x;
            } else if (s[i] == 'W') {
                --x;
            } else if (s[i] == 'N') {
                ++y;
            } else if (s[i] == 'S') {
                --y;
            }
            result = max(result, min(abs(x) + abs(y) + 2 * k, i + 1));
        }
        return result;
    }
};
