// Time:  O(nlogn)
// Space: O(1)

// math, binary search
class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        const auto& check = [&](int x, int64_t t) {
            int64_t cnt = 0;
            for (int i = 0; i < size(nums); ++i) {
                if (nums[i] <= x) {
                    cnt += cost[i];
                }
            }
            return cnt >= t;
        };

        const int64_t total = accumulate(cbegin(cost), cend(cost), 0ll);
        int left = *min_element(cbegin(nums), cend(nums));
        int right = *max_element(cbegin(nums), cend(nums));
        const int64_t target = (total + 1) / 2;
        while (left <= right) {
            const int mid = left + (right - left) / 2;
            if (check(mid, target)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        int64_t result = 0;
        for (int i = 0; i < size(nums); ++i) {
            result += static_cast<int64_t>(abs(nums[i] - left)) * cost[i];
        }
        return result;
    }
};
