// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> min_heap(sticks.cbegin(), sticks.cend());
        int result = 0;
        while (min_heap.size() > 1) {
            const auto x = min_heap.top(); min_heap.pop();
            const auto y = min_heap.top(); min_heap.pop();
            result += x + y;
            min_heap.emplace(x + y);
        }
        return result;
    }
};
