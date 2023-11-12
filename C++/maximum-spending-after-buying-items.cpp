// Time:  O(m * n * logm)
// Space: O(m)

// greedy, heap
class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        const int m = size(values), n = size(values[0]);
    
        vector<pair<int, int>> pairs(m);
        for (int i = 0; i < m; ++i) {
            pairs[i] = pair(values[i].back(), i);
            values[i].pop_back();
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap(cbegin(pairs), cend(pairs));
        int64_t result = 0;
        for (int64_t d = 1; d <= m * n; ++d) {
            const auto [x, i] = min_heap.top(); min_heap.pop();
            result += x * d;
            if (!empty(values[i])) {
                min_heap.emplace(values[i].back(), i);
                values[i].pop_back();
            }
        }
        return result;
    }
};
