// Time:  O(nlogm), m is the max of quantities
// Space: O(1)

class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1, right = *max_element(cbegin(quantities), cend(quantities));
        while (left <= right) {
            const auto& mid = left + (right - left) / 2;
            if (check(n, quantities, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    bool check(int n, const vector<int>& quantities, int x) {
        return accumulate(cbegin(quantities), cend(quantities), 0,
                          [this, &x](const auto& total, const auto& q) {
                              return total + ceil_divide(q, x);
                          }) <= n;
    }

    int ceil_divide(int a, int b) {
        return (a + (b - 1)) / b;
    }
};
