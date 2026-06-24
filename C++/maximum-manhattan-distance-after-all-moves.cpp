// Time:  O(n)
// Space: O(1)

// simulation
class Solution {
public:
    int maxDistance(string moves) {
        int x = 0, y = 0, cnt = 0;
        for (const auto& c : moves) {
            if (c == 'U') {
                ++y;
            } else if (c == 'D') {
                --y;
            } else if (c == 'L') {
                --x;
            } else if (c == 'R') {
                ++x;
            } else {
                ++cnt;
            }
        }
        return abs(x) + abs(y) + cnt;
    }
};
