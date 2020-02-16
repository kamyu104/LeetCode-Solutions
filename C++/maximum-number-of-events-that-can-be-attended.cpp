// Time:  O(r + nlogn), r is the max end day of events
// Space: O(n)

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), greater<vector<int>>());
        const auto max_day = (*max_element(events.cbegin(), events.cend(),
                                           [](const auto& a, const auto& b) {
                                               return a[1] < b[1];
                                           }))[1];
        priority_queue<int, vector<int>, greater<int>> min_heap;
        int result = 0;
        for (int d = 1; d <= max_day; ++d) {
            while (!events.empty() && events.back()[0] == d) {
                min_heap.emplace(events.back()[1]);
                events.pop_back();
            }
            while (!min_heap.empty() && min_heap.top() == d - 1) {
                min_heap.pop();
            }
            if (min_heap.empty()) {
                continue;
            }
            min_heap.pop();
            ++result;
        }
        return result;
    }
};
