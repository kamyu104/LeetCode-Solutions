// Time:  O(nlogn + mlogm)
// Space: O(1)

// sort, two pointers
class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(begin(buses), end(buses));
        sort(begin(passengers), end(passengers));
        int cnt = 0, j = 0;
        for (int i = 0; i < size(buses) - 1; ++i) {
            while (j < size(passengers) && passengers[j] <= buses[i]) {
                ++cnt;
                ++j;
            }
            cnt = max(cnt-capacity, 0);
        }
        j -= max(cnt - capacity, 0);
        cnt = min(cnt, capacity);
        while (j < size(passengers) && passengers[j] <= buses.back() && cnt + 1 <= capacity) {
            ++cnt;
            ++j;
        }
        if (cnt < capacity && (j - 1 < 0 || passengers[j - 1] != buses.back())) {
            return buses.back();
        }
        --j;
        for (; j; --j) {
            if (passengers[j] - 1 != passengers[j - 1]) {
                break;
            }
        }
        return passengers[j] - 1;
    }
};
