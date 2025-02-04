// Time:  O(n)
// Space: O(1)

// two pointers, sliding window
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        startTime.emplace_back(eventTime);
        endTime.emplace(begin(endTime), 0);
        int result = 0;
        for (int i = 0, curr = 0; i < size(startTime); ++i) {
            curr += startTime[i] - endTime[i];
            result = max(result, curr);
            if (i - k >= 0) {
                curr -= startTime[i - k] - endTime[i - k];
            }
        }
        return result;
    }
};
