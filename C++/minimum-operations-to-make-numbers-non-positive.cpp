// Time:  O(nlogr)
// Space: O(1)

// binary search, greedy
class Solution {
public:
    int minOperations(vector<int>& nums, int x, int y) {
        const auto& ceil_divide = [](int a, int b) {
            return (a + b - 1) / b;
        };

        const auto& check = [&](int total) {
            return accumulate(cbegin(nums), cend(nums), 0ll, [&](const auto& accu, const auto& v) {
                return accu + ceil_divide(max(v - min(ceil_divide(v, y), total) * y, 0), x - y);
            }) <= total;
        };

        int left = 1, right = ceil_divide(*max_element(cbegin(nums), cend(nums)), y);
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
