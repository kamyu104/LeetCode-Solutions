// Time:  O(nlogd)
// Space: O(d)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// sliding window, ordered set
class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        static const int32_t INF32 = numeric_limits<int32_t>::max();
        static const int64_t INF64 = numeric_limits<int64_t>::max();
        using ordered_set = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;
        ordered_set os;
        for (int i = 1; i < 1 + dist; ++i) {
            os.insert({nums[i], i});
        }
        int64_t curr = 0;
        auto it = cbegin(os);
        for (int i = 0; i < k - 2; ++i, ++it) {
            curr += it->first;
        }
        int64_t mn = INF64;
        for (int i = 1 + dist; i < size(nums); ++i) {
            curr += min(nums[i], k - 2 < size(os) ? os.find_by_order(k - 2)->first : INF32);
            mn = min(mn, curr);
            os.insert({nums[i], i});
            curr -= min(nums[i - dist], k - 2 < size(os) ? os.find_by_order(k - 2)->first : INF32);
            os.erase({nums[i - dist], i - dist});
        }
        return nums[0] + mn;
    }
};
