// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        vector<pair<double, int>> workers;
        for (int i = 0; i < quality.size(); ++i) {
            workers.emplace_back(static_cast<double>(wage[i]) / quality[i], quality[i]);
        }
        sort(begin(workers), end(workers));
        auto result = numeric_limits<double>::max();
        auto sum = 0.0;
        priority_queue<int> max_heap;
        for (const auto& [ratio, q]: workers) {
            sum += q;
            max_heap.emplace(q);
            if (max_heap.size() > K) {  // keep k smallest q to make sum as small as possible
                sum -= max_heap.top(), max_heap.pop();
            }
            if (max_heap.size() == K) {
                result = min(result, sum * ratio);
            }
        }
        return result;
    }
};
