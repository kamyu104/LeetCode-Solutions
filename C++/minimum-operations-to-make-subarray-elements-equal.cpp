// Time:  O(nlogk)
// Space: O(k)

// math, two pointers, sliding window, bst
class Solution {
public:
    long long minOperations(vector<int>& nums, int k) {
        set<pair<int, int>> left, right;
        int64_t total_left = 0, total_right = 0;
        const auto& rebalance = [&]() {
            if (size(left) + 1 < size(right)) {
                auto it = begin(right);
                const auto [x, i] = *it;
                right.erase(it);
                total_right -= x;
                left.emplace(-x, -i);
                total_left += x;
            } else if (size(left) > size(right)) {
                auto it = begin(left);
                const auto [x, i] = *it;
                left.erase(*it);
                total_left -= -x;
                right.emplace(-x, -i);
                total_right += -x;
            }
        };

        int64_t result = numeric_limits<int64_t>::max();
        for (int i = 0; i < size(nums); ++i) {
            if (!empty(left) && -cbegin(left)->first > nums[i]) {
                left.emplace(-nums[i], -i);
                total_left += nums[i];
            } else {
                right.emplace(nums[i], i);
                total_right += nums[i];
            }
            rebalance();
            const int j = i - (k - 1);
            if (j >= 0) {
                result = min(result, (total_right - (k % 2 ? cbegin(right)->first: 0)) - total_left);
                if (left.count(pair(-nums[j], -j))) {
                    left.erase(pair(-nums[j], -j));
                    total_left -= nums[j];
                } else {
                    right.erase(pair(nums[j], j));
                    total_right -= nums[j];
                }
                rebalance();
            }
        }
        return result;
    }
};
