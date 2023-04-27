// Time:  O(nlogn)
// Space: O(n)

// sort, line sweep
class Solution {
public:
    vector<vector<int>> findMaximalUncoveredRanges(int n, vector<vector<int>>& ranges) {
        sort(begin(ranges), end(ranges));
        vector<vector<int>> covered = {{-1, -1}};
        for (const auto& r : ranges) {
            if (covered.back()[1] < r[0]) {
                covered.emplace_back(r);
                continue;
            }
            covered.back()[1] = max(covered.back()[1], r[1]);
        }
        covered.push_back({n, n});
        vector<vector<int>> result;
        for (int i = 1; i < size(covered); ++i) {
            if (covered[i - 1][1] + 1 <= covered[i][0] - 1) {
                result.push_back({covered[i - 1][1] + 1, covered[i][0] - 1});
            }
        }
        return result;
    }
};
