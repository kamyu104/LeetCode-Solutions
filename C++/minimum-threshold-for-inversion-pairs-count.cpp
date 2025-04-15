// Time:  O(nlogn * logr)
// Space: O(n)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// binary search, ordered set
class Solution {
public:
    int minThreshold(vector<int>& nums, int k) {
        const auto& binary_search = [](auto left, auto right, const auto& check) {
            while (left <= right) {
                const auto mid = left + (right - left) / 2;
                if (check(mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return left;
        };

        const auto& check = [&](int x) {
            using ordered_set = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;
            ordered_set os;
            int cnt = 0;
            for (int i = size(nums) - 1; i >= 0; --i) {
                cnt += os.order_of_key({nums[i], i}) - os.order_of_key({nums[i] - x, i});
                os.insert({nums[i], i});
            }
            return cnt >= k;
        };
    
        int mx = nums[0], right = 0;
        for (int i = 1; i < size(nums); ++i) {
            right = max(right, mx - nums[i]);
            mx = max(mx, nums[i]);
        }
        const int result = binary_search(0, right, check);
        return result <= right ? result : -1;
    }
};
