// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(begin(events), end(events));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        int result = 0, best = 0;
        for (int i = 0; i < size(events); ++i) {
            min_heap.emplace(events[i][1], events[i][2]);
            while (!empty(min_heap) && min_heap.top().first < events[i][0]) {
                best = max(best, min_heap.top().second); min_heap.pop();
            }
            result = max(result, best + events[i][2]);
        }
        return result;
    }
};
