// Time:  O(n + m)
// Space: O(1)

// two pointers
class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        vector<vector<int>> result;
        for (int i = 0, j = 0; i != size(series1) || j != size(series2); ){
            if (j == size(series2) || (i != size(series1) && series1[i][0] < series2[j][0])) {
                result.push_back({series1[i][0], series1[i][1] + (j != size(series2) ? series2[j][1] : 0)});
                ++i;
            } else if (i == size(series1) || series2[j][0] < series1[i][0]) {
                result.push_back({series2[j][0], series2[j][1] + (i != size(series1) ? series1[i][1] : 0)});
                ++j;
            } else {
                result.push_back({series1[i][0], series1[i][1] + series2[j][1]});
                ++i, ++j;
            }
        }
        return result;
    }
};
