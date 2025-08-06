// Time:   O(n)
// Spacee: O(1)

// greedy
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int mn_land = numeric_limits<int>::max();
        for (int i = 0; i < size(landStartTime); ++i) {
            mn_land = min(mn_land, landStartTime[i] + landDuration[i]);
        }
        int mn_water = numeric_limits<int>::max();
        for (int i = 0; i < size(waterStartTime); ++i) {
            mn_water = min(mn_water, waterStartTime[i] + waterDuration[i]);
        }
        int result = numeric_limits<int>::max();
        for (int i = 0; i < size(landStartTime); ++i) {
            result = min(result, max(landStartTime[i], mn_water) + landDuration[i]);
        }
        for (int i = 0; i < size(waterStartTime); ++i) {
            result = min(result, max(waterStartTime[i], mn_land) + waterDuration[i]);
        }
        return result;
    }
};
