// Time:  O(n)
// Space: O(1)

// two pointers, sliding window
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int result = 0;
        for (int i = 0, curr = 0; i < size(startTime) + 1; ++i) {
            curr += (i != size(startTime) ? startTime[i] : eventTime) - (i - 1 >= 0 ? endTime[i - 1] : 0);
            result = max(result, curr);
            if (i - k >= 0) {
                curr -= startTime[i - k] - (i - k - 1 >= 0 ? endTime[i - k - 1] : 0);
            }
        }
        return result;
    }
};
