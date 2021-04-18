// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> result, idx(tasks.size());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        iota(begin(idx), end(idx), 0);
        sort(begin(idx), end(idx), [&](int i, int j) { return tasks[i][0] < tasks[j][0]; });
        for (int64_t i = 0, time = tasks[idx[i]][0]; i < size(idx) || !empty(min_heap);) {
            for (; i < size(idx) && tasks[idx[i]][0] <= time; ++i) {
                min_heap.emplace(tasks[idx[i]][1], idx[i]);
            }
            if (empty(min_heap)) {
                time = tasks[idx[i]][0];
                continue;
            }
            const auto [t, j] = min_heap.top(); min_heap.pop();
            time += t;
            result.emplace_back(j);
        }
        return result;
    }
};
