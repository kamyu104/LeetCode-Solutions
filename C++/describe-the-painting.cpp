// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        unordered_map<int, int64_t> counts;
        for (const auto& s : segments) {
            counts[s[0]] += s[2];
            counts[s[1]] -= s[2];
        }
        vector<pair<int, int64_t>> points(cbegin(counts), cend(counts));
        sort(begin(points), end(points));

        vector<vector<long long>> result;
        int64_t overlap = 0, prev = 0;
        for (const auto& [curr, cnt] : points) {
            if (overlap) {
                result.push_back({prev, curr, overlap});
            }
            overlap += cnt;
            prev = curr;
        }
        return result;
    }
};
