// Time:  O(l)
// Space: O(1)

// array
class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int result = -1;
        for (int i = 0, prev = 0, t = 0; i < size(logs); prev = logs[i++][1]) {
            if (logs[i][1] - prev > t) {
                t = logs[i][1] - prev;
                result = logs[i][0];
            } else if (logs[i][1] - prev == t && logs[i][0] < result) {
                result = logs[i][0];
            }
        }
        return result;
    }
};
