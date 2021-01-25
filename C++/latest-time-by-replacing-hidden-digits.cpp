// Time:  O(1)
// Space: O(1)

class Solution {
public:
    string maximumTime(string time) {
        for (int i = 0; i < size(time); ++i) {
            if (time[i] != '?') {
                continue;
            }
            if (i == 0) {
                time[i] = (time[1] <= '3' || time[1] == '?') ? '2' : '1';
            } else if (i == 1) {
                time[i] = (time[0] == '2') ? '3' : '9';
            } else if (i == 3) {
                time[i] = '5';
            } else if (i == 4) {
                time[i] = '9';
            }
        }
        return time;
    }
};
