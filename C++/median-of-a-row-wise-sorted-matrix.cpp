// Time:  O(logr * mlogn), r = O(right-left+1) = O(10^6), O(logr) = O(20)
// Space: O(1)

// binary search
class Solution {
public:
    int matrixMedian(vector<vector<int>>& grid) {
        const auto& check = [&](int x) {
            return accumulate(cbegin(grid), cend(grid), 0,
                              [&](const auto& total, const auto& curr) {
                                  return total + distance(cbegin(curr), upper_bound(cbegin(curr), cend(curr), x));
                              }) > size(grid) * size(grid[0]) / 2;
        };

        int left = min_element(cbegin(grid), cend(grid), [](const auto& a, const auto& b) { return a.front() < b.front(); })->front();
        int right = max_element(cbegin(grid), cend(grid), [](const auto& a, const auto& b) { return a.back() < b.back(); })->back();
        while (left <= right) {
            const int mid = left + (right - left) / 2;
            if (check(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
