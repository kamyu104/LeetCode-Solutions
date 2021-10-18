// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool winnerOfGame(string colors) {
        int cnt1 = 0, cnt2 = 0;
        for (int i = 1; i + 1 < size(colors); ++i) {
            if (!(colors[i - 1] == colors[i] && colors[i] == colors[i + 1])) {
                continue;
            }
            if (colors[i] == 'A') {
                ++cnt1;
            } else {
                ++cnt2;
            }
        }
        return cnt1 > cnt2;
    }
};
