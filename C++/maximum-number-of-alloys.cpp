// Time:  O(k * n * logr), r = min(stock)+budget
// Space: O(1)

// binary search
class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        const auto& check = [&](int64_t x) {
            for (const auto& machine : composition) {
                int64_t curr = 0;
                for (int i = 0; i < n; ++i) {
                    curr += (max(x * machine[i] - stock[i], static_cast<int64_t>(0)) * cost[i]);
                    if (curr > budget) {
                        break;
                    }
                }
                if (curr <= budget) {
                    return true;
                }
            }
            return false;
        };

        int left = 1, right = *min_element(cbegin(stock), cend(stock)) + budget;
        while (left <= right) {
            const int mid = left + (right - left) / 2;
            if (!check(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
};
