// Time:  O(n)
// Space: O(1)

// math
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int curr = 0, cnt = 0;
        for (const auto& x : moves) {
            if (x == 'L') {
                --curr;
            } else if (x == 'R') {
                ++curr;
            } else {
                ++cnt;
            }
        }
        return abs(curr) + cnt;
    }
};
