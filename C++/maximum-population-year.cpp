// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        static const int MIN_YEAR = 1950;
        static const int MAX_YEAR = 2050;
        vector<int> years(MAX_YEAR - MIN_YEAR + 1);
        for (int i = 0; i < size(logs); ++i) {
            ++years[logs[i][0] - MIN_YEAR];
            --years[logs[i][1] - MIN_YEAR];
        }
        int result = 0;
        for (int i = 0; i < size(years); ++i) {
            if (i) {
                years[i] += years[i - 1];
            }
            if (years[i] > years[result]) {
                result = i;
            }
        }
        return result + MIN_YEAR;
    }
};
