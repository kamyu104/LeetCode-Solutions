// Time:  O(1)
// Space: O(1)

// combinatorics
class Solution {
public:
    int countTime(string time) {
        int result = 1;
        if (time[4] == '?') {
            result *= 10;
        }
        if (time[3] == '?') {
            result *= 6;
        }
        if (time[1] == '?' && time[0] == '?') {
            result *= 24;
        } else if (time[1] == '?') {
            result *= time[0] != '2' ? 10 : 4;
        } else if (time[0] == '?') {
            result *= time[1] < '4' ? 3 : 2;
        }
        return result;
    }
};
