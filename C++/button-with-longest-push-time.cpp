// Time:  O(n)
// Space: O(1)

// array
class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int mx = events[0][1];
        int idx = events[0][0];
        for (int i = 1; i < size(events); ++i) {
            const int diff = events[i][1] - events[i - 1][1];
            if (diff > mx || (diff == mx && events[i][0] < idx)) {
                mx = diff;
                idx = events[i][0];
            }
        }
        return idx;
    }
};
