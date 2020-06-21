// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int, vector<int>> lookup;
        for (int i = rains.size() - 1; i >= 0; --i) {
            lookup[rains[i]].emplace_back(i);
        }
        vector<int> result;
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for (int i = 0; i < rains.size(); ++i) {
            if (rains[i]) {
                if (lookup[rains[i]].size() >= 2) {
                    lookup[rains[i]].pop_back();
                    min_heap.emplace(lookup[rains[i]].back());
                }
                result.emplace_back(-1);
            } else if (!min_heap.empty()) {
                int j = min_heap.top(); min_heap.pop();
                if (j < i) {
                    return {};
                }
                result.emplace_back(rains[j]);
            } else {
                result.emplace_back(1);
            }
        }
        return min_heap.empty() ? result : vector<int>();
    }
};
