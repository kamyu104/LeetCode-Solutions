// Time:  O(nlogn)
// Space: O(n)

// greedy solution
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return (a[0] != b[0]) ? (a[0] < b[0]) : (b[1] < a[1]);
             });
        vector<int> cnts(intervals.size(), 2);
        int result = 0;
        while (!intervals.empty()) {
            auto start = intervals.back()[0]; intervals.pop_back();
            auto cnt = cnts.back(); cnts.pop_back();
            for (int s = start; s < start + cnt; ++s) {
                for (int i = 0; i < intervals.size(); ++i) {
                    if (cnts[i] && s <= intervals[i][1]) {
                        --cnts[i];
                    }
                }
            }
            result += cnt;
        }
        return result;
    }
};
