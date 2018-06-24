// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        vector<pair<double, int>> workers;
        for (int i = 0; i < quality.size(); ++i) {
            workers.emplace_back(static_cast<double>(wage[i]) / quality[i],
                                 quality[i]);
        }
        sort(workers.begin(), workers.end());
        auto result = numeric_limits<double>::max();
        auto sum = 0.0;
        priority_queue<int> max_heap;
        for (const auto& worker: workers) {
            sum += worker.second;
            max_heap.emplace(worker.second);
            if (max_heap.size() > K) {
                sum -= max_heap.top(), max_heap.pop();
            }
            if (max_heap.size() == K) {
                result = min(result, sum * worker.first);
            }
        }
        return result;
    }
};
