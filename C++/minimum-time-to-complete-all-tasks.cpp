// Time:  O(nlogn + n * r), r = max(e for _, e in tasks)
// Space: O(r)

// sort, greedy
class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(begin(tasks), end(tasks), [](const auto& x, const auto& y) {
            return x[1] < y[1];
        });
        unordered_set<int> lookup;
        for (const auto& t : tasks) {
            int s = t[0], e = t[1], d = t[2];
            for (int i = s; i <= e; ++i) {
                if (lookup.count(i)) {
                    --d;
                }
            }
            for (int i = e; d > 0; --i) {
                if (lookup.count(i)) {
                    continue;
                }
                lookup.emplace(i);
                --d;
            }
        }
        return size(lookup);
    }
};
