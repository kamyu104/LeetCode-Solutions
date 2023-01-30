// Time:  O(nlogn)
// Space: O(1)

// greedy, sort
class Solution {
public:
    double maxPrice(vector<vector<int>>& items, int capacity) {
        sort(begin(items), end(items), [](const auto& a, const auto& b) {
            return a[0] * b[1] > a[1] * b[0];
        });
        double result = 0;
        for (const auto& item : items) {
            const auto cnt = min(item[1], capacity);
            capacity -= cnt;
            result += (static_cast<double>(item[0]) / item[1]) * cnt;
        }
        return capacity == 0 ? result : -1;
    }
};
