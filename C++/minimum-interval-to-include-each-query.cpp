// Time:  O(nlogn + klogk + klogn)
// space: O(n + k)

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(begin(intervals), end(intervals));
        vector<pair<int, int>> sorted_queries;
        for (int i = 0; i < size(queries); ++i) {
            sorted_queries.emplace_back(queries[i], i);
        }
        sort(begin(sorted_queries), end(sorted_queries));
        using P = pair<int, int>;
        priority_queue<P, vector<P>, greater<P>> min_heap;
        int i = 0;
        vector<int> result(size(queries), -1);
        for (const auto& [q, idx] : sorted_queries) {
            for (; i != size(intervals) && intervals[i][0] <= q; ++i) {
                min_heap.emplace(intervals[i][1] - intervals[i][0] + 1, i);
            }
            while (!empty(min_heap) && intervals[min_heap.top().second][1] < q) {
                min_heap.pop();
            }
            result[idx] = (!empty(min_heap)) ? min_heap.top().first : -1;
        }
        return result;
    }
};
